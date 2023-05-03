#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <numeric>
#include <cstdlib>

namespace ariel{

    const double max_val = std::numeric_limits<int>::max();
    const double min_val = std::numeric_limits<int>::min();


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
        int numerator1 = this->numerator*other.denominator;
        int numerator2 = this->denominator*other.numerator;
        if(overFlow(Fraction(this->numerator,this->denominator),other)){
            throw std::overflow_error("Error: OverFlow");
        }
        else{
            return Fraction(numerator1+numerator2,this->denominator*other.denominator);
        }
    }
    Fraction Fraction::operator-(Fraction other){
        int numerator1 = this->numerator*other.denominator;
        int numerator2 = this->denominator*other.numerator;
        if(overFlow(Fraction(this->numerator,this->denominator),other)){
            throw std::overflow_error("Error: OverFlow");
        }
        else{
        return Fraction(numerator1-numerator2,this->denominator*other.denominator);
        }
    }
    Fraction Fraction::operator*(Fraction other){
        if(overFlow(Fraction(this->numerator,this->denominator),other)){
            throw std::overflow_error("Error: OverFlow");
        }
        else{
            return Fraction(this->numerator*other.numerator,this->denominator*other.denominator);

        }
    }

    Fraction Fraction::operator/(Fraction other){
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

    float Fraction::fractionToFloat(const Fraction fraction)const{
        int waitup =  (float)(fraction.getNumerator()*1000.0/fraction.getDenominator());
        cout << " wait " << waitup << endl;
        float tempo = waitup/1000.0;
        return tempo;
        // cout << "Now it's this " << tempo<<endl;
        // return (float)(fraction.getNumerator()*1000.0/fraction.getDenominator())/1000.0;
    }
    bool Fraction::operator==(const Fraction other)const{
        // return(this->value==other.value);
        // cout <<"other: "<< other.numerator<<"/"<<other.denominator<< endl;
        // float one = (float)(other.numerator*1000.0/other.denominator)/1000.0;
        // float two = (float)(this->numerator*1000.0/this->denominator)/1000.0;
        // float dif = (float)abs(one-two);
        // cout << "one " << one<< ", two " << two << endl;
        // cout << "The dif is " << dif <<endl;
        // return (dif<0.001);
        Fraction temp(this->numerator,this->denominator);
        cout << "temp = " << temp << endl;
        cout <<fractionToFloat(temp) << endl;
        if(fractionToFloat(temp) == fractionToFloat(other)){
            return true;
        }
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
        int gcd = std::gcd(numerator,denominator);
        return Fraction(numerator/gcd,denominator/gcd);
    }

    bool Fraction::overFlow(Fraction one, Fraction two) {
    

    double num_product = static_cast<double>(one.getNumerator()) * static_cast<double>(two.getNumerator());
    double den_product = static_cast<double>(one.getDenominator()) * static_cast<double>(two.getDenominator());
    
    if (num_product > max_val || num_product < min_val || den_product > max_val || den_product < min_val) {
        return true;
    }
    
    return false;
    }

    

}
    