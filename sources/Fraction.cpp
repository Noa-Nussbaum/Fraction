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
        return Fraction(this->numerator+this->denominator,this->denominator); 
    }
    Fraction Fraction::operator--(){
        return Fraction(1,3);
    }
    Fraction Fraction::operator++(int){
        // Fraction copy(this);
        // here i have.a copy and return copy with
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
    