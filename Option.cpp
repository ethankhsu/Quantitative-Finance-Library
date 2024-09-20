// Option.cpp
#include "Option.hpp"

namespace QuantLib {

Option::Option(double strike, double maturity, OptionType type)
    : strike_(strike), maturity_(maturity), type_(type) {}

double Option::getStrike() const { return strike_; }
double Option::getMaturity() const { return maturity_; }
OptionType Option::getType() const { return type_; }

} // namespace QuantLib
