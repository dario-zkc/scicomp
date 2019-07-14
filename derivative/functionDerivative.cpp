#include <iostream>
#include <math.h>
#include <memory>


double cube(double aD)
{
    return pow(aD, 3);
}

double linear(double aD)
{
    return pow(aD, 1);
}

class scheme
{
private:

public:
    virtual double calculate(double aF(double), double aXValue, double aDeltaX) const = 0;
    virtual ~scheme() = default;
};

class firstOrderScheme : public scheme
{
public:
    virtual double calculate(double aF(double), double aXValue, double aDeltaX) const override
    {
        return (aF(aXValue + aDeltaX) - aF(aXValue))
                / aDeltaX;
    }
};

class secondOrderScheme : public scheme
{
public:

    virtual double calculate(double aF(double), double aXValue, double aDeltaX) const override
    {
        return (aF(aXValue + aDeltaX) - aF(aXValue - aDeltaX))
                / (2 * aDeltaX);
    }
};

class fourthOrderScheme : public scheme
{
public:
    virtual double calculate(double aF(double), double aXValue, double aDeltaX) const override
    {
        return (aF(aXValue - 2*aDeltaX) - 8*aF(aXValue - aDeltaX)
                + 8*aF(aXValue + aDeltaX) - aF(aXValue + 2*aDeltaX))
                / (12 * aDeltaX);
    }
};

class derivOperator
{
private:
    int order;
    double (*aF) (double);
    double aXValue;
    double aDeltaX;
    std::unique_ptr<scheme> numericalScheme;

public:
    derivOperator(double aF(double), double aXValue, double aDeltaX, int ord):
    aF(aF),
    aXValue(aXValue),
    aDeltaX(aDeltaX),
    order(ord),
    numericalScheme()
    {
        if (order == 1)
        {
            numericalScheme = std::make_unique<firstOrderScheme>();
        }
        else if (order == 2)
        {
            numericalScheme = std::make_unique<secondOrderScheme>();
        }
        else if (order == 4)
        {
            numericalScheme = std::make_unique<fourthOrderScheme>();
        }
        else
        {
            std::cout << "Unknown order of accuracy: " << order << std::endl;
        }
    }

    double calculate()
    {
        return numericalScheme->calculate(aF, aXValue, aDeltaX);
    }
};


int main ()
{
    double deltaX = 1e-1;
    double xValue = 1.0;

    int functionChoice;
    int orderChoice;
    double (*myFunction) (double);

    // Stores memory address of function
    std::cout << "Choose a function 1 - cube, 2 - linear: ";
    std::cin >> functionChoice;
    std::cout << "Choose order of accuracy 1 - first, 2 - second, 4 - fourth: ";
    std::cin >> orderChoice;

    switch (functionChoice)
    {
        case 1: myFunction = cube; break;
        // Output: 3.31
        case 2: myFunction = linear; break; // Output: 1
        default: std::cout << "Incorrect Input - program exiting";
    }
    derivOperator dop(myFunction, xValue, deltaX, orderChoice);

    std::cout << dop.calculate() << std::endl;
}
