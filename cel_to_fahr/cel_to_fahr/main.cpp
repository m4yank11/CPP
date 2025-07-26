//
//  main.cpp
//  cel_to_fahr
//
//  Created by Mayank Raj Gupta on 05/08/23.
//

#include <iostream>
using namespace std;

int main(){
    int temp;
    cout<<"Enter the temperature in celsius: \n";
    cin>> temp;
    int ftemp=(9*temp+160)/5;
    cout<< ftemp <<endl;
    return 0;
}
