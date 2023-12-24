#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <iostream>

using namespace std;
using namespace boost::math;

int main() {
    // Test x
    double x = 5;
    // Exponential Distribution
    double lambda = 0.5;  // Scale parameter for exponential distribution
    exponential_distribution<> myExponential(lambda);

    cout << "\nExponential Distribution\n";
    cout << "Mean: " << mean(myExponential) << endl;
    cout << "Standard Deviation: " << standard_deviation(myExponential) << endl;
    cout << "Mean: " << mean(myExponential) << endl;
    cout << "Variance: " << variance(myExponential) << endl;
	cout << "median: " << median(myExponential) << endl;
	cout << "mode: " << mode(myExponential) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
	cout << "kurtosis: " << kurtosis(myExponential) << endl;
	cout << "characteristic function (at x = " << x << "): " << chf(myExponential, x) << endl;
	cout << "hazard: (at x = " << x << "): " << hazard(myExponential, x) << endl;

    // Poisson Distribution
    double meanPoisson = 3.0;  // Mean for Poisson distribution
    poisson_distribution<double> myPoisson(meanPoisson);

    cout << "\nPoisson Distribution\n";
    cout << "Mean: " << mean(myPoisson) << endl;
    cout << "Standard Deviation: " << standard_deviation(myPoisson) << endl;
    cout << "Variance: " << variance(myPoisson) << endl;
	cout << "median: " << median(myPoisson) << endl;
	cout << "mode: " << mode(myPoisson) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myPoisson) << endl;
	cout << "kurtosis: " << kurtosis(myPoisson) << endl;
	cout << "characteristic function (at x = " << x << "): " << chf(myPoisson, x) << endl;
	cout << "hazard: (at x = " << x << "): " << hazard(myPoisson, x) << endl;


    // Explore properties of the Poisson distribution
    vector<double> pdfList;
    vector<double> cdfList;

    double start = 0;
    double end = 20.0;
    long N = 30;
    double val = start;
    double h = (end - start) / static_cast<double>(N);

    for (long j = 1; j <= N; ++j) {
        pdfList.push_back(pdf(myPoisson, val));
        cdfList.push_back(cdf(myPoisson, val));
        val += h;
    }

    cout << "\nPDF Values:\n";
    for (size_t j = 0; j < pdfList.size(); ++j) {
        cout << pdfList[j] << ", ";
    }

    cout << "\n\nCDF Values:\n";
    for (size_t j = 0; j < cdfList.size(); ++j) {
        cout << cdfList[j] << ", ";
    }

    return 0;
}
