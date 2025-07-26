//
//  main.cpp
//  Factorial
//
//  Created by Mayank Raj Gupta on 18/04/24.
//

#include <iostream>
using namespace std;

int factorial(int n){
    //base case
    if(n==0) return 1;
    //recursive call
    return n*factorial(n-1);
}

int main(int argc, const char * argv[]) {
    cout<<factorial(5)<<endl;
    return 0;
}
