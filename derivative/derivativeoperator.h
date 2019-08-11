#ifndef DERIVATIVEOPERATOR_H
#define DERIVATIVEOPERATOR_H

#include <iostream>
#include <unordered_map>
#include <string>

template <typename ImplScheme>
class scheme
{
    public:
        double calculate
        (
            double aF(double),
            double aXValue,
            double aDeltaX
        ) const
        {
            return impl().calculate(aF, aXValue, aDeltaX);
        }

    const ImplScheme& impl() const
    {
        return static_cast<ImplScheme const&>(*this);
    }
};

class firstOrderScheme
: public scheme<firstOrderScheme>
{
    public:
        double calculate
        (
            double aF(double),
            double aXValue,
            double aDeltaX
        ) const;
};

class secondOrderScheme
: public scheme<secondOrderScheme>
{
    public:
        double calculate
        (
            double aF(double),
            double aXValue,
            double aDeltaX
        ) const;
};

class fourthOrderScheme
: public scheme<fourthOrderScheme>
{
    public:
        double calculate
        (
            double aF(double),
            double aXValue,
            double aDeltaX
        ) const;
};

class derivativeOperator
{
    private:
        int order;
        double (*aF) (double);
        double aXValue;
        double aDeltaX;

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

        template <typename Implementation>
        double calcImp(const scheme<Implementation>& numScheme);
};

#endif // DERIVATIVEOPERATOR_H
