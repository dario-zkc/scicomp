#include <iostream>
#include <math.h>
#include "../integraloperator.h"

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
    double leftEndPoint = 0.0;
    double rightEndPoint = 2;
    int nIntervals = 2;

    int functionChoice;
    int ruleChoice;
    double (*myFunction) (double);

    // Stores memory address of function
    std::cout << "Choose a function 1 - cube, 2 - linear: ";
    std::cin >> functionChoice;
    std::cout << "Choose integration rule 1 - midpoint, 2 - Simpson: ";
    std::cin >> ruleChoice;

    switch (functionChoice)
    {
        case 1: myFunction = cube; break;
        case 2: myFunction = linear; break;
        default: std::cout << "Incorrect Input - program exiting" << std::endl; return 1;
    }

    try
    {
        integralOperator iop
        (
            myFunction,
            ruleChoice,
            leftEndPoint,
            rightEndPoint,
            nIntervals
        );
        std::cout << iop.calculate() << std::endl;
    }
    catch( ... )
    {
        return 1;
    }

}
