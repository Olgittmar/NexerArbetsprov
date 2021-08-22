// std
#include <iostream>
#include <fstream>

// Own
#include <GeorgesCheesePizza.h>
#include <PlayFair.h>
#include <PersFactorial.h>

int
main( int argc, char* argv[] )
{
    // Need at least 1 solution name arg.
    if( argc < 2 ){
        return 0;
    }
    if( 0 == stricmp( argv[1], "GeorgesCheesePizza") ) {
        // run solution GeorgesCheesePizza
        Solutions::GeorgesCheesePizza(std::cin, std::cout);
    }
    if( 0 == stricmp( argv[1], "PlayFair") ) {
        // run solution PlayFair
        Solutions::PlayFair(std::cin, std::cout);
    }
    if( 0 == stricmp( argv[1], "PersFactorial") ) {
        // run solution PersFactorial
        Solutions::PersFactorial(std::cin, std::cout);
    }
    
    return 0;
}