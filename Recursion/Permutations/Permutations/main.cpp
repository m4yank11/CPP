//
//  main.cpp
//  Permutations
//
//  Created by Mayank Raj Gupta on 31/07/24.
//

#include <iostream>
#include <string>
using namespace std;

void permutations(string ans, string str){
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        string left = str.substr(0,i);
        string right = str.substr(i+1);
        permutations(ans+ch, left+right);
    }
}

int main() {
    string str = "abc";
//    // c ka index hai 2 and length of string is 5
//    string left = str.substr(0,2);
//    string right = str.substr(2+1);
//    cout<<left<<endl;
//    cout<<right<<endl;
    permutations("",str);
    return 0;
}

