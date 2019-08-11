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
    order(ord)
{}

double derivativeOperator::calculate()
{

    if (order == 1)
    {
        auto numericalScheme = firstOrderScheme();
        return calcImp(numericalScheme);
    }
    else if (order == 2)
    {
        auto numericalScheme = secondOrderScheme();
        return calcImp(numericalScheme);
    }
    else if (order == 4)
    {
        auto numericalScheme = fourthOrderScheme();
        return calcImp(numericalScheme);
    }
    else
    {
        std::cout << "Unknown order of accuracy: " << order << std::endl;
        throw "Unknown order of accuracy";
    }
}

template <typename Implementation>
double derivativeOperator::calcImp(const scheme<Implementation>& numScheme)
{
    return numScheme.calculate(aF, aXValue, aDeltaX);
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
