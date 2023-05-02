#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

namespace ariel{

class Fraction{

    public:
    

    // Constructor
        Fraction(const int& numerator, const int& denominator);
        Fraction();
        int getNumerator() const;
        int getDenominator() const;
        

    // Fraction and float
        Fraction(const float& one);

    // Fraction to fraction
        Fraction operator+(Fraction other);
        Fraction operator-(Fraction other);
        Fraction operator*(Fraction other);
        Fraction operator/(Fraction other);
        bool operator==(const Fraction other)const;
        bool operator>(const Fraction other)const;
        bool operator<(const Fraction other)const;
        bool operator>=(const Fraction other)const;
        bool operator<=(const Fraction other)const;
        Fraction operator++();
        Fraction operator--();
        Fraction operator++(int);
        Fraction operator--(int);


    // Float to fraction
        friend Fraction operator+(float other, Fraction fraction);
        friend Fraction operator-(float other, Fraction fraction);
        friend Fraction operator*(float other, Fraction fraction);
        friend Fraction operator/(float other, Fraction fraction);
        friend bool operator==(const float other, Fraction fraction);
        friend bool operator>(const float other, Fraction fraction);
        friend bool operator<(const float other, Fraction fraction);
        friend bool operator>=(const float other, Fraction fraction);
        friend bool operator<=(const float other, Fraction fraction);


    // io
        friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);
        friend std::istream& operator>>(std::istream& os, Fraction& obj) ;
        // friend std::stringstream& operator>>(std::stringstream& input, Fraction& fraction);

    // Others
        Fraction GCD();

        private:
            int numerator;
            int denominator;
            float value;

    };
    
    }
