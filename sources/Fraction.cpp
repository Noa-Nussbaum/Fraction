#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace ariel{
    Fraction::Fraction(int one,int two){}
    Fraction::Fraction(float one){}
    std::ostream& operator<<(std::ostream& os, const Fraction& obj)
    {
        // write obj to stream
        return os;
    }

    
    // fraction to fraction
        Fraction Fraction::operator+(Fraction other){
            return Fraction(1,3);
        }
        Fraction Fraction::operator-(Fraction other){
            return Fraction(1,3);
        }
        Fraction Fraction::operator*(Fraction other){
            return Fraction(1,3);
        }
        Fraction Fraction::operator/(Fraction other){
            return Fraction(1,3);
        }
        bool Fraction::operator==(Fraction other){
            return true;
        }
        bool Fraction::operator>(Fraction other){
            return true;
        }
        bool Fraction::operator<(Fraction other){
            return true;
        }
        bool Fraction::operator>=(Fraction other){
            return true;
        }
        bool Fraction::operator<=(Fraction other){
            return true;
        }
        Fraction Fraction::operator++(){
            return Fraction(1,3); 
        }
        Fraction Fraction::operator--(){
            return Fraction(1,3);
        }
        Fraction Fraction::operator++(int){
            return Fraction(1,3);
        }
        Fraction Fraction::operator--(int){
            return Fraction(1,3);
        }



    // float to fraction
        Fraction operator+(float other, Fraction f){
            return Fraction(1,3);
        }
        Fraction operator-(float other, Fraction fraction){
            return Fraction(1,3);
        }
        Fraction operator*(float other, Fraction fraction){
            return Fraction(1,3);
        }
        Fraction operator/(float other, Fraction fraction){
            return Fraction(1,3);
        }
        bool operator==(float other, Fraction fraction){
            return true;
        }
        bool operator>(float other, Fraction fraction){
            return true;
        }
        bool operator<(float other, Fraction fraction){
            return true;
        }
        bool operator>=(float other, Fraction fraction){
            return true;
        }
        bool operator<=(float other, Fraction fraction){
            return true;
        }



}
    