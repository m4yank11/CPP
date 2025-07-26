#include<iostream>
#include<stdlib.h>
using namespace std;

//method 1 
//using iterative method
//method 2
//using recursive method
//method 3
// using built in function
// int count(int n){
//     return __builtin_popcount(n)<<endl;
// }
// method 4
//using bit manipulation
// Brian Kernigham's algorithm
int countSetBits(int n){
    int count =0;
    while(n>0){
        count ++;
        n = n & (n-1);
    }
    return count;
}

int main(){
    cout<<countSetBits(22)<<endl;
}