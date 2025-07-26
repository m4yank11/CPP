//
//  main.cpp
//  String Assignment 2
//
//  Created by Mayank Raj Gupta on 08/04/24.
//

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void fun(int k){
    static int a=2;
    if(k>1){
        a--;
        k--;
        fun(k);
        cout<<a<<endl;
       
    }
    else return;
}
//Q1
string reversestring(string str){
    string s = str;
    reverse(s.begin(),s.end());
    return str+s;
}
//Q2
int secondlargest(string s){
    int n = (int)s.length();
    int max = INT_MIN;
    int smax = max;
    for(int i=0;i<n;i++){
        int digit = s[i]-'0';
        if (digit > max) {
            //smax = max;
            max = digit;
        }
        else if (digit < max && digit > smax) {
            smax = digit;
        }
    }
    
    return smax;
}
//Q3
int numberofvowelsubstrings(string str){
    //Input : str = "abjkoe"
    //Output : 4
    //Explanation : The possible substrings that only contain vowels are "a" , "o" , "e" , "oe"
    int n = (int)str.length();
    int p = 0;
    int q = p;
    int count = 0;
    for(int i=0;i<n;i++){
        if(str[p]=='a'||str[p]=='e'||str[p]=='i'||str[p]=='o'||str[p]=='u'){
            if(str[q]=='a'||str[q]=='e'||str[q]=='i'||str[q]=='o'||str[q]=='u'){
                count++;
                q++;
            }
            else{
                p++;
                q=p;
            }
        }
    }
    return count;
}
//Q4
bool anagramStrings(string s,string t){
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s==t) return true;
    return false;
}
//Q5
/*string maximumlex(string str){
    stringstream ss(str);
    vector<string>v;
    string temp;
    while(ss>>temp){
        v.push_back(temp);
    }
    for(int i=0;i<v.size();i++){
        
    }
}*/

int main(int argc, const char * argv[]) {
    int k=4;
    fun(k);
    string str="PWSkills";
    cout<<reversestring(str)<<endl;
    string number = "2947578";
    cout<<secondlargest(number)<<endl;
    string vowels = "abjkoe";
    cout<<numberofvowelsubstrings(vowels)<<endl;
    string s="book";
    string t="hook";
    cout<<anagramStrings(s, t)<<endl;
    string sentence;
    getline(cin,sentence);
    
    return 0;
}
