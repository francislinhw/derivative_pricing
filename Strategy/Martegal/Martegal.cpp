#include <iostream>
#include <cmath> // For pow function

int main() {
    double probabilityWin = 0.5; // Probability of winning
    int baseBet = 1;             // Base bet
    int n = 3;                   // Maximum number of losses
    double expectation = 0.0;

    // Calculate expectation for winning in the first n rounds
    for (int i = 1; i <= n; ++i) {
        double probWinThisRound = std::pow(1 - probabilityWin, i - 1) * probabilityWin;
        double gain = baseBet;
        expectation += probWinThisRound * gain;
    }

    // Calculate the expected loss when losing all n rounds
    double probLosingAll = std::pow(1 - probabilityWin, n);
    double lossInAllRounds = 0;
    for (int i = 1; i <= n; ++i) {
        lossInAllRounds += std::pow(2, i - 1) * baseBet;
    }
    expectation -= probLosingAll * lossInAllRounds;

    std::cout << "Expected value of martingale strategy with " << n 
              << " rounds limit: " << expectation << std::endl;

    return 0;
}
