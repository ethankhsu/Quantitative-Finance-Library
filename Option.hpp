// Option.hpp
#ifndef OPTION_HPP
#define OPTION_HPP

namespace QuantLib {

enum OptionType { Call, Put };

class Option {
public:
    Option(double strike, double maturity, OptionType type);
    virtual ~Option() = default;

    double getStrike() const;
    double getMaturity() const;
    OptionType getType() const;

protected:
    double strike_;
    double maturity_;
    OptionType type_;
};

} // namespace QuantLib

#endif // OPTION_HPP
