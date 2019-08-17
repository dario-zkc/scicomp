#ifndef DERIVATIVEOPERATOR_H
#define DERIVATIVEOPERATOR_H

#include <iostream>
#include <memory>
#include <string>

class schemeInterface
{
    public:
        virtual double calculate
        (
            double aF(double),
            double aXValue,
            double aDeltaX
        ) const = 0;

        virtual ~schemeInterface() = default;
};


template <typename ImplScheme>
class scheme
: public schemeInterface
{
    public:
        virtual double calculate
        (
            double aF(double),
            double aXValue,
            double aDeltaX
        ) const override
        {
            return impl().calc(aF, aXValue, aDeltaX);
        }

    friend class firstOrderScheme;
    friend class secondOrderScheme;
    friend class fourthOrderScheme;

    private:
        const ImplScheme& impl() const
        {
            return static_cast<ImplScheme const&>(*this);
        }
};

class firstOrderScheme
: public scheme<firstOrderScheme>
{
    public:
        double calc
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
        double calc
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
        double calc
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
        std::unique_ptr<schemeInterface> numericalScheme;

    public:
        derivativeOperator() = delete;
        derivativeOperator
        (
            double aF(double),
            double aXValue,
            double aDeltaX,
            int ord
        );

        double calculate() const;
};

#endif // DERIVATIVEOPERATOR_H
