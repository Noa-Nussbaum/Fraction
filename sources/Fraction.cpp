#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <numeric>
#include <cstdlib>

namespace ariel{

    // For the overflow function
    const double max = std::numeric_limits<int>::max();
    const double min = std::numeric_limits<int>::min();


    // Constructors
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
        float hold = (float)numerator/denominator;
        value = std::round(hold*1000.0)/1000.0;
    }

    // Default constructor
    Fraction::Fraction(): numerator(0), denominator(1) {}

    int Fraction::getNumerator() const{
        return this->numerator;
    }
    int Fraction::getDenominator() const{
        return this->denominator;
    }

    // Constructor
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
    throw std::runtime_error("Error: runtime error");
    else if (denominator==0)
        throw std::runtime_error("Error: runtime error");

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
        // Math rules
        int numerator1 = this->numerator*other.denominator;
        int numerator2 = this->denominator*other.numerator;
        // Check there's no overflow
        if(overFlow(Fraction(this->numerator,this->denominator),other)){
            throw std::overflow_error("Error: OverFlow");
        }
        else{
            return Fraction(numerator1+numerator2,this->denominator*other.denominator);
        }
    }

    Fraction Fraction::operator-(Fraction other){
        // Math rules
        int numerator1 = this->numerator*other.denominator;
        int numerator2 = this->denominator*other.numerator;
        // Check there's no overflow
        if(overFlow(Fraction(this->numerator,this->denominator),other)){
            throw std::overflow_error("Error: OverFlow");
        }
        else{
        return Fraction(numerator1-numerator2,this->denominator*other.denominator);
        }
    }
    Fraction Fraction::operator*(Fraction other){
        // Math rules
        // Check there's no overflow
        if(overFlow(Fraction(this->numerator,this->denominator),other)){
            throw std::overflow_error("Error: OverFlow");
        }
        else{
            return Fraction(this->numerator*other.numerator,this->denominator*other.denominator);

        }
    }

    Fraction Fraction::operator/(Fraction other){
        // Math rules
        // Check there's no overflow or division by zero
        if(other.getNumerator()==0){
            throw std::runtime_error("Error: Denominator equals 0");
        }
        if(overFlow(Fraction(this->numerator,this->denominator),other)){
            throw std::overflow_error("Error: OverFlow");
        }
        else{
            return Fraction(this->numerator*other.denominator,this->denominator*other.numerator);
        }
    }

    // Convert fraction to float for comparison
    float Fraction::fractionToFloat(const Fraction fraction)const{
        int waitup =  (float)(fraction.getNumerator()*1000.0/fraction.getDenominator());
        // Convert to int and then back to float so we keep only 3 points past the dot
        float tempo = waitup/1000.0;
        return tempo;
    }

    bool Fraction::operator==(const Fraction other)const{
        // Compare numerator and denominator
        Fraction temp(this->numerator,this->denominator);
        // Compare float values
        return (this->numerator==other.getNumerator() && this->denominator == other.getDenominator())
        || (fractionToFloat(temp) == fractionToFloat(other));
    }

    bool Fraction::operator>(const Fraction other)const{
        // Math rules
        int one = this->numerator*other.denominator;
        int two = this->denominator*other.numerator;
        return (one>two);
    }
    bool Fraction::operator<(const Fraction other)const{
        // Math rules
        int one = this->numerator*other.denominator;
        int two = this->denominator*other.numerator;
        return (one<two);
    }
    bool Fraction::operator>=(const Fraction other)const{
        // Math rules
        int one = this->numerator*other.denominator;
        int two = this->denominator*other.numerator;
        return (one>=two);
    }
    bool Fraction::operator<=(const Fraction other)const{
        // Math rules
        int one = this->numerator*other.denominator;
        int two = this->denominator*other.numerator;
        return (one<=two);
    }
    Fraction Fraction::operator++(){
        // increase and return actual
        *this = *this+Fraction(1,1);
        return *this;
    }
    Fraction Fraction::operator--(){
        // decrease and return actual
        *this = *this-Fraction(1,1);
        return *this;
    }
    Fraction Fraction::operator++(int){
        // increase and return copy
        Fraction copy = *this;
        ++*this;
        return copy;
    }
    Fraction Fraction::operator--(int){
        // decrease and return copy
        Fraction copy = *this;
        --*this;
        return copy;
    }

    // float to fraction
    // Because we implemented the fraction ones, we used them here
    Fraction operator+(float other, Fraction fraction){
            return (fraction+Fraction(other));
    }
    Fraction operator-(float other, Fraction fraction){
        return ((fraction)*(-1)+Fraction(other));
    }
    Fraction operator*(float other, Fraction fraction){
        return (fraction*Fraction(other));
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
        // Greatest common divisor function
        int gcd = std::gcd(numerator,denominator);
        return Fraction(numerator/gcd,denominator/gcd);
    }

    // Check the values aren't greater than the maximum or smaller than the minimum
    bool Fraction::overFlow(Fraction one, Fraction two) {
    // Check the values
    double numerator = static_cast<double>(one.getNumerator()) * static_cast<double>(two.getNumerator());
    double denumerator = static_cast<double>(one.getDenominator()) * static_cast<double>(two.getDenominator());
    if (numerator > max || numerator < min || denumerator > max || denumerator < min) {
        return true;
    }
    return false;
    }

    

}
    