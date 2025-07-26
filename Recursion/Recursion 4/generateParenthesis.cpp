#include<iostream>
#include <vector>
#include <string>
using namespace std;

void generate(int n, string s, int o, int c){
    // hint : at any given instance the number of closing brackets will never be more than number of 
    // opening brackets
    if(c==0){
        cout<<s<<endl;
        return;
    }
    if(o>0){
        generate(n,s+"(",o-1,c);
    }
    if(c>o){
        generate(n,s+")",o,c-1);
    }
}

int main(){
    int n = 3;
    int open = n;  // no of opening brackets
    int close = n;  // no of closing brackets
    generate(n," ",open,close);
}