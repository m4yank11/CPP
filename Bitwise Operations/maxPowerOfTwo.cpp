#include<iostream>
#include<stdlib.h>
using namespace std;

//using bit manipulation
// Brian Kernigham's algorithm
int maxPowerOfTwo(int n){
    int temp = 0;
    while(n>0){
        temp = n;
        n = n & (n-1);
    }
    return temp;
}

int main(){
    cout<<maxPowerOfTwo(90)<<endl;
}