//
//  main.cpp
//  Reverse Part of String
//
//  Created by Mayank Raj Gupta on 13/02/24.
//

#include <iostream>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int len = s.length();
    reverse(s.begin(),s.begin()+ 3);
    cout<<s<<endl;
}
