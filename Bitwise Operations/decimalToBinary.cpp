#include<iostream>
using namespace std;

string decimalToBinary(int n){
    string binary = "";
    while(n > 0){
        // if(n % 2 == 0){
        //     //even
        //     binary = "0" + binary;
        // } else{
        //     //odd
        //     binary = "1" + binary;
        // }
        // n /= 2;
        // better way
        binary = (to_string(n%2)) + binary;
        //using rightshift
        n = n >> 1;
    }
    return binary;
}
int main(){
    cout<<decimalToBinary(19)<<endl;
}