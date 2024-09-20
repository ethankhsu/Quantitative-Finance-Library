// BlackScholesModel.hpp
#ifndef BLACKSCHOLESMODEL_HPP
#define BLACKSCHOLESMODEL_HPP

#include "EuropeanOption.hpp"

namespace QuantLib {

class BlackScholesModel {
public:
    BlackScholesModel(double riskFreeRate, double volatility);
    double optionPrice(const EuropeanOption& option, double spotPrice) const;

private:
    double riskFreeRate_;
    double volatility_;
    double normalCDF(double x) const;
};

} // namespace QuantLib

#endif // BLACKSCHOLESMODEL_HPP
