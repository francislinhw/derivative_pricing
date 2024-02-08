#include "ExcelDriverlite.hpp"
#include "Utilities.hpp"

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/math/distributions/normal.hpp>
#include <iostream>

#include <cmath>
#include <algorithm> // For max function
#include <string>
#include <vector>
#include <list>
#include <map>
#include <format>


enum OptionType { EUROPEAN_CALL, EUROPEAN_PUT };

struct OptionParameters {
	double K; // Strike price
	double T; // Time to maturity (in years)
	double sigma; // Volatility
	double r; // Risk-free interest rate
	double q; // Dividend yield
	OptionType type; // Call or Put

	OptionParameters(double K, double T, double sigma, double r, double q, OptionType type)
		: K(K), T(T), sigma(sigma), r(r), q(q), type(type) {}
};

double blackScholesCallPrice(double S, const OptionParameters& op) {
	boost::math::normal_distribution<> nd;
	double d1 = (log(S / op.K) + (op.r - op.q + 0.5 * op.sigma * op.sigma) * op.T) / (op.sigma * sqrt(op.T));
	double d2 = d1 - op.sigma * sqrt(op.T);

	double callPrice = S * exp(-op.q * op.T) * cdf(nd, d1) - op.K * exp(-op.r * op.T) * cdf(nd, d2);
	return callPrice;
}


double rho = 0.5;
double NormalPdf1d(double x)
{ // Univariate normal density function

	double fac = 1.0 / std::sqrt(2.0 * 3.14159265359);
	return fac * std::exp(-x * x / 2);
}

template <typename Vector>
Vector DiscreteNormalPdf1d(const std::vector<double>& x)
{
	return CreateDiscreteFunction< std::vector<double>>(x, NormalPdf1d);
}

int main()
{
	OptionParameters params(65, 0.25, 0.3, 0.08, 0, EUROPEAN_CALL);
	std::vector<double> callPrices;
	std::vector<int> underlyings;

	for (int S = 21; S <= 70; S++) {
		double price = blackScholesCallPrice(S, params);
		callPrices.push_back(price);
		underlyings.push_back(S);
		std::cout << "Call price for S=" << S << ": " << price << std::endl;
	}
	// C++11 syntax
	//using NumericMatrix = boost::numeric::ublas::matrix<double>;
	// using Vector = std::vector<double>
	typedef boost::numeric::ublas::matrix<double> NumericMatrix;
	typedef std::vector<double> Vector;
	//	auto xarr = CreateMesh(N + 1, 0.0, 10.0);

	std::string sheetName("Vector Case");

	ExcelDriver& excel = ExcelDriver::Instance();
	excel.MakeVisible(true);		// Default is VISIBLE!

	// Labels for columns of the Excel vector.
	// Only labelled values are printed!!

	std::string rowLabel("Call Price");
	int numberOfLabels = 49; // Define how many labels we want
	std::list<std::string> colLabels; // C++11: {"C1", "C2", "C3", "C4","C5"};
	for (int i = 0; i <= numberOfLabels; i++) {
		std::string S = std::to_string(underlyings[i]);
		std::string name = "S = " + S; // std::to_string(i);
		colLabels.push_back(name);
	}

	try
	{
		long row = 4; long col = 3;
		excel.AddVector<NumericMatrix>(callPrices, sheetName, rowLabel, colLabels, row, col);
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << '\n';
	}
	catch (...)
	{
		// Catches everything else
		std::cout << "oop";
	}


	{
		// Using mapping continuous space to discrete space
		std::size_t N = 10;
		auto x = CreateMesh(N, -4.0, 4.0);

		std::vector<double> vec = DiscreteNormalPdf1d<std::vector<double>>(x);

		try
		{

			ExcelDriver& excel = ExcelDriver::Instance();
			std::string sheetName("Bivariate Normal pdf");
			long row = 3; long col = 2;
			//excel.AddVector<NumericMatrix>(vec, sheetName, row, col);
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what() << '\n';
		}
		catch (...)
		{
			// Catches everything else
			std::cout << "oop";
		}
	}


	return 0;
}
