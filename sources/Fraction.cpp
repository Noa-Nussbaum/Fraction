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
            // int gcd = std::gcd(numerator,denominator);
            this->numerator=numerator;
            this->denominator=denominator;
        }
    }

    Fraction::Fraction(const float& one){
        Fraction f(one*1000,1000);
        this->numerator =f.numerator;
        this->denominator = f.denominator;
    }

    std::ostream& operator<<(std::ostream& output, const Fraction& fraction)
    {
        return (output << fraction.numerator << "/" << fraction.denominator << endl);
    }
    
    // fraction to fraction
    Fraction Fraction::operator+(Fraction other){
        int numerator1 = this->numerator*other.denominator;
        int numerator2 = this->denominator*other.numerator;
        return Fraction(numerator1+numerator2,this->denominator*other.denominator).GCD();
    }
    Fraction Fraction::operator-(Fraction other){
        int numerator1 = this->numerator*other.denominator;
        int numerator2 = this->denominator*other.numerator;
        return Fraction(numerator1-numerator2,this->denominator*other.denominator).GCD();
    }
    Fraction Fraction::operator*(Fraction other){
        return Fraction(this->numerator*other.numerator,this->denominator*other.denominator).GCD();
    }

    Fraction Fraction::operator/(Fraction other){
        return Fraction(this->numerator*other.denominator,this->denominator*other.numerator).GCD();
    }

    bool Fraction::operator==(Fraction other){
        return (this->numerator==other.numerator && this->denominator==other.denominator);
    }
    bool Fraction::operator>(Fraction other){
        Fraction one(this->numerator*other.denominator,this->denominator*other.denominator);
        Fraction two(this->denominator*other.numerator,this->denominator*other.denominator);
        return (one.numerator>two.numerator);
    }
    bool Fraction::operator<(Fraction other){
        Fraction one(this->numerator*other.denominator,this->denominator*other.denominator);
        Fraction two(this->denominator*other.numerator,this->denominator*other.denominator);
        return (one.numerator<two.numerator);
    }
    bool Fraction::operator>=(Fraction other){
        Fraction one(this->numerator*other.denominator,this->denominator*other.denominator);
        Fraction two(this->denominator*other.numerator,this->denominator*other.denominator);
        return (one.numerator>=two.numerator);
    }
    bool Fraction::operator<=(Fraction other){
        Fraction one(this->numerator*other.denominator,this->denominator*other.denominator);
        Fraction two(this->denominator*other.numerator,this->denominator*other.denominator);
        return (one.numerator<=two.numerator);
    }
    Fraction Fraction::operator++(){
        // increase and return actual;
        *this = *this+Fraction(1,1);
        return *this;
    }
    Fraction Fraction::operator--(){
        // decrease and return actual;
        *this = *this-Fraction(1,1);
        return *this;
    }
    Fraction Fraction::operator++(int){
        Fraction copy = *this;
        ++*this;
        return copy;
    }
    Fraction Fraction::operator--(int){
        Fraction copy = *this;
        --*this;
        return copy;
    }


    // float to fraction
    Fraction operator+(float other, Fraction fraction){
        return (fraction+other).GCD();
    }
    Fraction operator-(float other, Fraction fraction){
        return ((fraction)*(-1)+other).GCD();
    }
    Fraction operator*(float other, Fraction fraction){
        return (fraction*other).GCD();
    }
    Fraction operator/(float other, Fraction fraction){
        return Fraction(other)/fraction;
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
    