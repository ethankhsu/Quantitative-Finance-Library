// BinomialTreeModel.cpp
#include "BinomialTreeModel.hpp"
#include <cmath>
#include <vector>

namespace QuantLib {

BinomialTreeModel::BinomialTreeModel(double riskFreeRate, double volatility, int numSteps)
    : riskFreeRate_(riskFreeRate), volatility_(volatility), numSteps_(numSteps) {}

double BinomialTreeModel::optionPrice(const Option& option, double spotPrice) const {
    double K = option.getStrike();
    double T = option.getMaturity();
    double sigma = volatility_;
    double r = riskFreeRate_;
    OptionType type = option.getType();
    int N = numSteps_;

    double deltaT = T / N;
    double u = std::exp(sigma * std::sqrt(deltaT));
    double d = 1.0 / u;
    double p = (std::exp(r * deltaT) - d) / (u - d);

    // Initialize asset prices at maturity
    std::vector<double> assetPrices(N + 1);
    for (int i = 0; i <= N; ++i) {
        assetPrices[i] = spotPrice * std::pow(u, N - i) * std::pow(d, i);
    }

    // Initialize option values at maturity
    std::vector<double> optionValues(N + 1);
    for (int i = 0; i <= N; ++i) {
        if (type == Call) {
            optionValues[i] = std::max(assetPrices[i] - K, 0.0);
        } else { // Put Option
            optionValues[i] = std::max(K - assetPrices[i], 0.0);
        }
    }

    // Backward induction
    for (int step = N - 1; step >= 0; --step) {
        for (int i = 0; i <= step; ++i) {
            optionValues[i] = std::exp(-r * deltaT) * 
                              (p * optionValues[i] + (1.0 - p) * optionValues[i + 1]);
        }
    }

    return optionValues[0];
}

} // namespace QuantLib
