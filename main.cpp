// main.cpp
#include <iostream>
#include "EuropeanOption.hpp"
#include "BlackScholesModel.hpp"
#include "MonteCarloPricer.hpp"
#include "BinomialTreeModel.hpp"

int main() {
    using namespace QuantLib;

    // Common parameters
    double spotPrice = 100.0;    // Current stock price
    double strikePrice = 100.0;  // Strike price
    double maturity = 1.0;       // Time to expiration in years
    double riskFreeRate = 0.05;  // Risk-free interest rate
    double volatility = 0.2;     // Volatility

    // Create a European Call Option
    EuropeanOption euroOption(strikePrice, maturity, Call);

    // Black-Scholes Model Pricing
    BlackScholesModel bsModel(riskFreeRate, volatility);
    double bsPrice = bsModel.optionPrice(euroOption, spotPrice);
    std::cout << "Black-Scholes Call Price: " << bsPrice << std::endl;

    // Monte Carlo Simulation Pricing
    int numSimulations = 1000000;
    MonteCarloPricer mcPricer(riskFreeRate, volatility, numSimulations);
    double mcPrice = mcPricer.optionPrice(euroOption, spotPrice);
    std::cout << "Monte Carlo Call Price: " << mcPrice << std::endl;

    // Binomial Tree Model Pricing
    int numSteps = 100;
    BinomialTreeModel btModel(riskFreeRate, volatility, numSteps);
    double btPrice = btModel.optionPrice(euroOption, spotPrice);
    std::cout << "Binomial Tree Call Price: " << btPrice << std::endl;

    return 0;
}
