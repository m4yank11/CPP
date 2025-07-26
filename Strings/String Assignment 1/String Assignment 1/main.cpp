//
//  main.cpp
//  String Assignment 1
//
//  Created by Mayank Raj Gupta on 08/04/24.
//

#include <iostream>
#include <vector>
using namespace std;

//Q1
string updateOdd(string s){
    int n= (int)s.length();
    for(int i=0;i<n;i++){
        if(i%2!=0) s[i]='#';
    }
    return s;
}
//Q2
int countConsonants(string s){
    int count =0;
    int n= (int)s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='a' ||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') continue;
        else count++;
    }
    return count;
}
//Q3
bool palindrome(string s){
    int n= (int)s.length();
    int lo= s[0];
    int hi= s[n-1];
    while(lo<=hi){
        if(lo==hi){
            lo++;
            hi--;
        }
        else return false;
    }
    return true;
}
//Q4
string reverseSecond(string s){
    int n = (int)s.length();
    reverse(s.begin()+n/2,s.end());
    return s;
}
//Q5
int conversion(string s){
    int n =(int)s.length();
    int ans=0;
    int product=1;
    for(int i=n-1;i>=0;i--){
        ans+=(s[i]-'0')*product;
        product*=10;
    }
    return ans;
}

int main() {
    string str = "Pbwcshkuiglhlds";
    cout<<updateOdd(str)<<endl;
    string input = "abcd";
    cout<<countConsonants(input)<<endl;
    string p = "abcdcba";
    cout<<palindrome(p)<<endl;
    string rev ="abcdefgh";
    cout<<reverseSecond(rev)<<endl;
    string num = "3244";
    cout<<conversion(num)<<endl;
    return 0;
}
