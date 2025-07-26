//
//  main.cpp
//  a power b
//
//  Created by Mayank Raj Gupta on 18/04/24.
//

#include <iostream>
using namespace std;

//using recursion
int power(int a,int b){
    if(b==0) return 1;
    return a*power(a, b-1);
}
//using iteration
int pow(int a,int b){
    int p=1;
    for(int i=1;i<=b;i++){
        p*=a;
    }
    return p;
}

int main(){
    int a;
    int b;
    cout<<"Enter the base and exponent : ";
    cin>>a>>b;
    cout<<power(a,b)<<endl;
    cout<<pow(b,a)<<endl;
    return 0;
}
