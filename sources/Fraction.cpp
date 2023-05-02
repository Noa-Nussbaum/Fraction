#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <numeric>
#include <cstdlib>

namespace ariel{

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    Fraction::Fraction(const int& numerator,const int& denominator){
        int gcd = std::gcd(abs(numerator),abs(denominator));
        if(denominator!=0){
            if((numerator<0 && denominator>0) || (denominator<0 && numerator>0)){
                this->numerator=-abs(numerator)/gcd;
                this->denominator=abs(denominator)/gcd;
            }
            else if(numerator<0 && denominator<0){
                this->numerator=abs(numerator)/gcd;
                this->denominator=abs(denominator)/gcd;
            }
            else{
                this->numerator=abs(numerator)/gcd;
                this->denominator=abs(denominator)/gcd;
            }
        }
        else{
            throw std::invalid_argument("Error: Denominator equals 0");
        }
    }

    Fraction::Fraction(): numerator(0), denominator(1) {}


    int Fraction::getNumerator() const{
        return this->numerator;
    }
    int Fraction::getDenominator() const{
        return this->denominator;
    }

    Fraction::Fraction(const float& one){
        Fraction f(one*1000,1000);
        this->numerator =f.numerator;
        this->denominator = f.denominator;
    }

    std::ostream& operator<<(std::ostream& output, const Fraction& fraction)
    {
        return (output << fraction.numerator << "/" << fraction.denominator );
    }



std::istream& operator>>( std::istream& input, Fraction& fraction) {

    


    // Extract the numerator and denominator from the input string
    
    int numerator, denominator;

    input >> numerator >> denominator;
    if(input.fail())
    throw std::runtime_error("dsff");
    else if (denominator==0)
        throw std::runtime_error("dsff");

    // Set the fraction's numerator and denominator
    fraction = Fraction(numerator,denominator);
    
    // Return the input stream
    return input;
}

std::stringstream& operator>>(std::stringstream& input, Fraction& fraction) {
    // call the existing operator>> for istringstream
    std::istringstream temp(input.str());
    temp >> fraction;
    return input;
}

    
    // fraction to fraction
    Fraction Fraction::operator+(Fraction other){
        int numerator1 = this->numerator*other.denominator;
        int numerator2 = this->denominator*other.numerator;
        return Fraction(numerator1+numerator2,this->denominator*other.denominator);
    }
    Fraction Fraction::operator-(Fraction other){
        int numerator1 = this->numerator*other.denominator;
        int numerator2 = this->denominator*other.numerator;
        return Fraction(numerator1-numerator2,this->denominator*other.denominator);
    }
    Fraction Fraction::operator*(Fraction other){
        if(this->numerator*other.numerator > max_int || this->denominator*other.denominator> max_int){
            throw std::overflow_error("Too big");
        }
        return Fraction(this->numerator*other.numerator,this->denominator*other.denominator);
    }

    Fraction Fraction::operator/(Fraction other){
        if(other.getNumerator()==0){
            throw std::runtime_error("Division by zero");
        }else{
            return Fraction(this->numerator*other.denominator,this->denominator*other.numerator);
        }
    }


    bool Fraction::operator==(const Fraction other)const{
        return (this->numerator==other.getNumerator() && this->denominator == other.getDenominator());
    }

    bool Fraction::operator>(const Fraction other)const{
        int one = this->numerator*other.denominator;
        int two = this->denominator*other.numerator;
        return (one>two);
    }
    bool Fraction::operator<(const Fraction other)const{
        int one = this->numerator*other.denominator;
        int two = this->denominator*other.numerator;
        return (one<two);
    }
    bool Fraction::operator>=(const Fraction other)const{
        int one = this->numerator*other.denominator;
        int two = this->denominator*other.numerator;
        return (one>=two);
    }
    bool Fraction::operator<=(const Fraction other)const{
        int one = this->numerator*other.denominator;
        int two = this->denominator*other.numerator;
        return (one<=two);
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
        return (fraction+other);
    }
    Fraction operator-(float other, Fraction fraction){
        return ((fraction)*(-1)+other);
    }
    Fraction operator*(float other, Fraction fraction){
        return (fraction*other);
    }
    Fraction operator/(float other, Fraction fraction){
        return (Fraction(other)/fraction);
    }
    bool operator==(const float other, Fraction fraction){
        return (fraction==Fraction(other));
    }
    bool operator>(const float other, Fraction fraction){
        return (fraction<Fraction(other));
    }
    bool operator<(const float other, Fraction fraction){
        return (fraction>Fraction(other));
    }
    bool operator>=(const float other, Fraction fraction){
        return (fraction<=Fraction(other));
    }
    bool operator<=(const float other, Fraction fraction){
        return (fraction>=Fraction(other));
    }

    // Other functions
    Fraction Fraction::GCD(){
        int gcd = std::gcd(numerator,denominator);
        return Fraction(numerator/gcd,denominator/gcd);
    }
}
    