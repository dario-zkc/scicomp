#ifndef DERIVATIVEOPERATOR_H
#define DERIVATIVEOPERATOR_H

#include <iostream>
#include <memory>

class derivative
{
    public:
        virtual double calculate
        (
            double aF(double),
            double aXValue,
            double aDeltaX
        ) const = 0;

        virtual ~derivative() = default;
};

class firstOrderDerivative
: public derivative
{
    public:
        virtual double calculate
        (
            double aF(double),
            double aXValue,
            double aDeltaX
        ) const override;
};

class secondOrderDerivative
: public derivative
{
    public:
        virtual double calculate
        (
            double aF(double),
            double aXValue,
            double aDeltaX
        ) const override;
};

class fourthOrderDerivative
: public derivative
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
        std::unique_ptr<derivative> derivativeScheme;

    public:
        derivativeOperator() = delete;
        derivativeOperator
        (
            double aF(double),
            double aXValue,
            double aDeltaX,
            int ord
        );

        void setX(double newX);
        void setDeltaX(double newDeltaX);

        double calculate();
};

#endif // DERIVATIVEOPERATOR_H
