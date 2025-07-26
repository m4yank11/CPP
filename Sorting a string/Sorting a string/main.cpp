//
//  main.cpp
//  Sorting a string
//
//  Created by Mayank Raj Gupta on 27/01/24.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    sort(s.begin(),s.end());
    cout<<s<<endl;
    
}
