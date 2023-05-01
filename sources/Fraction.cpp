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
        else{
            throw std::invalid_argument("Error: Denominator equals 0");
        }
    }

    int Fraction::getNumerator(){
        return this->numerator;
    }
    int Fraction::getDenominator(){
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



    // std::istream& operator>>(std::istream& input, Fraction& fraction) {
//     // Read the input stream as a string
//     std::string fractionString;
//     input >> fractionString;

//     // Split the input string by the '/' character
//     std::istringstream fractionStream(fractionString);
//     std::string numeratorStr, denominatorStr;
//     std::getline(fractionStream, numeratorStr, '/');
//     std::getline(fractionStream, denominatorStr);

//     // Parse the numerator and denominator as integers
//     int numerator, denominator;
//     try {
//         numerator = std::stoi(numeratorStr);
//         denominator = std::stoi(denominatorStr);
//     } catch (std::invalid_argument& e) {
//         // Throw an exception if the input cannot be parsed as integers
//         throw std::invalid_argument("Invalid input format");
//     }

//     // Update the fraction object with the parsed numerator and denominator
//     if (denominator != 0) {
//         fraction.numerator = numerator;
//         fraction.denominator = denominator;
//     } else {
//         throw std::invalid_argument("Denominator cannot be zero");
//     }

//     return input;
// }

//     std::istringstream& operator>>(std::istringstream& input, Fraction& fraction){
    
//     int numerator = 0;
//     int denominator = 1;

//     // Read the input string into a buffer
//     std::string buffer;
//     input >> buffer;

//     // Search for the '/' character
//     size_t slashPos = buffer.find('/');
//     if (slashPos == std::string::npos) {
//         // If the slash character is not found, treat the whole input string as the numerator
//         numerator = std::stoi(buffer);
//     } else {
//         // Extract the numerator and denominator from the input string
//         numerator = std::stoi(buffer.substr(0, slashPos));
//         denominator = std::stoi(buffer.substr(slashPos + 1));
//     }

//     // Set the fraction's numerator and denominator
//     fraction.numerator = numerator;
//     fraction.denominator = denominator;

//     // Return the input stream
//     return input;
// }

std::istringstream& operator>>(std::istringstream& input, Fraction& fraction) {

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

    bool Fraction::operator==(Fraction other){
        Fraction a=Fraction(this->numerator,this->denominator).GCD();
        Fraction b=Fraction(other.getNumerator(),other.getDenominator()).GCD();
        return(a.getNumerator()==b.getNumerator() && a.getDenominator()==b.getDenominator());
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
        return (Fraction(other)/fraction).GCD();
    }
    bool operator==(float other, Fraction fraction){
        return (fraction==Fraction(other));
    }
    bool operator>(float other, Fraction fraction){
        return (fraction<Fraction(other));
    }
    bool operator<(float other, Fraction fraction){
        return (fraction>Fraction(other));
    }
    bool operator>=(float other, Fraction fraction){
        return (fraction<=Fraction(other));
    }
    bool operator<=(float other, Fraction fraction){
        return (fraction>=Fraction(other));
    }

    // Other functions
    Fraction Fraction::GCD(){
        int gcd = std::gcd(numerator,denominator);
        return Fraction(numerator/gcd,denominator/gcd);
    }
}
    