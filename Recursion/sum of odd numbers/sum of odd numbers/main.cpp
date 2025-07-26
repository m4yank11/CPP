//
//  main.cpp
//  sum of odd numbers
//
//  Created by Mayank Raj Gupta on 19/04/24.
//

#include <iostream>
using namespace std;

//Q1
int sumofOdd(int a,int b){
    //if a and b are not odd
    //change the base case
    if(a%2==0){
        a=a+1;
    }
    if(b%2==0){
        if(a==b-1) return b-1;
    }
    else{
        if(a==b) return b;
    }
    return a+sumofOdd(a+2, b);
}

//Q2
int countWays(int n){
    //base cases
    if(n==0 || n==1){
        return 1;
    }
    else if(n==2) return 2;
    return countWays(n-1)+countWays(n-2)+countWays(n-3);
}

//Q3
bool powerof2(int a){
    
    if(a==1) return true;
    else if(a%2!=0) return false;
    return powerof2(a/2);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<sumofOdd(a,b)<<endl;
    int n;
    cout<<"Enter the number of stairs: ";
    cin>>n;
    cout<<countWays(n)<<endl;
    cout<<powerof2(n)<<endl;
    return 0;
}
