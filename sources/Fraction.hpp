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
    
        int nominator;
        int denominator;

        Fraction(int nominator, int denominator);

    // fraction and float
        Fraction(float one);

    // fraction to fraction
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



    // float to fraction
        friend Fraction operator+(float other, Fraction fraction);
        friend Fraction operator-(float other, Fraction fraction);
        friend Fraction operator*(float other, Fraction fraction);
        friend Fraction operator/(float other, Fraction fraction);
        friend bool operator==(float other, Fraction fraction);
        friend bool operator>(float other, Fraction fraction);
        friend bool operator<(float other, Fraction fraction);
        friend bool operator>=(float other, Fraction fraction);
        friend bool operator<=(float other, Fraction fraction);


    //io
        friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);
        friend std::ostream& operator>>(std::ostream& os, const Fraction& obj);

    };
    
    }
