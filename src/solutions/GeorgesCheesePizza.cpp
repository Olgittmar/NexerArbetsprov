#include "GeorgesCheesePizza.h"
#include <string>

namespace Solutions {
    void
    GeorgesCheesePizza(std::istream& in, std::ostream& out)
    {
        int r, c;
        in >> r >> c;
        out << std::to_string( CalculateCheesePercentage(r, c) ) << std::endl;
    }

    double
    CalculateCheesePercentage(int r, int c)
    {
        // return 100.0*(AreaOfCircle(cheeseRadius)/AreaOfCircle(r));
        double ratio = ((double)c)/r;
        return 100.0*(1.0 - 2*ratio + ratio*ratio);
    }
}