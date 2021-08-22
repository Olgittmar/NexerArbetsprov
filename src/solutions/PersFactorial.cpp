#include "PersFactorial.h"

#include <iostream>
#include <ranges>
#include <numeric>
#include <list>

namespace Solutions {

    std::set<int>
    FactorFinder::SieveForPrimeNumbers(int n)
    {
        if( n <= currMax ){
            return primes;
        }

        // Inefficient solution, but if it becomes a problem I'll optimize it later.
        for(int i = currMax; i < n; ++i ) {
            for( auto it = primes.begin(); it != primes.end(); ++it ){
                if( (i % *it) == 0 ) {
                    goto OUTER;
                }
            }
            primes.insert(i);
            OUTER: continue;
        }

        currMax = n;
        return primes;
    }

    std::unordered_map<int, int>
    FactorFinder::FactorFactorial(int n)
    {
        if( currMax < n ){
            SieveForPrimeNumbers(n);
        }

        //! This isn't correct, should be comparing to n!, not n itself.
        std::unordered_map<int,int> _ret;
        for(auto it = primes.begin(); it != primes.end() && (*it) <= n; ++it) {
            int i = 0;
            int r = n;
            while( r % (*it) == 0 ) {
                r = r / (*it);
                ++i;
            }
            _ret[*it] = i;
        }
        return _ret;
    }

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