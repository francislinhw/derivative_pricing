// Struct data holder

#ifndef Optiondata
#define Optiondata

struct optiondata
{
	double S0;
	double K;
	double T;
	double r;
	double sig;
	long interval;			// number of stock price simulations per path
	long paths;				// number of paths run by the thread
	long totalpaths;		// numbers of paths run
	double output;
	int counter;
	int type;
};

#endif