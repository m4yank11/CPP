//
//  main.cpp
//  factorial
//
//  Created by Mayank Raj Gupta on 09/08/23.
//

#include <iostream>


using namespace std;

int main(){
    unsigned int num;
    unsigned long fact=1;
    cout<<"Enter the number: ";
    cin>>num;
    for(int i=num; i>0; i--){
        fact*= i;
    }
    cout<<"The factorial of "<<num<< " is "<<fact<<endl;
}
