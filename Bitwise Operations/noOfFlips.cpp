#include<iostream>
#include<stdlib.h>
using namespace std;
//calulate set bits of xor of the two numbers

int countSetBits(int n){
    int count = 0;
    while(n){
        count++;
        n = n&(n-1);
    }
    return count;
}
int no_of_flips_required(int x, int y){
    int n = x ^ y;
    return countSetBits(n);
}

int main(){
   cout<<no_of_flips_required(15,36)<<endl;
}