//
//  main.cpp
//  Operator overloading using member function
//
//  Created by Mayank Raj Gupta on 05/10/23.
//

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
    
    Complex operator -(double x){
        Complex temp;
        temp.real = real - x;
        temp.imag = imag;
        return temp;
    
    }
};

int main(){
    Complex c1(5, 4);
    Complex c2 = c1 - 1.2;
    c2.print();
    
}
