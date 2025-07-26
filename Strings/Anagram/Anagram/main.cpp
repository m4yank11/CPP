//
//  main.cpp
//  Anagram
//
//  Created by Mayank Raj Gupta on 13/02/24.
//

#include <iostream>
using namespace std;

int main(){
    string s1 = "physicswallah";
    string s2 = "wallahphysics";
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2){
        return 1;
    }
    else return 0;
}
