// std
#include <iostream>
#include <fstream>

// Own
#include <GeorgesCheesePizza.h>

int
main( int argc, char* argv[] )
{
    // Need at least 1 solution name arg.
    if( argc < 2 ){
        return 0;
    }
    if( 0 == stricmp( argv[1], "GeorgesCheesePizza") ) {
        // run solution GeorgesCheesePizza
        Solutions::GeorgesCheesePizza();
    }
    if( 0 == stricmp( argv[1], "PlayFair") ) {
        // run solution PlayFair
    }
    if( 0 == stricmp( argv[1], "PersFactorial") ) {
        // run solution PersFactorial
    }
    
    return 0;
}