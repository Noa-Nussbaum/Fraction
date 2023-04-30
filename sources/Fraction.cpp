#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <numeric>

namespace ariel{
    Fraction::Fraction(const int& numerator,const int& denominator){
        if(denominator!=0){
            int gcd = std::gcd(numerator,denominator);
            this->numerator=numerator/gcd;
            this->denominator=denominator/gcd;
        }
    }

    Fraction::Fraction(const float& one){

    }

    std::ostream& operator<<(std::ostream& output, const Fraction& fraction)
    {
        return (output << fraction.numerator << "/" << fraction.denominator << endl);
    }
    
    // fraction to fraction
    Fraction Fraction::operator+(Fraction other){
        int numerator1 = this->numerator*other.denominator;
        int numerator2 = this->denominator*other.numerator;
        return Fraction(numerator1+numerator2,this->denominator*other.denominator);
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


    // Other functions
    Fraction Fraction::GCD(){
        int gcd = std::gcd(numerator,denominator);
        return Fraction(numerator/gcd,denominator/gcd);
    }



}
    