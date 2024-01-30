// Monte Carlo Pricer of a call option
// Using Geometric Brownian Motion

#include <boost/math/distributions.hpp>	// for use with normal distribution
#include <boost/random.hpp>		// To be use with random generator
#include <iostream>
#include <cmath>				// math library
#include <fstream>				// allows us to use file streams
#include <iomanip>				// stream manipulations
#include <Windows.h>			// use with multithreading
#include "Optiondata.hpp"
using namespace std;
using namespace boost::math;
/*
void printvector(vector<DataHolder>& vu)
{
	vector<DataHolder>::iterator it;

	for(it=vu.begin(); it!=vu.end(); it++)
	{
		//(*it).PrintPath();
		(*it).PrintInterval();
	}
}
*/
double BScall(optiondata& tu)
{
	// Initialize normal distribution as a standard normal
	// You need a standard normal because Geometric Brownian Motion is based on
	// a standard normal distribution
	normal_distribution<> stNormal(0.0, 1.0);
		
	double tmp=tu.sig*sqrt(tu.T);
	double d1=((log(tu.S0/tu.K)+(tu.r+(tu.sig*tu.sig)*0.5)*tu.T)/tmp);	//d1
	double d2=d1-tmp;								//d2

	if(tu.type==1)
	{
		//call price
		// cdf=cumulative standard normal distribution function
		return(tu.S0*cdf(stNormal,d1)-tu.K*exp(-tu.r*tu.T)*cdf(stNormal,d2));
	}
	else
	{
		//call price
		return(tu.K*exp(-tu.r*tu.T)*cdf(stNormal,-d2)-tu.S0*cdf(stNormal,-d1));
	}
}

double payoff(double X, double K, int type)
{
	if(type==1)
	{
		// for call option
		return(max((X-K),0.0));
	}
	else
	{
		// for put option
		return(max((K-X),0.0));
	}
}

double MCcall(optiondata& tu)
{
	// Define dt
	double dt=tu.T/tu.interval;
	
	// Define Values of Stock price, Sum, Average, Price, zero $ Stocks  
	double S(0),Sum(0);
	
	// Random Generator lagged fibonacci
	boost::mt19937 rng;
	// Seed for random generator (x(0))
	rng.seed(static_cast<unsigned int> (std::time(0)));
	// Initialize normal distribution as a standard normal
	boost::normal_distribution<> st(0.0, 1.0);
	
	// Calculate of different paths 
	for (long i = 1; i <= tu.paths; ++i)
	{
		// Give status after each 1000th iteration
		if ((i/10000) * 10000 == i)
		{
			cout << "Thread " << tu.counter << " has processed " << i << " iterations" << endl;
		}
				
		// Initialize values
		double SOld=tu.S0;
		S=0;
		// Run Simulation for 1 path
		for (long index=1; index <= tu.interval; ++index)
		{
			// Create a random number using a standard normal for distribution
			boost::variate_generator < boost::mt19937&, boost::normal_distribution<> > gen(rng,st);
			
			// Geometric Brownian Motion SDE
			//S = SOld + SOld*r*dt + SOld*sig*gen()*sqrt(dt);			// Basic SDE
			S = SOld*exp((tu.r-0.5*tu.sig*tu.sig)*dt+tu.sig*gen()*sqrt(dt));	// Solved SDE using Ito
			
			// Change to previous values
			SOld=S;
		}
			
		Sum+=payoff(S,tu.K,tu.type);
	}

	return(Sum);
}

// The function which would be called from the thread
// LPVOID (long pointer to void) for generic use
// DWORD (Double Word)
DWORD WINAPI ThreadFn(LPVOID x)
{
	// this is called casting
	// compiler thinks that x is has a void argument
	// in order to change this we use a pointer to alter the input argument 
	optiondata* data=(optiondata*)x;
		
	data->output=MCcall(*data);

	return(0);
}

int main()
{
	// Set the number of threads
	int threads=7;
	// Set number of Threads and Initiate object
	optiondata data[7];
	// Set number of paths
	long totalpaths=30000000;

	for(int i=0; i<threads; i++)
	{
		// Initialize values
		data[i].S0=65;
		data[i].K=65;
		data[i].T=1;
		data[i].r=0.08;
		data[i].sig=0.3;
		data[i].interval=1000;						// number of stock price simulations per path
		data[i].paths=(long)ceil(double(totalpaths/threads));
		data[i].output=0;
		data[i].counter=i;
		data[i].type=1;
	}
	
	cout << "The program will run " << totalpaths << " paths: " << endl;

	// Assigns an array of the maximoum number of threads you can run
	HANDLE handlearray[30];	
	
	// Runs the threads
	for(int i=0;i<threads;i++)
	{
		// Create thread
		handlearray[i]=CreateThread(NULL,0,ThreadFn,&data[i],0,NULL);
	}
		
	// This function defines that the system needs to wait
	// for all threads to finish before moving futher
	WaitForMultipleObjects(threads,handlearray,TRUE,INFINITE);

	double Sum(0),pricenew(0);
	for(int i=0; i<threads; i++)
	{
		Sum+=data[i].output;
	}

	pricenew=exp(-data[0].r*data[0].T)*(Sum/(totalpaths));
	
	cout << "The price of the option using Monte Carlo is: " << pricenew << endl;
	cout << "The price of the option using Black-Scholes is: " << BScall(data[1]) << endl;

	// close the handle to the thread
	CloseHandle(handlearray);

	return(0);
}