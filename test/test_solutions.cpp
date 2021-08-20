#include "gtest/gtest.h"
#include <GeorgesCheesePizza.h>
#include <PersFactorial.h>
#include <PlayFair.h>

TEST(TestGeorgesCheesePizza, GenericInput) {
    EXPECT_EQ( Solutions::CalculateCheesePercentage(1, 1), 0.0 );
    EXPECT_EQ( Solutions::CalculateCheesePercentage(100, 100), 0.0 );
    EXPECT_EQ( Solutions::CalculateCheesePercentage(2, 1), 25.0 );
    EXPECT_NEAR( Solutions::CalculateCheesePercentage(3, 2), (100.0/9.0), 0.000001 );
}

TEST(TestPlayFair, GenericInput) {
    std::string in = "4\n"
                     "ThisIsATest\n"
                     "AQuickBrownFox\n"
                     "JumpedOverTheLazyDogs\n"
                     "Playfair ciphers are fun\n"
                     "Hooray for cryptology\n"
                     "2\n"
                     "Just another example\n"
                     "Meet me at eight o clock\n"
                     "Signed Agent Double O Eight\n"
                     "0";
    std::string expected = "IUQABLDPPVUNQV\n"
                           "AQKRBFVTDOHICGFASMVOIY\n"
                           "QKSZNFSQLCWBDOATODNZLZ\n"
                           "TPPUSZEUQDYSOHQGVOZY\n"
                           "\n"
                           "LOLELOIANTFEUEGXNDCB\n"
                           "TUCEOGTKROUGMOXBRHNTFEIL\n";
    EXPECT_EQ( Solutions::EncodeMessage(in), expected );
}
