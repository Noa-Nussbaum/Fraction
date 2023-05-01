#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <numeric>
#include <cstdlib>

namespace ariel{
    Fraction::Fraction(const int& numerator,const int& denominator){
        if(denominator!=0){
            if((numerator<0 && denominator>0) || (denominator<0 && numerator>0)){
                this->numerator=-abs(numerator);
                this->denominator=abs(denominator);
            }
            else if(numerator<0 && denominator<0){
                this->numerator=abs(numerator);
                this->denominator=abs(denominator);
            }
            else{
                this->numerator=abs(numerator);
                this->denominator=abs(denominator);
            }
        }
        else{
            throw std::invalid_argument("Error: Denominator equals 0");
        }
    }

    Fraction() : numerator(0), denominator(1) {}


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



std::istringstream& operator>>(const std::istringstream& input, Fraction& fraction)const {

    std::string buffer;
    std::getline(input, buffer);

    std::string input_str = input.str();
    if (input_str.length() < 2) {
        throw std::invalid_argument("Invalid input: expected two integers");
    }

    // Extract the numerator and denominator from the input string
    std::stringstream ss(buffer);
    int numerator, denominator;

    ss >> numerator >> denominator;

    // Set the fraction's numerator and denominator
    fraction.numerator = numerator;
    fraction.denominator = denominator;

    
    
    // Return the input stream
    return input;
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


    bool Fraction::operator==(const Fraction other)const{

        Fraction one(this->numerator*other.getDenominator() , this->denominator*other.getDenominator());
        Fraction two(other.getNumerator()*this->denominator,other.getDenominator()*this->denominator);

        return (one.getNumerator() == two.getNumerator());
        
    }

    bool Fraction::operator>(const Fraction other)const{
        Fraction one(this->numerator*other.denominator,this->denominator*other.denominator);
        Fraction two(this->denominator*other.numerator,this->denominator*other.denominator);
        return (one.numerator>two.numerator);
    }
    bool Fraction::operator<(const Fraction other)const{
        Fraction one(this->numerator*other.denominator,this->denominator*other.denominator);
        Fraction two(this->denominator*other.numerator,this->denominator*other.denominator);
        return (one.numerator<two.numerator);
    }
    bool Fraction::operator>=(const Fraction other)const{
        Fraction one(this->numerator*other.denominator,this->denominator*other.denominator);
        Fraction two(this->denominator*other.numerator,this->denominator*other.denominator);
        return (one.numerator>=two.numerator);
    }
    bool Fraction::operator<=(const Fraction other)const{
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
        return (Fraction(other)/fraction).GCD();
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
    