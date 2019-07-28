#ifndef INTEGRALOPERATOR_H
#define INTEGRALOPERATOR_H

#include <iostream>
#include <memory>

class rule
{
    public:
        virtual double calculate
        (
            double aF(double),
            double leftEndPoint,
            double rightEndPoint,
            int nIntervals
        ) const = 0;

        virtual ~rule() = default;
};

class midPointRule
: public rule
{
    public:
        virtual double calculate
        (
            double aF(double),
            double leftEndPoint,
            double rightEndPoint,
            int nIntervals
        ) const override;
};

class SimpsonRule
: public rule
{
    public:
        virtual double calculate
        (
            double aF(double),
            double leftEndPoint,
            double rightEndPoint,
            int nIntervals
        ) const override;
};

class integralOperator
{
    private:
        double (*aF) (double);
        int ruleChoice;
        double leftEndPoint;
        double rightEndPoint;
        int nIntervals;
        std::unique_ptr<rule> integrationRule;

    public:
        integralOperator() = delete;
        integralOperator
        (
            double aF(double),
            int rc,
            double leftEndPoint,
            double rightEndPoint,
            int nIntervals
        );

        double calculate();
};

#endif // INTEGRALOPERATOR_H
