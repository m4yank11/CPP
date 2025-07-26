#include<iostream>
#include<stdlib.h>
using namespace std;

// using bit manipulation
// Brian Kernigham's algorithm to calculate just greater 2*n - 1 number 
// eg 23 - 10111
// just greater number will be 32 ie 100000
// and 32 - 1 is 11111
// performing xor with 23 
// 10111
// 11111
// 01000
// we will get flipped number

int justgreater(int n){
    int x;
    while(n > 0){
        x = n;
        n = n & (n-1);
    }
    return x*2-1;
}

int flip(int n){
    int f = justgreater(n);
    return n ^ f;
}

int main(){
    cout<<flip(23)<<endl;
}