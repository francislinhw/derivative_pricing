#ifndef MONTE_CARLO_OUTPUT_HPP
#define MONTE_CARLO_OUTPUT_HPP

using namespace std;

// Encapsulate all MC output data in one place
struct MonteCarloOutput
{ 
	double optionPrice;
	double standardDeviation;
	double standardError;
	double numberOfIntervals;
	double numberofSimulations;
	double N_NSIM_Ratio;

	// Extra
	double diff = 0;
};


#endif