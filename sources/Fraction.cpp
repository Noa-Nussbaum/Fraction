#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace ariel{
    Fraction::Fraction(int one,int two){}

    Fraction operator+(Fraction other){
        Fraction(1,3);
    }

    std::ostream& operator<<(std::ostream& os, const Fraction& obj)
    {
        // write obj to stream
        return os;
    }
    // Fraction operator+(float other, Fraction f){
    // }

    

}
    