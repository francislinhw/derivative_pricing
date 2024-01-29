// HardCoded.cpp
//
// C++ code to price an option, essential algorithms.
//
// We take CEV model with a choice of the elaticity parameter
// and the Euler method. We give option price and number of times
// S hits the origin.
//
// (C) Datasim Education BC 2008-2011
//

#include "OptionData.hpp" 
#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include <standardError.hpp>
#include <cmath>
#include <iostream>

template <class T> 
void print(const std::vector<T>& myList)
{  // A generic print function for vectors
	
	std::cout << std::endl << "Size of vector is " << myList.size() << "\n[";

	// We must use a const iterator here, otherwise we get a compiler error.
	typename std::vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i)
	{
			std::cout << *i << ",";

	}

	std::cout << "]\n";
}

namespace SDEDefinition
{ // Defines drift + diffusion + data

	OptionData* data;				// The data for the option MC

	double drift(double t, double X)
	{ // Drift term
	
		return (data->r)*X; // r - D
	}

	
	double diffusion(double t, double X)
	{ // Diffusion term
	
		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);
		
	}

	double diffusionDerivative(double t, double X)
	{ // Diffusion term, needed for the Milstein method
	
		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV) * pow(X, 2.0 * betaCEV - 1.0);
	}
} // End of namespace


int main()
{
	std::cout <<  "1 factor MC with explicit Euler\n";
	OptionData myOption;
	myOption.K = 65.0;
	myOption.T = 0.25;
	myOption.r = 0.08;
	myOption.sig = 0.3;
	myOption.type = -1;	// Put -1, Call +1
	double S_0 = 60;

	OptionData batchFourCall;
	myOption.K = 100.0;
	myOption.T = 30.0;
	myOption.r = 0.08;
	myOption.sig = 0.30;
	myOption.type = +1;	// Put -1, Call +1

	OptionData batchFourPut;
	myOption.K = 100.0;
	myOption.T = 30.0;
	myOption.r = 0.08;
	myOption.sig = 0.30;
	myOption.type = -1;	// Put -1, Call +1

	double batchFourS0 = 100;

	long N = 100;
	std::cout << "Number of subintervals in time: ";
	std::cin >> N;

	// Create the basic SDE (Context class)
	Range<double> range (0.0, myOption.T);
	Range<double> batchFourRange (0.0, batchFourCall.T);
	double VOld = S_0;
	double VNew;
	double batchFourVOld = batchFourS0;
	double batchFourVNew;

	std::vector<double> x = range.mesh(N);
	std::vector<double> x = batchFourRange.mesh(N);
	
	// V2 mediator stuff
	long NSim = 50000;
	std::cout << "Number of simulations: ";
	std::cin >> NSim;

	double k = myOption.T / double (N);
	double sqrk = sqrt(k);

	double batchFourK = batchFourCall.T / double (N);
	double batchFourSqrk = sqrt(batchFourK);

	// Normal random number
	double dW;
	double price = 0.0;	// Option price
	double batchFourCallPrice = 0.0;	// Option price
	double batchFourPutPrice = 0.0;	    // Option price
	
	// NormalGenerator is a base class
	NormalGenerator* myNormal = new BoostNormal();

	using namespace SDEDefinition;
	SDEDefinition::data = &myOption;

	std::vector<double> res;
	int coun = 0; // Number of times S hits origin

	// A.
	for (long i = 1; i <= NSim; ++i) { // Calculate a path at each iteration
			
		if ((i/10000) * 10000 == i) {// Give status after each 10000th iteration

				std::cout << i << std::endl;
		}

		VOld = S_0;
		for (unsigned long index = 1; index < x.size(); ++index) {

			// Create a random number
			dW = myNormal->getNormal();
				
			// The FDM (in this case explicit Euler)
			VNew = VOld  + (k * drift(x[index-1], VOld))
						+ (sqrk * diffusion(x[index-1], VOld) * dW);

			VOld = VNew;

			// Spurious values
			if (VNew <= 0.0) coun++;
		}
			
		double tmp = myOption.myPayOffFunction(VNew);
		price += (tmp)/double(NSim);
	}
	
	// D. Finally, discounting the average price
	price *= exp(-myOption.r * myOption.T);

	// Cleanup; V2 use scoped pointer
	delete myNormal;

	std::cout << "Price, after discounting: " << price << ", " << std::endl;
	std::cout << "Number of times origin is hit: " << coun << endl;

	return 0;
	/* 
	 * ============
	 *   Group C
	 * ============
	 * 
	 * a) Study the source code in the file TestMC.cpp and relate it to the theory that we have just discussed.
	 *    The project should contain the following source files and you need to set project settings in VS
	 *    to point to the correct header files:
	 * 
	 *    Compile and run the program as is and make sure there are no errors.
	 * 	  The Monte Carlo method simulates many possible price paths for the underlying asset using random samples from a normal distribution. This is consistent with the theory that option prices can be modeled as a stochastic process described by an SDE.
	 * 	  The drift and diffusion functions defined in the SDEDefinition namespace correspond to the theoretical drift and volatility terms in the Black-Scholes SDE.
	 * 	  The program calculates an estimate for the option price by averaging the payoff across all simulated paths and discounting it back to present value using the risk-free rate.
	 * 
	 * 
	 * b) Run the MC program again with data from Batches 1 and 2.
	 *    Experiment with different value of NT (time steps) and NSIM (simulations or draws).
	 *    In particular, how many time steps and draws do you need in order to get the same accuracy as the exact solution?
	 *    How is the accuracy affected by different values for NT/NSIM?
	 * 
	 * 	  You will need to run the simulation multiple times with different values for NT (number of time steps) and NSIM (number of simulations) to find the values that give an option price close to the exact solution (obtained from the Black-Scholes formula or other exact methods).
	 * 	  The accuracy of the Monte Carlo simulation is generally improved by increasing NSIM.
	 *    Increasing NT can lead to more accurate simulations of the asset price path,
	 *    but may also increase computational cost.
	 * 
	 * 
	 * c) Now we do some stress-testing of the MC method. Take Batch 4.
	 *    What values do we need to assign to NT and NSIM in order to get an accuracy to two places behind the decimal point?
	 *    How is the accuracy affected by different values for NT/NSIM?
	 * 
	 *    You would likely need to significantly increase NSIM to reduce the standard error of the simulation to achieve two decimal places of accuracy.
	 *    The required NT will depend on the characteristics of the option; longer-dated options or options with more volatile underlying assets might require more time steps to accurately simulate the path.
	 *    As a rule of thumb, the accuracy of a Monte Carlo simulation is proportional to the inverse square root of NSIM (i.e., to halve the error, you would need to quadruple the number of simulations).
	 *    To determine the exact values for NT and NSIM, you would need to run simulations and compare the results with known accurate prices, adjusting NT and NSIM as necessary. This process is iterative and requires computational resources.
	 *
	 * ============
	 *   Group D
	 * ============
	 * 
	 * a) Create generic functions to compute the standard deviation and standard error based on the above formulae.
	 *    The inputs are a vector of size M (M = NSIM), the interest-free rate and expiry time T.
	 *    Integrate this new code into TestMC.cpp. Make sure that the code compiles.
	 * 
	 *    The standard deviation function should take a vector of simulated option prices and calculate their standard deviation. You can use the formula SD = sqrt(sum((xi - mean)^2) / (M - 1)), where xi are the simulated prices, mean is the average of these prices, and M is the number of simulations.
	 *    The standard error function should take the standard deviation and calculate the SE using the formula SE = SD / sqrt(M).
	 *    Both functions can be templated to work with any numeric vector type.
	 * 
	 * b) Run the MC program again with data from Batches 1 and 2.
	 *    Experiment with different values of NT (time steps) and NSIM (simulations or draws).
	 *    How do SD and SE react for these different run parameters,
	 *    and is there any pattern in regards to the accuracy of the MC (when compared to the exact method)?
	 *    
	 *    Experiment with different values of NT and NSIM. After each run,
	 *    calculate and output the SD and SE of the simulated option prices.
	 *    Compare the Monte Carlo prices with the exact method prices
	 *    (e.g., Black-Scholes formula) and observe how SD and SE change with different NT and NSIM.
	 *    Look for patterns in the SD and SE as you vary NT and NSIM.
	 *    Typically, you should see the SE decrease as NSIM increases,
	 *    indicating more precision in the simulation.
	 *    The effect of changing NT is less straightforward and might depend on the specifics of the option being priced.
	 */
}