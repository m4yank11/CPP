//
//  main.cpp
//  LastIndex
//
//  Created by Mayank Raj Gupta on 19/12/23.
//

#include <iostream>
#include <vector>
using namespace std;

// print the last index of the occurance of a number
//since last index is to be known so we'll start the loop from last

int main(){
    vector<int> v;
    v.push_back(9);
    v.push_back(5);
    v.push_back(3);
    v.push_back(1);
    v.push_back(5);
    v.push_back(2);
    v.push_back(3);
    v.push_back(9);
    v.push_back(6);
    v.push_back(1);
    int idx=-1;
    for (int i= v.size() ; i>0 ; i--){
        if(v[i]==9)  idx=i;
        break;
    }
    cout<<idx+1<<endl;
}
