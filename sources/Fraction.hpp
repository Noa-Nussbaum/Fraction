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
    
        int numerator;
        int denominator;

    // Constructor
        Fraction(const int& numerator, const int& denominator);

    // Fraction and float
        Fraction(const float& one);

    // Fraction to fraction
        Fraction operator+(Fraction other);
        Fraction operator-(Fraction other);
        Fraction operator*(Fraction other);
        Fraction operator/(Fraction other);
        bool operator==(Fraction other);
        bool operator>(Fraction other);
        bool operator<(Fraction other);
        bool operator>=(Fraction other);
        bool operator<=(Fraction other);
        Fraction operator++();
        Fraction operator--();
        Fraction operator++(int);
        Fraction operator--(int);



    // Float to fraction
        friend Fraction operator+(float other, Fraction fraction);
        friend Fraction operator-(float other, Fraction fraction);
        friend Fraction operator*(float other, Fraction fraction);
        friend Fraction operator/(float other, Fraction fraction);
        friend bool operator==(float other, Fraction fraction);
        friend bool operator>(float other, Fraction fraction);
        friend bool operator<(float other, Fraction fraction);
        friend bool operator>=(float other, Fraction fraction);
        friend bool operator<=(float other, Fraction fraction);


    // io
        friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);
        friend std::ostream& operator>>(std::ostream& os, const Fraction& obj);

    // Others
        Fraction GCD();

    };
    
    }
