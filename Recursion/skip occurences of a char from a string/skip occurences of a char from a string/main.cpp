//
//  main.cpp
//  skip occurences of a char from a string
//
//  Created by Mayank Raj Gupta on 11/07/24.
//

#include <iostream>
using namespace std;
//my way
string skipOccurences(string str, string s,int idx){
    if(idx == str.size()) return s; // base case
    if(str[idx]!='a') s+=str[idx];
    return skipOccurences(str, s, idx+1);
}
int main(){
    // we have to skip all occurences of 'a'
    string str = "Mayank Raj Gupta";
    string s = "";
    //for loop way
//    for(int i=0;i<str.size();i++){
//        if(str[i]!='a') s+=str[i];
//    }
    cout<<skipOccurences(str, s, 0)<<endl;
    return 0;
}
