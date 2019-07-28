#include "integraloperator.h"

integralOperator::integralOperator
(
    double aF(double),
    int rc,
    double leftEndPoint,
    double rightEndPoint,
    int nIntervals
):
    aF(aF),
    ruleChoice(rc),
    leftEndPoint(leftEndPoint),
    rightEndPoint(rightEndPoint),
    nIntervals(nIntervals),
    integrationRule()
{
    if (ruleChoice == 1)
    {
        integrationRule = std::make_unique<midPointRule>();
    }
    else if (ruleChoice == 2)
    {
        integrationRule = std::make_unique<SimpsonRule>();
    }
    else
    {
        std::cout << "Unknown integration rule: " << ruleChoice << std::endl;
        throw "Unknown integration rule";
    }
}

double integralOperator::calculate()
{
    return integrationRule->calculate(aF, leftEndPoint, rightEndPoint, nIntervals);
}

double midPointRule::calculate
(
    double aF(double),
    double leftEndPoint,
    double rightEndPoint,
    int nIntervals
) const
{
    double delta = (rightEndPoint - leftEndPoint)/nIntervals;
    double ak(0.0);

    for (int i=0;i<nIntervals;i++)
    {
        ak += aF(leftEndPoint + delta*(0.5 + i));
    }

    return delta * ak;
}

double SimpsonRule::calculate
(
    double aF(double),
    double leftEndPoint,
    double rightEndPoint,
    int nIntervals
) const
{
    double delta = (rightEndPoint - leftEndPoint)/nIntervals;
    double deltaHalf = delta/2;
    double xL = leftEndPoint;
    double ak(0.0);

    for (int i=0;i<nIntervals;i++)
    {
        ak += 2*aF(xL) + 4*aF(xL+deltaHalf);
        xL += delta;
    }

    ak += aF(rightEndPoint) - aF(leftEndPoint);
    return delta * ak / 6;
}
