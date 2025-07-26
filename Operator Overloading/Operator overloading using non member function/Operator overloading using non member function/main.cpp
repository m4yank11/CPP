//
//  main.cpp
//  Operator overloading using non member function
//
//  Created by Mayank Raj Gupta on 05/10/23.
//  updating imaginary part of complex number

#include <iostream>
using namespace std;

class Complex{
    double real;
    double imag;
public:
    Complex(){
        real = 0;
        imag = 0;
    }
    Complex(int i,int j){
        real = i;
        imag = j;
    }
    
    void print(){
        cout<<real<<" + "<<imag<<"i"<<endl;
    }
    //since using non member function so using friend class
    friend Complex operator+(Complex c, double y);
};

Complex operator+(Complex c, double y){
    Complex temp;
    temp.real = c.real;
    temp.imag = c.imag + y;
    return temp;
}



int main(){
    Complex c1(5, 4);
    Complex c2 = c1 + 3.6;
    c2.print();
    
}
