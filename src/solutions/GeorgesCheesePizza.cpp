#include "GeorgesCheesePizza.h"
#define _USE_MATH_DEFINES
// Std
#include <iostream>
#include <cmath>

namespace Solutions {
    void
    GeorgesCheesePizza()
    {
        int r, c;
        std::cin >> r >> c;
        std::cout << CalculateCheesePercentage(r, c);
    }

    double
    CalculateCheesePercentage(int r, int c)
    {
        // return 100.0*(AreaOfCircle(cheeseRadius)/AreaOfCircle(r));
        double ratio = ((double)c)/r;
        return 100.0*(1.0 - 2*ratio + ratio*ratio);
    }
}