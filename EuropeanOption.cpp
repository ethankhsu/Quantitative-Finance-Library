// EuropeanOption.cpp
#include "EuropeanOption.hpp"

namespace QuantLib {

EuropeanOption::EuropeanOption(double strike, double maturity, OptionType type)
    : Option(strike, maturity, type) {}

} // namespace QuantLib
