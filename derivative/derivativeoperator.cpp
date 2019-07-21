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
    numericalScheme()
{
    if (order == 1)
    {
        numericalScheme = std::make_unique<firstOrderScheme>();
    }
    else if (order == 2)
    {
        numericalScheme = std::make_unique<secondOrderScheme>();
    }
    else if (order == 4)
    {
        numericalScheme = std::make_unique<fourthOrderScheme>();
    }
    else
    {
        std::cout << "Unknown order of accuracy: " << order << std::endl;
        throw "Unknown order of accuracy";
    }
}

double derivativeOperator::calculate()
{
    return numericalScheme->calculate(aF, aXValue, aDeltaX);
}

double firstOrderScheme::calculate
(
    double aF(double),
    double aXValue,
    double aDeltaX
) const
{
    return (aF(aXValue + aDeltaX) - aF(aXValue))
            / aDeltaX;
}

double secondOrderScheme::calculate
(
    double aF(double),
    double aXValue,
    double aDeltaX
) const
{
    return (aF(aXValue + aDeltaX) - aF(aXValue - aDeltaX))
            / (2 * aDeltaX);
}

double fourthOrderScheme::calculate
(
    double aF(double),
    double aXValue,
    double aDeltaX
) const
{
    return (aF(aXValue - 2*aDeltaX) - 8*aF(aXValue - aDeltaX) + 8*aF(aXValue + aDeltaX) - aF(aXValue + 2*aDeltaX))
            / (12 * aDeltaX);
}
