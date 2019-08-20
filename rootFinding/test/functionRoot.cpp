#include <iostream>
#include <math.h>
#include "rootFinding/rootfinder.h"

double poliquadratic(double x)
{
    return (pow(x, 2) + 3*x - 10);
}

double policubic(double x)
{
    return (pow(x, 3) + 3*x - 10);
}

int main()
{
    double intervalBegin = 0.0;
    double intervalEnd = 5.0;

    int functionChoice;
    double (*myFunction) (double);
    int methodChoice;

    // Stores memory address of function
    std::cout << "Choose a function 1 - quadratic polynomial, 2 - cubic polynomial: ";
    std::cin >> functionChoice;
    std::cout << "Choose a method 1 - bisection, 2 - Newton-Raphson : ";
    std::cin >> methodChoice;

    switch (functionChoice)
    {
        case 1: myFunction = poliquadratic; break;
        case 2: myFunction = policubic; break;
        default: std::cout << "Incorrect Input - program exiting" << std::endl; return 1;
    }

    try
    {
        if (methodChoice == 1)
        {
            rootFinder rf(myFunction, intervalBegin, intervalEnd);
            std::cout << rf.calculate() << std::endl;
        }
        else if (methodChoice == 2)
        {
            int orderChoice;
            std::cout << "Choose the order of accuracy for the derivative operator: " << std::endl
                      << "1 - first, 2 - second, 4 - fourth: " << std::endl;
            std::cin >> orderChoice;
            rootFinder rf(myFunction, intervalBegin, intervalEnd, orderChoice);
            std::cout << rf.calculate() << std::endl;
        }
        else
        {
            std::cout << "Wrong method choice" << std::endl;
        }
    }
    catch( ... )
    {
        return 1;
    }

}
