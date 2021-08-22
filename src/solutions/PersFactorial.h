#ifndef PERS_FACTORIAL_H
#define PERS_FACTORIAL_H

#include <string>
#include <set>
#include <unordered_map>

namespace Solutions {
    struct FactorFinder {
      public:
        FactorFinder()
          : currMax(36), primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}) {};
        explicit FactorFinder(int n)
          : FactorFinder() { SieveForPrimeNumbers(n); }

        std::set<int> SieveForPrimeNumbers(int n);
        std::unordered_map<int, int> FactorFactorial(int n);

      private:
        int currMax;
        std::set<int> primes;
    };

    std::string FindLastThreeNonZeroDigitsOfFactorial(int n);
    void PersFactorial(std::istream& in, std::ostream& out);
}

#endif