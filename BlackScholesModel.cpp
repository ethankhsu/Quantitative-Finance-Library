// BlackScholesModel.cpp
#include "BlackScholesModel.hpp"
#include <cmath>
#include <algorithm>

namespace QuantLib {

BlackScholesModel::BlackScholesModel(double riskFreeRate, double volatility)
    : riskFreeRate_(riskFreeRate), volatility_(volatility) {}

// Implementation of cumulative normal distribution function
// Using the Abramowitz and Stegun approximation
// https://en.wikipedia.org/wiki/Normal_distribution#Cumulative_distribution_function

// Helper function for standard normal cumulative distribution function
// This is a numerical approximation of the cumulative normal distribution

// Function to compute option price using the Black-Scholes formula
double BlackScholesModel::optionPrice(const EuropeanOption& option, double spotPrice) const {
    double d1 = (std::log(spotPrice / option.getStrikePrice()) + (riskFreeRate_ + 0.5 * volatility_ * volatility_) * option.getMaturity()) / (volatility_ * std::sqrt(option.getMaturity()));
    double d2 = d1 - volatility_ * std::sqrt(option.getMaturity());

    if (option.getOptionType() == Call) {
        return spotPrice * normalCDF(d1) - option.getStrikePrice() * std::exp(-riskFreeRate_ * option.getMaturity()) * normalCDF(d2);
    } else {
        return option.getStrikePrice() * std::exp(-riskFreeRate_ * option.getMaturity()) * normalCDF(-d2) - spotPrice * normalCDF(-d1);
    }
}

// Implementation of normalCDF, approximating the cumulative normal distribution
double BlackScholesModel::normalCDF(double x) const {
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

} // namespace QuantLib
