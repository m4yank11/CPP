//
//  main.cpp
//  print substrings of a string
//
//  Created by Mayank Raj Gupta on 26/07/24.
//

#include <iostream>
#include <string.h>
using namespace std;
void printsub(string original, string s){
    if(original.length()==0){
        cout<<s<<endl;
        return;
    }
    char ch = original[0];
    printsub(original.substr(1),s+ch);
    printsub(original.substr(1),s);
}

int main(){
    string str = "abc";
    string s = "";
    printsub(str,s);
}

