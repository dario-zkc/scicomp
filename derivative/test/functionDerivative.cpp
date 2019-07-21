#include <iostream>
#include <math.h>
#include "../derivativeoperator.h"

double cube(double aD)
{
    return pow(aD, 3);
}

double linear(double aD)
{
    return pow(aD, 1);
}

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
        default: std::cout << "Incorrect Input - program exiting" << std::endl; return 1;
    }

    try
    {
        derivativeOperator dop(myFunction, xValue, deltaX, orderChoice);
        std::cout << dop.calculate() << std::endl;
    }
    catch( ... ) {
        return 1;
    }

}
