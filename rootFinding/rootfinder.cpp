#include "rootfinder.h"
#include <iostream>
#include <math.h>

rootFinder::rootFinder
(
    double aF(double),
    double ll,
    double rl
):
    aF(aF),
    leftLimit(ll),
    rightLimit(rl),
    method()
{
    std::cout << "Constructing 'Bisection' method" << std::endl;
    method = std::make_unique<bisection>();
}

rootFinder::rootFinder
(
    double aF(double),
    double ll,
    double rl,
    int order
):
    aF(aF),
    leftLimit(ll),
    rightLimit(rl),
    method()
{
    std::cout << "Constructing 'Newton' method" << std::endl;
    method = std::make_unique<NewtonMethod>(order);
}

double rootFinder::calculate() const
{
    return method->calculate(aF, leftLimit, rightLimit);
}

double bisection::calculate
(
    double aF(double),
    double ll,
    double rl
) const
{
    double leftLimit = ll;
    double rightLimit = rl;

    while (abs(leftLimit - rightLimit) > tolerance)
    {
        double midpoint = (leftLimit + rightLimit)/2;
        if (aF(midpoint) * aF(rightLimit) <= 0.0)
        {
            leftLimit = midpoint;
        }
        else
        {
            rightLimit = midpoint;
        }
    }
    return (leftLimit + rightLimit)/2;
}

NewtonMethod::NewtonMethod(int order)
:derivativeOrder(order)
{}

double NewtonMethod::calculate
(
    double aF(double),
    double ll,
    double rl
) const
{
    double dfdx = 0.0;
    int count = 0;

    double deltaX = abs(ll-rl)/10;
    double rootEstimate = (aF(ll) + aF(rl))/2;

    derivativeOperator dop
        (
            aF,
            rootEstimate,
            deltaX,
            derivativeOrder
        );

    while ((abs(deltaX) >= tolerance) && (count < 10))
    {
        dfdx = dop.calculate();

        deltaX = -aF(rootEstimate) / dfdx;
        rootEstimate += deltaX;

        dop.setX(rootEstimate);
        dop.setDeltaX(deltaX);

        count++;
    }
    return rootEstimate;
}
