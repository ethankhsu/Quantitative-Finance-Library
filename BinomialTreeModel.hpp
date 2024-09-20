// BinomialTreeModel.hpp
#ifndef BINOMIALTREEMODEL_HPP
#define BINOMIALTREEMODEL_HPP

#include "Option.hpp"

namespace QuantLib {

class BinomialTreeModel {
public:
    BinomialTreeModel(double riskFreeRate, double volatility, int numSteps);
    double optionPrice(const Option& option, double spotPrice) const;

private:
    double riskFreeRate_;
    double volatility_;
    int numSteps_;
};

} // namespace QuantLib

#endif // BINOMIALTREEMODEL_HPP
