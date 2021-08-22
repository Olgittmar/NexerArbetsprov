#include "PersFactorial.h"
#include <iostream>

namespace Solutions {

    std::string
    FindLastThreeNonZeroDigitsOfFactorial(int n)
    {
        std::string N = std::to_string(n);
        return N.substr( N.size() - 4, 3 );
    }

    void
    PersFactorial(std::istream& in, std::ostream& out)
    {
        int n;
        in >> n;
        out << FindLastThreeNonZeroDigitsOfFactorial(n);
    }
}