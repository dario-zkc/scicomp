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

//rootFinder::rootFinder
//(
//    double aF(double),
//    double ll,
//    double rl,
//    int order
//):
//    aF(aF),
//    leftLimit(ll),
//    rightLimit(rl),
//    method()
//{
//    std::cout << "Constructing 'Newton' method" << std::endl;
//    method = std::make_unique<NewtonMethod>(order);
//}

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
    double error = 1e-6;

    while (abs(leftLimit - rightLimit) > error)
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

//NewtonMethod::NewtonMethod(int order):
//    dop()
//{

//}
