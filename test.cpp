#include "doctest.h"
#include "sources/Fraction.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>

using namespace std;

namespace ariel{

TEST_CASE("Initiation"){

    Fraction one(5,3);
    CHECK(one==5/3);

    Fraction two(8,2);
    CHECK(two==8/2);

    Fraction three(14,21);
    CHECK(three==14/21);

    // CHECK_THROWS(Fraction four(14,0));

}
TEST_CASE("Addition"){

    Fraction one(5,3);
    Fraction two(8,2);
    Fraction three(17,3);

    CHECK(one+two==three);
    CHECK(one+one==2*one);
    CHECK(two+two==2*one);
    
}

TEST_CASE("Subtraction"){

    Fraction one(5,3);
    Fraction two(8,2);
    Fraction three(-7,3);

    CHECK(one-two==three);
    CHECK(two-two==0);
    CHECK(three-three==0);

}

TEST_CASE("Multiplication"){

    Fraction one(5,3);
    Fraction two(8,2);
    Fraction three(25,9);
    Fraction four(20,3);
    Fraction four(16,1);

    CHECK(one*one==three);
    CHECK(two*one==four);
    CHECK(two*two==four);

}

TEST_CASE("Division"){

    Fraction one(5,3);
    Fraction two(8,2);
    Fraction three(5,12);
    Fraction four(7,9);
    Fraction five(15,28);
    Fraction six(1,1);


    CHECK(one/two==three);
    CHECK(three/four==five);
    CHECK(four/four==six);
    CHECK(five/five==six);


}
TEST_CASE("Equals == "){
        
    Fraction one(64,17);
    Fraction two(64,2);
    Fraction three(64,17);
    
    CHECK(one==three);
    CHECK_FALSE(one==two);

}
TEST_CASE("All comparisons"){
        
    Fraction one(64,17);
    Fraction two(64,2);
    Fraction three(64,17);

    CHECK(one==three);
    CHECK_FALSE(one==two);
    

}
TEST_CASE("++ pre fix"){
        
        

}
TEST_CASE("++ post fix"){
        
        

}
TEST_CASE("-- pre fix"){
        
        

}
TEST_CASE("-- post fix"){
        
        

}
TEST_CASE("<< operator"){
        
        

}
TEST_CASE(">> operator"){
        
        

}



}
