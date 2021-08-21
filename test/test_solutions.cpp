#include "gtest/gtest.h"
#include <GeorgesCheesePizza.h>
#include <PersFactorial.h>
#include <PlayFair.h>

TEST(TestCalculateCheesePercentage, GenericInput) {
    EXPECT_EQ( Solutions::CalculateCheesePercentage(1, 1), 0.0 );
    EXPECT_EQ( Solutions::CalculateCheesePercentage(2, 1), 25.0 );
    EXPECT_EQ( Solutions::CalculateCheesePercentage(100, 100), 0.0 );
    EXPECT_NEAR( Solutions::CalculateCheesePercentage(3, 2), (100.0/9.0), 0.000001 );
}

TEST(TestGeorgesCheesePizza, IOStreamInput) {
    std::string in[] = {
        "1 1",
        "2 1",
        "100 100",
        "3 2"};
    double expected[] = {
        0.0,
        25.0,
        0.0,
        (100.0/9.0)};
    
    for(int i = 0; i < size(in); ++i){
        std::stringstream istrm(in[i]);
        std::stringstream ostrm;
        Solutions::GeorgesCheesePizza(istrm, ostrm);
        EXPECT_NEAR(std::stod(ostrm.str()), expected[i], 0.000001);
    }
}

TEST(TestEncryptDigraph, GenericInput) {
    auto table = Solutions::EncryptionTable("ThisIsATest");
    for(int i = 0; i < 5; ++i){
        std::cerr << table.GetTable().substr(i*5, 5) << std::endl;
    }

    EXPECT_STREQ( table.EncryptDigraph("BR").c_str(), "DP" );
    EXPECT_STREQ( table.EncryptDigraph("AV").c_str(), "TZ" );
    EXPECT_STREQ( table.EncryptDigraph("CY").c_str(), "DX" );
    EXPECT_STREQ( table.EncryptDigraph("IC").c_str(), "CL" );
    EXPECT_STREQ( table.EncryptDigraph("PW").c_str(), "WH" );
    EXPECT_STREQ( table.EncryptDigraph("KM").c_str(), "LN" );
    EXPECT_STREQ( table.EncryptDigraph("DF").c_str(), "FE" );

    EXPECT_STREQ( table.EncryptDigraph("HO").c_str(), "TP" );
    EXPECT_STREQ( table.EncryptDigraph("OR").c_str(), "PU" );
    EXPECT_STREQ( table.EncryptDigraph("AY").c_str(), "SZ" );
    EXPECT_STREQ( table.EncryptDigraph("FO").c_str(), "EU" );
    EXPECT_STREQ( table.EncryptDigraph("RC").c_str(), "QD" );
    EXPECT_STREQ( table.EncryptDigraph("RY").c_str(), "YS" );
    EXPECT_STREQ( table.EncryptDigraph("PT").c_str(), "OH" );
    EXPECT_STREQ( table.EncryptDigraph("OL").c_str(), "QG" );
    EXPECT_STREQ( table.EncryptDigraph("OG").c_str(), "VO" );
    EXPECT_STREQ( table.EncryptDigraph("YX").c_str(), "ZY" );

    table = Solutions::EncryptionTable("Playfair");
    for(int i = 0; i < 5; ++i){
        std::cerr << table.GetTable().substr(i*5, 5) << std::endl;
    }

    EXPECT_STREQ( table.EncryptDigraph("RS").c_str(), "CO" );
    EXPECT_STREQ( table.EncryptDigraph("FU").c_str(), "PZ" );
    EXPECT_STREQ( table.EncryptDigraph("UF").c_str(), "ZP" );
    EXPECT_STREQ( table.EncryptDigraph("EM").c_str(), "GE" );
    EXPECT_STREQ( table.EncryptDigraph("HW").c_str(), "QA" );
    EXPECT_STREQ( table.EncryptDigraph("OC").c_str(), "SR" );
    EXPECT_STREQ( table.EncryptDigraph("XZ").c_str(), "ZU" );
}

TEST(TestDigraphList, GenericInput) {
    EXPECT_STREQ( Solutions::DigraphList("Hello World").toString().c_str(), "HELXLOWORLDX" );
    EXPECT_STREQ( Solutions::DigraphList("WHOOP").toString().c_str(), "WHOXOP" );
    EXPECT_STREQ( Solutions::DigraphList("AQuickBrownFox").toString().c_str(), "AQUICKBROWNFOX" );
    EXPECT_STREQ( Solutions::DigraphList("JumpedOverTheLazyDogs").toString().c_str(), "IUMPEDOVERTHELAZYDOGSX" );
    EXPECT_STREQ( Solutions::DigraphList("Hooray for cryptology").toString().c_str(), "HOORAYFORCRYPTOLOGYX" );
}

TEST(TestEncryptionTable, GenericInput) {
    EXPECT_STREQ( Solutions::EncryptionTable("ThisIsATest").GetTable().c_str(), "THISAEBCDFGKLMNOPQRUVWXYZ" );
    EXPECT_STREQ( Solutions::EncryptionTable("Playfair").GetTable().c_str(), "PLAYFIRBCDEGHKMNOQSTUVWXZ" );
}

TEST(TestEncodeMessage, GenericInput) {
    auto table = Solutions::EncryptionTable("ThisIsATest");
    EXPECT_STREQ( Solutions::EncodeMessage("AQuickBrownFox", table).c_str(), "IUQABLDPPVUNQV" );
    EXPECT_STREQ( Solutions::EncodeMessage("JumpedOverTheLazyDogs", table).c_str(), "AQKRBFVTDOHICGFASMVOIY" );
    EXPECT_STREQ( Solutions::EncodeMessage("Playfair ciphers are fun", table).c_str(), "QKSZNFSQLCWBDOATODNZLZ" );
    EXPECT_STREQ( Solutions::EncodeMessage("Hooray for cryptology", table).c_str(), "TPPUSZEUQDYSOHQGVOZY" );

    table = Solutions::EncryptionTable("Just another example");
    EXPECT_STREQ( Solutions::EncodeMessage("Meet me at eight o clock", table).c_str(), "LOLELOIANTFEUEGXNDCB" );
    EXPECT_STREQ( Solutions::EncodeMessage("Signed Agent Double O Eight", table).c_str(), "TUCEOGTKROUGMOXBRHNTFEIL" );
}

TEST(TestPlayFair, IOStreamInput) {
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

    std::stringstream istrm(in);
    std::stringstream ostrm;
    Solutions::PlayFair( istrm, ostrm );

    EXPECT_STREQ( ostrm.str().c_str(), expected.c_str() );
}
