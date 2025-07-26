//
//  main.cpp
//  Operator overloading
//
//  Created by Mayank Raj Gupta on 05/10/23.
//

#include <iostream>
using namespace std;

class Complex{
    int real, imag;
public:
    //default constructor with defined values as 0
    Complex(){
        real =0;
        imag =0;
    }
    //parameterised constructor
    Complex(int x,int y){
        real =x;
        imag =y;
    }
    //operator overloading
    Complex operator +(Complex c){
        Complex temp;
        temp.real = this->real + c.real;
        temp.imag = this->imag + c.imag;
        return temp;
    }
    // using friend function
    friend Complex operator -(Complex c1, Complex c2);
    
    void print(){
        cout<<real<<"+"<<imag<<"i"<<endl;
    }

};

Complex operator -(Complex c1, Complex c2){
    Complex temp;
    temp.real =c1.real - c2.real ;
    temp.imag =c1.imag - c2.imag ;
    return temp;
}



int main(){
    Complex c1(3,5);
    Complex c2(2,3);
    Complex c3;
    c3 = c1+c2;
    c3.print();
    c3 = c1-c2;
    c3.print();
}
