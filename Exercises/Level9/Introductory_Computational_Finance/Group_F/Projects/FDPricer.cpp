// TestBSPDE1.cpp
//
// Testing 1 factor BS model.
//
// Francis's Homework Nine
//

#include "FdmDirector.hpp"

#include <iostream>
#include <string>
#include <map>
using namespace std;

#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"

namespace BS // Black Scholes
{
	double sig = 0.3;
	double K = 65.0;
	double T = 0.25;
	double r = 0.08;
	double D = 0.0; // aka q

	void setOptionParamenters(double T, double K, double r, double sig) {
		BS::sig = sig;
		BS::K = K;
		BS::T = T;
		BS::r = r;
	}

	double mySigma (double x, double t)
	{

		double sigmaS = sig*sig;

		return 0.5 * sigmaS * x * x;
	}

	double myMu (double x, double t)
	{
		
		return (r - D) * x;
	
	}

	double myB (double x, double t)
	{	
	
		return  -r;
	}

	double myF (double x, double t)
	{
		return 0.0;
	}

	double myBCL (double t)		
	{
		// Put
		return K *exp(-r * t);
	}

	double myBCR (double t)
	{
			
		// Put
		return 0.0; // P
	}

	double myIC (double x)
	{ // Payoff 
	
		// Put
		return max(K - x, 0.0);
	}

}

namespace BSCall // Black Scholes
{
	double sig = 0.3;
	double K = 65.0;
	double T = 0.25;
	double r = 0.08;
	double D = 0.0; // aka q

	void setOptionParamenters(double T, double K, double r, double sig) {
		BSCall::sig = sig;
		BSCall::K = K;
		BSCall::T = T;
		BSCall::r = r;
	}

	double mySigma(double x, double t)
	{

		double sigmaS = sig * sig;

		return 0.5 * sigmaS * x * x;
	}

	double myMu(double x, double t)
	{

		return (r - D) * x;

	}

	double myB(double x, double t)
	{

		return  -r;
	}

	double myF(double x, double t)
	{
		return 0.0;
	}

	double myBCL(double t)
	{
		// Call
		return 0.0;
	}

	double myBCR(double t)
	{

		// Call
		return K * exp(-r * t);
	}

	double myIC(double x)
	{ // Payoff 

		// Call
		return max(x - K, 0.0);
	}

}

void FDMPricer(double sig, double K, double T, double r, string excelName) {
	using namespace ParabolicIBVP;

	BS::setOptionParamenters(T, K, r, sig);

	// Assignment of functions
	sigma = BS::mySigma;
	mu = BS::myMu;
	b = BS::myB;
	f = BS::myF;
	BCL = BS::myBCL;
	BCR = BS::myBCR;
	IC = BS::myIC;

	int J = static_cast<int>(5 * BS::K); int N = (10000 - 1); // k = O(h^2) !!!!!!!!!

	double Smax = 5 * BS::K;			// Magix

	cout << "start FDM\n";
	FDMDirector fdir(Smax, BS::T, J, N);

	fdir.doit();

	cout << "Finished\n";

	// Have you Excel installed (ExcelImports.cpp)
	printOneExcel(fdir.xarr, fdir.current(), string(excelName + " Put"));
}

void FDMCallPricer(double sig, double K, double T, double r, string excelName//, double* J = nullptr, double*N = nullptr
) {
	// bool recoverJ = false;
	// bool recoverN = false;

	using namespace ParabolicIBVP;

	BSCall::setOptionParamenters(T, K, r, sig);

	// Assignment of functions
	sigma = BSCall::mySigma;
	mu = BSCall::myMu;
	b = BSCall::myB;
	f = BSCall::myF;
	BCL = BSCall::myBCL;
	BCR = BSCall::myBCR;
	IC = BSCall::myIC;

	//if (J == nullptr) {
		int J = static_cast<int>(5 * BSCall::K);
	//	bool recoverJ = true;
	//}
	//if (N == nullptr) {
		int N = (10000 - 1); // k = O(h^2) !!!!!!!!!
	//	bool recoverN = true;
	//}

	double Smax = 5 * BSCall::K;			// Magix

	cout << "start FDM\n";
	FDMDirector fdir(Smax, BSCall::T, J, N);

	fdir.doit();

	cout << "Finished\n";

	// Have you Excel installed (ExcelImports.cpp)
	printOneExcel(fdir.xarr, fdir.current(), string(excelName + " Call"));

	// if (recoverJ) {
	//	delete J;
	//}
	//if (recoverN) {
	//}
}

struct OptionParameters {
	double T;    // Time to maturity
	double K;    // Strike price
	double sig;  // Volatility
	double r;    // Risk-free interest rate
	double CostOfCarry = 0;    // Underlying asset price

	// Default constructor
	OptionParameters() : K(0), T(0), sig(0), r(0), CostOfCarry(0) {}

	OptionParameters(double K, double T, double sig, double r)
		: K(K), T(T), sig(sig), r(r) {}
};


int main()
{
	std::map<std::string, OptionParameters> optionBatches;

	optionBatches["Batch 1"] = OptionParameters(65, 0.25, 0.3, 0.08);
	optionBatches["Batch 2"] = OptionParameters(100, 1.0, 0.2, 0.0);
	optionBatches["Batch 3"] = OptionParameters(10, 1.0, 0.5, 0.12);
	optionBatches["Batch 4"] = OptionParameters(100, 30.0, 0.3, 0.08);

	FDMCallPricer(optionBatches["Batch 1"].sig,
		          optionBatches["Batch 1"].K,
		          optionBatches["Batch 1"].T,
		          optionBatches["Batch 1"].r,
		          "Batch One");

	FDMPricer(optionBatches["Batch 1"].sig,
			  optionBatches["Batch 1"].K,
		      optionBatches["Batch 1"].T,
		      optionBatches["Batch 1"].r,
			  "Batch One");

	FDMCallPricer(optionBatches["Batch 2"].sig,
		          optionBatches["Batch 2"].K,
		          optionBatches["Batch 2"].T,
		          optionBatches["Batch 2"].r,
		          "Batch Two");

	FDMPricer(optionBatches["Batch 2"].sig,
		      optionBatches["Batch 2"].K,
		      optionBatches["Batch 2"].T,
		      optionBatches["Batch 2"].r,
		      "Batch Two");

	FDMCallPricer(optionBatches["Batch 3"].sig,
		          optionBatches["Batch 3"].K,
		          optionBatches["Batch 3"].T,
		          optionBatches["Batch 3"].r,
		          "Batch Three");

	FDMPricer(optionBatches["Batch 3"].sig,
		      optionBatches["Batch 3"].K,
		      optionBatches["Batch 3"].T,
		      optionBatches["Batch 3"].r,
		      "Batch Three");

	FDMCallPricer(optionBatches["Batch 4"].sig,
		          optionBatches["Batch 4"].K,
		          optionBatches["Batch 4"].T,
		          optionBatches["Batch 4"].r,
		          "Batch Four");

	FDMPricer(optionBatches["Batch 4"].sig,
		      optionBatches["Batch 4"].K,
		      optionBatches["Batch 4"].T,
		      optionBatches["Batch 4"].r,
		      "Batch Four");

	return 0;
}
