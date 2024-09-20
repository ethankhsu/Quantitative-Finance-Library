// MonteCarloPricer.cpp
#include "MonteCarloPricer.hpp"
#include <cmath>

namespace QuantLib {

MonteCarloPricer::MonteCarloPricer(double riskFreeRate, double volatility, int numSimulations)
    : riskFreeRate_(riskFreeRate), volatility_(volatility), numSimulations_(numSimulations) {}

double MonteCarloPricer::optionPrice(const EuropeanOption& option, double spotPrice) const {
    double K = option.getStrike();
    double T = option.getMaturity();
    double sigma = volatility_;
    double r = riskFreeRate_;
    OptionType type = option.getType();

    std::mt19937_64 rng;
    rng.seed(std::random_device{}());
    std::normal_distribution<double> normDist(0.0, 1.0);

    double payoffSum = 0.0;
    for (int i = 0; i < numSimulations_; ++i) {
        double Z = normDist(rng);
        double S_T = spotPrice * std::exp((r - 0.5 * sigma * sigma) * T +
                                          sigma * std::sqrt(T) * Z);
        double payoff = 0.0;
        if (type == Call) {
            payoff = std::max(S_T - K, 0.0);
        } else { // Put Option
            payoff = std::max(K - S_T, 0.0);
        }
        payoffSum += payoff;
    }

    double optionPrice = (payoffSum / static_cast<double>(numSimulations_)) * 
                         std::exp(-r * T);
    return optionPrice;
}

} // namespace QuantLib
