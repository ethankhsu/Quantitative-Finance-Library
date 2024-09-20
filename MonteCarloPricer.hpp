// MonteCarloPricer.hpp
#ifndef MONTECARLOPRICER_HPP
#define MONTECARLOPRICER_HPP

#include "EuropeanOption.hpp"
#include <random>

namespace QuantLib {

class MonteCarloPricer {
public:
    MonteCarloPricer(double riskFreeRate, double volatility, int numSimulations);
    double optionPrice(const EuropeanOption& option, double spotPrice) const;

private:
    double riskFreeRate_;
    double volatility_;
    int numSimulations_;
};

} // namespace QuantLib

#endif // MONTECARLOPRICER_HPP
