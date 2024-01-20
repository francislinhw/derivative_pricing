// Exercise 5: Statistical Functions
// In this exercise we experiment with the exponential and Poisson distributions that have many applications to queueing theory,
// scheduling and jump (Levy) processes in finance. Some typical examples of use are:

/* double scaleParameter = 0.5;
 *
 * // Default type is 'double'
 * exponential_distribution<> myExponential(scaleParameter);
 * cout << "Mean:" << mean(myExponential)
 * << ",standard deviation: "
 * << standard_deviation(myExponential) << endl;
 * // and
 * double mean = 3.0; poisson_distribution<double> myPoisson(mean);
 */

// Modify the code in the file “TestNormalDistribution.cpp” 
// to work with exponential distribution instead of normal distribution and Poisson distribution instead of gamma distribution.
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

    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Exponential Distribution
     * Mean: 2
     * Standard Deviation: 2
     * Mean: 2
     * Variance: 4
     * median: 1.38629
     * mode: 0
     * kurtosis excess: 6
     * kurtosis: 9
     * characteristic function (at x = 5): 2.5
     * hazard: (at x = 5): 0.5
     * 
     * Poisson Distribution
     * Mean: 3
     * Standard Deviation: 1.73205
     * Variance: 3
     * median: 3
     * mode: 3
     * kurtosis excess: 0.333333
     * kurtosis: 3.33333
     * characteristic function (at x = 5): 2.47792
     * hazard: (at x = 5): 1.2014
     * PDF Values:
     * 0.0497871, 0.114718, 0.180925, 0.224042, 0.232304, 0.209356, 0.168031, 0.122186, 0.081528, 0.0504094, 0.029109, 0.0157985, 0.00810151, 0.00394286, 0.00182811, 0.000810151, 0.000344151, 0.00014049, 5.52376e-05, 2.09595e-05, 7.689e-06, 2.73153e-06, 9.41088e-07, 3.14868e-07, 1.02432e-07, 3.24375e-08, 1.00095e-08, 3.01272e-09, 8.85255e-10, 2.54161e-10, 
     * CDF Values:
     * 0.0497871, 0.138138, 0.268912, 0.42319, 0.576935, 0.710886, 0.815263, 0.889188, 0.937352, 0.966491, 0.982984, 0.991769, 0.996197, 0.998317, 0.999285, 0.999708, 0.999885, 0.999956, 0.999984, 0.999994, 0.999998, 0.999999, 1, 1, 1, 1, 1, 1, 1, 1, %    
     */
}
