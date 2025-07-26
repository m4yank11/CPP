//
//  main.cpp
//  highestFrequencyCharacter
//
//  Created by Mayank Raj Gupta on 14/02/24.
//

#include <iostream>
#include <vector>
using namespace std;

int highestFrequencyCharacter(string str){
    int n = (int)str.length();
    vector<int>a(26,0); //size 26 initialized with 0
    
    //increasing the count of the alphabets that come in the string
    for(int i=0;i<n;i++){
        char ch = str[i];
        int ascii = int(ch);
        a[ascii - 97]++;
    }
    //finding the max
    int max =0;
    char m='\0';
    for(int i=0; i<26;i++){
        if(a[i]>max) {
            max=a[i];
            m = char(i+97);
        }
    }
    cout<<m<<" : ";
    return max;
}

int main(){
    string str = "mayankrajgupta";
    cout<<highestFrequencyCharacter(str)<<endl;
    return 0;
}




