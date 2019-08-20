#ifndef ROOTFINDER_H
#define ROOTFINDER_H

#include "derivative/derivativeoperator.h"
#include <memory>


class rootFindingMethod
{
    public:
        double tolerance = 1e-6;

        virtual double calculate
        (
            double aF(double),
            double ll,
            double rl
        ) const = 0;
        virtual ~rootFindingMethod() = default;
};

class bisection: public rootFindingMethod
{
    public:
        virtual double calculate
        (
            double aF(double),
            double ll,
            double rl
        ) const override;
};

class NewtonMethod: public rootFindingMethod
{
    public:
        NewtonMethod() = delete;
        NewtonMethod(int order);

        virtual double calculate
        (
            double aF(double),
            double ll,
            double rl
        ) const override;

    private:
        int derivativeOrder;
};

class rootFinder
{
    private:
        double (*aF) (double);
        double leftLimit;
        double rightLimit;
        std::unique_ptr<rootFindingMethod> method;

    public:
        rootFinder() = delete;
        rootFinder
        (
            double aF(double),
            double ll,
            double rl
        );

        rootFinder
        (
            double aF(double),
            double ll,
            double rl,
            int order
        );

        double calculate() const;
};


#endif // ROOTFINDER_H

