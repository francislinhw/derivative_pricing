// Monte Carlo Pricer of a call option

#include <boost/math/distributions.hpp>	// for use with normal distribution
#include <boost/random.hpp>		// To be use with random generator
#include <iostream>
#include <cmath>
#include "DataHolder.h"
using namespace std;
using namespace boost::math;

void init(DataHolder& tu)
{
	double Sout=0;
	double Sumout=0;
	double Avegout=0;
	
	// Interval 
	double St=0;		// down and out barrier
	double gent=0;		// dividend
	double dtt=0;	// scale factor in CEV model
}

void printvector(vector<DataHolder>& vu)
{
	vector<DataHolder>::iterator it;

	for(it=vu.begin(); it!=vu.end(); it++)
	{
		(*it).PrintPath();
	}
}

double BScall(double S, double K, double T, double r, double sig)
{
	// Initialize normal distribution as a standard normal
	// You need a standard normal because Geometric Brownian Motion is based on
	// a standard normal distribution
	normal_distribution<double> stNormal(0.0, 1.0);
		
	double tmp=sig*sqrt(T);
	double d1=((log(S/K)+(r+(sig*sig)*0.5)*T)/tmp);	//d1
	double d2=d1-tmp;								//d2
	// cdf=cumulative standard normal distribution function
	double C=S*cdf(stNormal,d1)-K*exp(-r*T)*cdf(stNormal,d2);	//call price
		
	return(C);
}

double payoff(double X, double K)
{
	// for call option
	return(max((X-K),0.0));
}

double MCcall(double S0, double K, double T, double r, double sig, long paths, long interval)
{
	// Define dt
	double dt=T/interval;
	
	// Define Values of Stock price, Sum, Average, Price, zero $ Stocks  
	double S(0),Sum(0),Aveg(0),price(0),coun(0);
	DataHolder tu;
	init(tu);
	vector<DataHolder> vec;
		
	// Random Generator lagged fibonacci
	boost::lagged_fibonacci607 rng;
	// Seed for random generator (x(0))
	rng.seed(static_cast<unsigned int> (time(0)));
	// Initialize normal distribution as a standard normal
	boost::normal_distribution<> st(0.0, 1.0);
	
	// Calculate of different paths 
	for (long i = 1; i <= paths; ++i)
	{ 
		// Give status after each 1000th iteration
		if ((i/10000) * 10000 == i)
		{
			cout << i << endl;
		}
						
		// Run Simulation for 1 path
		for (long index=1; index <= interval; ++index)
		{
			// Create a random number using a standard normal for distribution
			boost::variate_generator<boost::lagged_fibonacci607&, boost::normal_distribution<>> gen(rng,st);
			//(when multiplied gy a sqrt(T) this is called the Weiner process)
			// this is the random parameter dW
			
			
			// Geometric Brownian Motion SDE
			S = S0 + S0*(r*dt + sig*gen()*sqrt(dt));

			// Change to previous values
			S0=S;

			// check if there are any spurious values (values <0)
			if (S <= 0.0)
			{
				coun++;
			}
		
		}
		
		tu.Sout=S;	// to be used with the vector
		Sum+=payoff(S,K);
		tu.Sumout=Sum;	// to be used with the vector
		Aveg=Sum/paths;
		tu.Avegout=Aveg;	// to be used with the vector
		vec.push_back(tu);
	}

	//printvector(vec);
	
	price=exp(-r*T)*Aveg;
	
	return(price);
}


int main()
{
	double S0=100;
	double K=100;
	double T=1;
	double r=0.05;
	double sig=0.2;
	long interval=1;		// number of stock price simulations per path
	long paths=3;			// numbers of paths run

	
	cout << BScall(S0,K,T,r,sig) << endl;

	cout << MCcall(S0,K,T,r,sig,paths,interval) << endl;

	return(0);
}