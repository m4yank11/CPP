//
//  main.cpp
//  MostOccuringWord
//
//  Created by Mayank Raj Gupta on 17/02/24.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string str = "Mayank is a talented and motivated young kid. He is persuing computer science and engineering. He has a profound knowledge about DSA";
    stringstream ss(str);
    string temp;
    vector<string> v;
    while(ss>>temp){
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    
    int maxcount=1;
    int count =1;
    string x;
    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1]) count ++;
        else count=1;
        maxcount = max(maxcount,count);
    }
    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1]) count ++;
        else count=1;
        if(count == maxcount){
            cout<<v[i]<<" "<<maxcount<<endl;
        }
    }
}
