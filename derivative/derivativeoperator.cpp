#include "derivativeoperator.h"

derivativeOperator::derivativeOperator
(
    double aF(double),
    double aXValue,
    double aDeltaX,
    int ord
):
    aF(aF),
    aXValue(aXValue),
    aDeltaX(aDeltaX),
    order(ord),
    derivativeScheme()
{
    if (order == 1)
    {
        derivativeScheme = std::make_unique<firstOrderDerivative>();
    }
    else if (order == 2)
    {
        derivativeScheme = std::make_unique<secondOrderDerivative>();
    }
    else if (order == 4)
    {
        derivativeScheme = std::make_unique<fourthOrderDerivative>();
    }
    else
    {
        std::cout << "Unknown order of accuracy: " << order << std::endl;
        throw "Unknown order of accuracy";
    }
}

double derivativeOperator::calculate()
{
    return derivativeScheme->calculate(aF, aXValue, aDeltaX);
}

double firstOrderDerivative::calculate
(
    double aF(double),
    double aXValue,
    double aDeltaX
) const
{
    return (aF(aXValue + aDeltaX) - aF(aXValue))
            / aDeltaX;
}

double secondOrderDerivative::calculate
(
    double aF(double),
    double aXValue,
    double aDeltaX
) const
{
    return (aF(aXValue + aDeltaX) - aF(aXValue - aDeltaX))
            / (2 * aDeltaX);
}

double fourthOrderDerivative::calculate
(
    double aF(double),
    double aXValue,
    double aDeltaX
) const
{
    return (aF(aXValue - 2*aDeltaX) - 8*aF(aXValue - aDeltaX) + 8*aF(aXValue + aDeltaX) - aF(aXValue + 2*aDeltaX))
            / (12 * aDeltaX);
}
