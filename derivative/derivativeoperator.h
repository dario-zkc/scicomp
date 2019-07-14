#ifndef DERIVATIVEOPERATOR_H
#define DERIVATIVEOPERATOR_H

#include <iostream>
#include <memory>

class scheme
{
    public:
        virtual double calculate
        (
            double aF(double),
            double aXValue,
            double aDeltaX
        ) const = 0;

        virtual ~scheme() = default;
};

class firstOrderScheme
: public scheme
{
    public:
        virtual double calculate
        (
            double aF(double),
            double aXValue,
            double aDeltaX
        ) const override;
};

class secondOrderScheme
: public scheme
{
    public:
        virtual double calculate
        (
            double aF(double),
            double aXValue,
            double aDeltaX
        ) const override;
};

class fourthOrderScheme
: public scheme
{
    public:
        virtual double calculate
        (
            double aF(double),
            double aXValue,
            double aDeltaX
        ) const override;
};

class derivativeOperator
{
    private:
        int order;
        double (*aF) (double);
        double aXValue;
        double aDeltaX;
        std::unique_ptr<scheme> numericalScheme;

    public:
        derivativeOperator() = delete;
        derivativeOperator
        (
            double aF(double),
            double aXValue,
            double aDeltaX,
            int ord
        );

        double calculate();
};

#endif // DERIVATIVEOPERATOR_H
