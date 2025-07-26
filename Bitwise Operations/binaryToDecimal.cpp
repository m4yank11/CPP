#include<iostream>
using namespace std;

int binaryToDecimal(string s){
    int ans = 0;
    int n = s.length();
    for (int i = n-1; i>=0; i--){
        char ch = s[i];
        int num = ch - '0';
        ans += num * (1 << (n-i-1));
    }
    return ans;
}

int main(){
    string str = "00011001";
    cout<< binaryToDecimal(str)<<endl; 
}