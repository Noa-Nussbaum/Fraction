/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    // Fraction a(5,3), b(14,21);
    Fraction c{1, 3}; 
    Fraction a(1, 2);
    Fraction b(1, 4);
    cout << c+ 4.321 <<endl;
    Fraction res(c+ 4.321);
    cout << res <<endl;
    Fraction fl(4.654);
    cout << fl <<endl;
    bool equal = c+ 4.321==4.654;  
    cout << "c==4.654: " << equal << endl; 
    
    bool m = b < a;
    cout << "b<a: "<<m << endl;
    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b " << a+b << endl; 
    cout << "a-b " << a-b << endl; 
    cout << "a/b " << a/b << endl; 
    cout << "a*b " << a*b << endl;
    // bool equal = a==b;  
    bool left = a>b;
    bool right = a<b;
    cout << "a==b " << equal << endl; 
    cout << "a>b " << left << endl; 
    cout << "a<b " << right << endl; 
    bool leftE = a>=b;
    bool rightE = a<=b;
    cout << "a>=b " << leftE << endl; 
    cout << "a<=b " << rightE << endl; 
    cout << "2.3*b " << 2.3*b << endl; 
    cout << "a+2.421 " << a+2.421 << endl; 
    // Fraction c = a+b-1;
    // cout << c << endl;
    // cout << ++c << endl;
    // cout << c-- << endl;
    // cout << c++ << endl;
    // cout << --c << endl;
    // Fraction d(2.3);
    // cout << "Did it work? " <<d<<endl;
    // cout << (2.3==d) << endl;

    // Fraction a(1, 2), b(3, 4);
    ostringstream os;

    istringstream is("5 6"); // Could also be "5,6" for ex
    // std::istringstream is("5/6");
    istringstream bad_is("7");

    // // Test operator>>
    is >> b;

    cout << b<<endl;

    // b.getNumerator() == 5;
    // b.getDenominator() == 6;
    // CHECK_THROWS(bad_is >> b); // Throws cuz the input is one number

    // cout << "c >=b ? : " << (c >= b) << endl;
    // if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    // else cout << " a is smaller than 1.1" << endl;


}