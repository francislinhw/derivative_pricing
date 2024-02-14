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
// C. Monte Carlo 101
// For this section, all necessary code is provided. You are expected to submit a document with the answers to the below three questions,
// but not any code.
// The document should contain a detailed,
// complete analysis and will be graded on how well it demonstrates understanding of the accuracy and efficiency of Monte Carlo methods in the below context.
// We focus on a linear, constant-coefficient, scalar (one-factor) problem. In particular,
// we examine the case of a one-factor European call option using the assumptions of the original Black Scholes equation. We give an overview of the process.
// At the expiry date t = T the option price is known as a function of the current stock price and the strike price.
// The essence of the Monte Carlo method is that we carry out a simulation experiment by finding the solution of a stochastic differential equation (SDE) from time t = 0 to time t = T .
// This process allows us to compute the stock price at t = T and then the option price using the payoff function.
// We carry out M simulations or draws by finding the solution of the SDE and we calculate the option price at t = T.
// Finally, we calculate the discounted average of the simulated payoff and we are done.
// Summarizing, the process is:
// 1. Construct a simulated path of the underlying stock.
// 2. Calculate the stock price at t = T .
// 3. Calculate the call price at t = T (use the payoff function).
// Execute steps 1–3 M times.
// 4. Calculate the averaged call price at t = T . 5. Discount the price found in step 4 to t = 0.
// The first step is to replace continuous time by discrete time. To this end, we divide the interval [0, T ] 
// (where T is the expiry date) into a number of subintervals as shown in Figure 1. We define N + 1 mesh points as follows:

#include "OptionData.hpp"
#include <MonteCarloOutput.hpp>
#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include <standardError.hpp>
#include <cmath>
#include <iostream>
// #include <optional> // Can be used in C++ 17

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

double standardDeviation(const std::vector<double>& prices, double r, double T) {
    long M = prices.size();
    double sum = 0.0;
    double squaredSum = 0.0;
    
    for (double price : prices) {
        sum += price;
        squaredSum += price * price;
    }
    
    double mean = sum / M;
    double variance = (squaredSum - (sum * sum) / M) / (M - 1);
    double stdDev = sqrt(variance) * exp(-r * T);
    
    return stdDev;
}

double standardError(double stdDev, long M) {
    return stdDev / sqrt(M);
}

MonteCarloOutput testMC(
	OptionData myOption, 
	double S_0,
	long* N = nullptr,
	long* NSim = nullptr,
	bool debug = false
	// std::optional<long> N = std::nullopt,
	// std::optional<long> NSim = std::nullopt
	) {

	std::vector<double> prices;

    bool shouldDeleteN = false;
    bool shouldDeleteNSim = false;

	if (N == nullptr) {
		N = new long(100);
		std::cout << "Number of subintervals in time: ";
		std::cin >> *N;
    	bool shouldDeleteN = true;
	}

	// Create the basic SDE (Context class)
	Range<double> range (0.0, myOption.T);
	double VOld = S_0;
	double VNew;
	double batchFourVNew;

	std::vector<double> x = range.mesh(*N);
	
	// V2 mediator stuff
	if (NSim == nullptr) {
		NSim = new long(50000);
		std::cout << "Number of simulations: ";
		std::cin >> *NSim;
    	bool shouldDeleteNSim = true;
	}

	double k = myOption.T / static_cast<double>(*N);
	double sqrk = sqrt(k);

	// Normal random number
	double dW;
	double price = 0.0;	// Option price
	
	// NormalGenerator is a base class
	// Incidentally, we generate increments of the Wiener process by a random number generator for independent Gaussian pseudo-random numbers,
	// for example Box-Muller, Polar Marsaglia, Mersenne Twister or lagged Fibonacci generator methods.
	// In this book, we focus exclusively on the generators in Boost Random.
	NormalGenerator* myNormal = new BoostNormal();

	using namespace SDEDefinition;
	SDEDefinition::data = &myOption;

	std::vector<double> res;
	int coun = 0; // Number of times S hits origin

	// A.
	for (long i = 1; i <= *NSim; ++i) { // Calculate a path at each iteration
		
		if (debug) {
			if ((i/10000) * 10000 == i) {// Give status after each 10000th iteration

					std::cout << i << std::endl;
			}
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
		prices.push_back(tmp);
		price += (tmp)/static_cast<double>(*NSim);
	}
	
	// D. Finally, discounting the average price
	price *= exp(-myOption.r * myOption.T);
	double sd = standardDeviation(prices, myOption.r, myOption.T);
	double se = standardError(sd, *NSim);
	float Number, Nsim;
	Number = static_cast<float>(*N);
	Nsim = static_cast<float>(*NSim);
	
	if (debug) {
		std::cout << "Number of times origin is hit: " << coun << ", " << endl;
		std::cout << "NT/NSIM: " << Number / Nsim << ", " << endl;
		std::cout << "Price, after discounting: " << price << std::endl;
	}

    // If we allocated memory for N, delete it
    if (shouldDeleteN) {
        delete N;
    }

    // If we allocated memory for NSim, delete it
    if (shouldDeleteNSim) {
        delete NSim;
    }

	// Cleanup; V2 use scoped pointer
	delete myNormal;

	MonteCarloOutput output;
	output.optionPrice = price;
	output.N_NSIM_Ratio = Number / Nsim;
	output.numberOfIntervals = Number;
	output.numberofSimulations = Nsim;
	output.standardDeviation = sd;
	output.standardError = se;

	return output;

}

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

	double Spot = 150;
	double Strike = 155;
	double r = 0.04;
	double T = 1.28;
	double sig = 0.27;
	double b = 0.04;

	OptionData batchOneCall;
	batchOneCall.K = Strike;
	batchOneCall.T = T;
	batchOneCall.r = r;
	batchOneCall.sig = sig;
	batchOneCall.type = +1;

	OptionData batchOnePut;
	batchOnePut.K = Strike;
	batchOnePut.T = T;
	batchOnePut.r = r;
	batchOnePut.sig = sig;
	batchOnePut.type = -1;

	double batchOneUnderlyingPrice = 60;

	OptionData batchTwoCall;
	batchTwoCall.K = 100.0;
	batchTwoCall.T = 1.0;
	batchTwoCall.r = 0.0;
	batchTwoCall.sig = 0.20;
	batchTwoCall.type = +1;

	OptionData batchTwoPut;
	batchTwoPut.K = 100.0;
	batchTwoPut.T = 1.0;
	batchTwoPut.r = 0.0;
	batchTwoPut.sig = 0.20;
	batchTwoPut.type = -1;

	double batchTwoUnderlyingPrice = 100;

	OptionData batchFourCall;
	batchFourCall.K = 100.0;
	batchFourCall.T = 30.0;
	batchFourCall.r = 0.08;
	batchFourCall.sig = 0.30;
	batchFourCall.type = +1;

	OptionData batchFourPut;
	batchFourPut.K = 100.0;
	batchFourPut.T = 30.0;
	batchFourPut.r = 0.08;
	batchFourPut.sig = 0.30;
	batchFourPut.type = -1;

	double batchFourUnderlyingPrice = 100;

	double testPrice, batchOneCallPrice, batchOnePutPrice,
		batchTwoCallPrice, batchTwoPutPrice, batchFourCallPrice, batchFourPutPrice;

	// D-a) Create generic functions to compute the standard deviation and standard error based on the above formulae.
	// The inputs are a vector of size M (M = NSIM), the interest-free rate and expiry time T.
	// Integrate this new code into TestMC.cpp. Make sure that the code compiles.
	MonteCarloOutput testOutput;
	testOutput = testMC(myOption, S_0, nullptr, nullptr, true);
	testPrice = testOutput.optionPrice;

	long start = 600;
	long end = 1200;
	long interval = 300;

	double batchOneTargetCallPrice = 2.13337;
	double batchOneTargetPutPrice = 5.84628;
	double batchTwoTargetCallPrice = 7.96557;
	double batchTwoPutTargetPrice = 7.96557;
	double diff = 0;
	double bestDiff = 10;
	long bestN;
	long bestNSim;

	// D-b) Run the MC program again with data from Batches 1 and 2.
	// Experiment with different values of NT (time steps) and NSIM (simulations or draws).
	// How do SD and SE react for these different run parameters,
	// and is there any pattern in regards to the accuracy of the MC (when compared to the exact method)?
	// It would take a bit longer to run the code as the time complexity is BigO(n^2)
	std::vector<MonteCarloOutput> simulationResults;

	for (long N = start; N <= end; N += interval) {
	    for (long NSim = start; NSim <= end; NSim += interval) {
			MonteCarloOutput batchOneCallResult;
			MonteCarloOutput batchOnePutResult;
			MonteCarloOutput batchTwoCallResult;
			MonteCarloOutput batchTwoPutResult;

			batchOneCallResult = testMC(batchOneCall, batchOneUnderlyingPrice, &N, &NSim);
			batchOneCallPrice = batchOneCallResult.optionPrice;

			batchOnePutResult = testMC(batchOnePut, batchOneUnderlyingPrice, &N, &NSim);
			batchOnePutPrice = batchOnePutResult.optionPrice;

			batchTwoCallResult = testMC(batchTwoCall, batchTwoUnderlyingPrice, &N, &NSim);
			batchTwoCallPrice = batchTwoCallResult.optionPrice;

			batchTwoPutResult = testMC(batchTwoPut, batchTwoUnderlyingPrice, &N, &NSim);
			batchTwoPutPrice = batchTwoPutResult.optionPrice;

			diff = abs(batchOneCallPrice - batchOneTargetCallPrice) 
			+ abs(batchOnePutPrice - batchOneTargetPutPrice) + abs(batchTwoCallPrice - batchTwoTargetCallPrice) 
			+ abs(batchTwoPutPrice - batchTwoPutTargetPrice);

			MonteCarloOutput singleResult;
			singleResult.numberOfIntervals = N;
			singleResult.numberofSimulations = NSim;
			singleResult.diff = diff;
			singleResult.standardDeviation = batchOneCallResult.standardDeviation + batchOnePutResult.standardDeviation
											 + batchTwoCallResult.standardDeviation + batchTwoPutResult.standardDeviation;
			singleResult.standardError = batchOneCallResult.standardError + batchOnePutResult.standardError
											 + batchTwoCallResult.standardError + batchTwoPutResult.standardError;
			simulationResults.push_back(singleResult);

			if (diff < bestDiff) {
				bestDiff = diff;
				bestN = N;
				bestNSim = NSim;
			}
		}
	}

	for (const MonteCarloOutput& result : simulationResults) {
	    std::cout << "N: " << result.numberOfIntervals << ", NSim: " << result.numberofSimulations << ", diff: " << result.diff  << ", StD: " << result.standardDeviation << ", SE: " << result.standardError <<  std::endl;
	}


	std::cout << "\nBest Number of Interval (NT): " << bestN << std::endl;
	std::cout << "Best Number of Simulation (NSIM): " << bestNSim << std::endl;
	std::cout << "Best NT/NSIM : " << bestN / bestNSim << std::endl;

	// C-c) Now we do some stress-testing of the MC method. Take Batch 4.
	//    What values do we need to assign to NT and NSIM in order to get an accuracy to two places behind the decimal point?
	//    How is the accuracy affected by different values for NT/NSIM?

	double batchFourTargetCallPrice = 92.17570;
	double batchFourTargetPutPrice = 1.24750;
	double diffCall;
	double diffPut;
	long timeSteps = long(5000);
	long numberSimu = long(10000);

	batchFourCallPrice = testMC(batchFourCall, batchFourUnderlyingPrice, &timeSteps, &numberSimu, true).optionPrice;
	batchFourPutPrice = testMC(batchFourPut, batchFourUnderlyingPrice, &timeSteps, &numberSimu, true).optionPrice;

	std::cout << "Diff of Call : " << batchFourCallPrice - batchFourTargetCallPrice << std::endl;
	std::cout << "Diff of Put : " << batchFourPutPrice - batchFourTargetPutPrice << std::endl;	

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
	 * 
	 * 	  The Monte Carlo method simulates many possible price paths for the underlying asset using random samples from a normal distribution.
	 *    This is consistent with the theory that option prices can be modeled as a stochastic process described by an SDE.
	 * 	  The drift and diffusion functions defined in the SDEDefinition namespace correspond to the theoretical drift and volatility terms in the Black-Scholes SDE.
	 * 	  The program calculates an estimate for the option price by averaging the payoff across all simulated paths and discounting it back to present value using the risk-free rate.
	 * 
     * 		* ============== *
     * 		* PROGRAM OUTPUT *
     * 		* ============== *
	 * 		
	 * 		1 factor MC with explicit Euler
	 * 		Number of subintervals in time: 10000
	 * 		Number of simulations: 10000
	 * 		10000
     *      Number of times origin is hit: 0,
	 * 		NT/NSIM: 1, 
     *      Price, after discounting: 5.88494
	 * 
	 * 		N: 600, NSim: 600, diff: 1.09018, StD: 33.1089, SE: 1.35166
	 * 		N: 600, NSim: 900, diff: 0.802462, StD: 34.1902, SE: 1.13967
	 * 		N: 600, NSim: 1200, diff: 0.66476, StD: 34.983, SE: 1.00987
	 * 		N: 900, NSim: 600, diff: 0.935109, StD: 33.9258, SE: 1.38502
	 * 		N: 900, NSim: 900, diff: 0.692468, StD: 34.5235, SE: 1.15078
	 * 		N: 900, NSim: 1200, diff: 0.492748, StD: 34.7232, SE: 1.00237
	 * 		N: 1200, NSim: 600, diff: 0.555532, StD: 33.2517, SE: 1.3575
	 * 		N: 1200, NSim: 900, diff: 0.69153, StD: 33.0283, SE: 1.10094
	 * 		N: 1200, NSim: 1200, diff: 1.16442, StD: 33.4269, SE: 0.964952
	 *
	 * 		Best Number of Interval (NT): 12000
	 * 		Best Number of Simulation (NSIM): 6000
	 * 		Best NT/NSIM : 2
	 * 		10000
	 * 		Number of times origin is hit: 0, 
	 * 		NT/NSIM: 0.5, 
	 * 		Price, after discounting: 91.3522
	 * 		10000
	 * 		Number of times origin is hit: 0, 
	 * 		NT/NSIM: 0.5, 
	 * 		Price, after discounting: 1.23325
	 * 		Diff of Call : -0.823482 // Might need to multiply the NSim by 4 to decrease diff
	 * 		Diff of Put : -0.0142477
	 * 
	 * b) Run the MC program again with data from Batches 1 and 2.
	 *    Experiment with different value of NT (time steps) and NSIM (simulations or draws).
	 *    In particular, how many time steps and draws do you need in order to get the same accuracy as the exact solution?
	 *    How is the accuracy affected by different values for NT/NSIM?
	 * 
	 * 	  I run the simulation multiple times with different values for NT (number of time steps) and NSIM (number of simulations) to find the values that give an option price close to the exact solution (obtained from the Black-Scholes formula or other exact methods).
	 * 	  The accuracy of the Monte Carlo simulation is generally improved by increasing NSIM.
	 *    Increasing NT can lead to more accurate simulations of the asset price path,
	 *    but may also increase computational cost.
	 * 
	 * 	  Looking back on my data, as NSim (the number of simulations) increases, the diff tends to decrease.
	 *    This is expected because increasing the number of simulations generally leads to a more accurate estimate of the expected payoff,
	 *    which reduces the standard error of the simulation.
	 *   
	 *    The law of large numbers suggests that the average of the results obtained from a large number of trials should be close to the expected value,
	 *    and will tend to become closer as more trials are performed.
	 * 	  But, the relationship between N and diff is not as clear-cut.
	 *    In some cases, increasing N decreases the diff, while in others, it increases the diff.
	 *    This can happen because while more time steps can lead to a more accurate simulation of the price path,
	 *    they can also introduce additional computational error. This is particularly true for methods like the Euler method,
	 *    which can have stability issues with finer discretizations.
	 * 	  
	 *    On the other hand, there is also no consistent pattern where increasing both N and NSim simultaneously will always result in a lower diff.
	 *    This could be due to the trade-off between having more precise paths (more time steps) and the randomness introduced in each simulation (more simulations).
	 * 	  It's important to note that the lowest diff values do not always occur for the highest values of N and NSim.
	 *    For example, a diff of 0.0586749 with N: 12000 and NSim: 6000 is lower than a diff of 0.19354 with N: 12000 and NSim: 12000.
	 *    This suggests that there's an optimal combination of N and NSim that provides the best accuracy for the given computational budget.
	 * 	  
	 *    To conclude, the accuracy of the Monte Carlo simulation improves with more simulations,
	 *    but the number of time steps also plays a role and must be balanced against computational cost and stability considerations.
	 *    The optimal parameters for N and NSim will depend on the specific characteristics of the option being priced,
	 *    and identifying these parameters may require experimentation and computational resources.
	 * 
	 * c) Now we do some stress-testing of the MC method. Take Batch 4.
	 *    What values do we need to assign to NT and NSIM in order to get an accuracy to two places behind the decimal point?
	 *    How is the accuracy affected by different values for NT/NSIM?
	 * 
	 *    I would like to significantly increase NSIM to reduce the standard error of the simulation to achieve two decimal places of accuracy.
	 *    The required NT will depend on the characteristics of the option; longer-dated options or options with more volatile underlying assets might require more time steps to accurately simulate the path.
	 *    As a rule of thumb, the accuracy of a Monte Carlo simulation is proportional to the inverse square root of NSIM (i.e., to halve the error, I would need to quadruple the number of simulations).
	 *    To determine the exact values for NT and NSIM, I would need to run simulations and compare the results with known accurate prices, adjusting NT and NSIM as necessary.
	 *    This process is iterative and requires computational resources.
	 *
	 * ============
	 *   Group D
	 * ============
	 * 
	 * a) Create generic functions to compute the standard deviation and standard error based on the above formulae.
	 *    The inputs are a vector of size M (M = NSIM), the interest-free rate and expiry time T.
	 *    Integrate this new code into TestMC.cpp. Make sure that the code compiles.
	 * 
	 *    The standard deviation function should take a vector of simulated option prices and calculate their standard deviation.
	 *    I can use the formula SD = sqrt(sum((xi - mean)^2) / (M - 1)),
	 *    where xi are the simulated prices, mean is the average of these prices, and M is the number of simulations.
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
	 *    Look for patterns in the SD and SE as I vary NT and NSIM.
	 *    Overall, I see the SE decrease as NSIM increases,
	 *    indicating more precision in the simulation.
	 *    The effect of changing NT is less straightforward and might depend on the specifics of the option being priced.
	 * 		
	 * 	  ==================
	 * 		Reiterate Data
	 *    ==================
	 * 
	 * 	    N: 600, NSim: 600, diff: 1.09018, StD: 33.1089, SE: 1.35166
	 * 		N: 600, NSim: 900, diff: 0.802462, StD: 34.1902, SE: 1.13967
	 * 		N: 600, NSim: 1200, diff: 0.66476, StD: 34.983, SE: 1.00987
	 * 		N: 900, NSim: 600, diff: 0.935109, StD: 33.9258, SE: 1.38502
	 * 		N: 900, NSim: 900, diff: 0.692468, StD: 34.5235, SE: 1.15078
	 * 		N: 900, NSim: 1200, diff: 0.492748, StD: 34.7232, SE: 1.00237
	 * 		N: 1200, NSim: 600, diff: 0.555532, StD: 33.2517, SE: 1.3575
	 * 		N: 1200, NSim: 900, diff: 0.69153, StD: 33.0283, SE: 1.10094
	 * 		N: 1200, NSim: 1200, diff: 1.16442, StD: 33.4269, SE: 0.964952
	 * 
	 *    From the data provided, we can observe how standard deviation (StD) and standard error (SE) are affected by different values of NT (number of time steps) and NSim (number of simulations), and how these metrics relate to the accuracy of the Monte Carlo (MC) method compared to the exact method (as indicated by the diff value):
     *   
	 *    Standard Deviation (StD): The standard deviation seems to fluctuate slightly with different NT and NSim values,
	 *    but there is no clear trend indicating that it consistently decreases or increases based on these parameters.
	 *    The StD is primarily a measure of the dispersion of the simulated option prices around their mean and is affected by the volatility of the underlying asset and the model parameters.
	 * 
	 *    Standard Error (SE): As expected, the standard error decreases as NSim increases.
	 *    This is evident when comparing the SE for NSim of 600, 900, and 1200 for the same NT.
	 *    The SE is inversely proportional to the square root of NSim, consistent with the formula SE = StD / sqrt(NSim).
	 *    A larger number of simulations leads to a more accurate estimate of the expected payoff, thereby reducing the standard error.
	 *    
	 *    Accuracy (diff): The diff value, representing the difference between the MC simulation prices and the exact method prices,
	 *    tends to decrease as NSim increases.
	 *    This pattern is consistent with the idea that more simulations provide a more accurate estimate.
	 *    However, there are instances where increasing NT (while keeping NSim constant) does not necessarily result in a lower diff.
	 *    For example, with NSim fixed at 1200, increasing NT from 600 to 1200 results in a higher diff,
	 *    which suggests that there might be an optimal combination of NT and NSim that minimizes diff.
	 *    
	 *    Pattern between SE and diff: 
	 *    Generally, a lower SE suggests a higher accuracy of the MC method. However,
	 *    the relationship between SE and diff is not straightforward, as a lower SE does not always correspond to a lower diff.
	 *    This discrepancy may arise because the diff also depends on the bias of the estimate, not just its variance.
	 *    The SE only captures the variability of the estimate, not whether the MC estimate is systematically higher or lower than the exact price.
	 *    
	 *    To summarize, while increasing the number of simulations (NSim) leads to a decrease in standard error and often a decrease in the difference from the exact method,
	 *    the number of time steps (NT) has a less predictable effect on accuracy.
	 *    This suggests that while increasing NSim is generally beneficial for precision, the choice of NT should be made more carefully,
	 *    considering both the computational cost and the specific characteristics of the option being priced.
	 *    Finding the optimal NT and NSim for a given problem typically requires experimentation and analysis of the trade-offs between accuracy,
	 *    computational expense, and potential numerical stability issues.
	 */
}