// EuropeanOption.hpp
#ifndef EUROPEANOPTION_HPP
#define EUROPEANOPTION_HPP

#include "Option.hpp"

namespace QuantLib {

class EuropeanOption : public Option {
public:
    EuropeanOption(double strike, double maturity, OptionType type);
    ~EuropeanOption() override = default;
};

} // namespace QuantLib

#endif // EUROPEANOPTION_HPP
