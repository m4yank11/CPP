//
//  main.cpp
//  Different neighbouring elements in a string
//
//  Created by Mayank Raj Gupta on 13/02/24.
//

#include <iostream>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    cout<<s<<endl;
    int count = 0;
    int n = (int)s.size();
    for(int i=0;i<n;i++){
        if(n==1){ cout<<0<<endl; break;}
        if(i==0){
            if(s[i]!=s[i+1]) count++;
        }
        else if(i==n-1){
            if(s[i]!=s[i-1]) count++;
        }
        else if(s[i]!=s[i-1] && s[i]!=s[i+1]) count++;
        
    }
    cout<<count<<endl;
}
