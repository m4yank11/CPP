//
//  main.cpp
//  Minimum value in array
//
//  Created by Mayank Raj Gupta on 01/08/24.
//

#include <iostream>
#include <vector>
using namespace std;

void minValue(vector<int>&v, int idx,int minVal,int n){
    if(idx==n){
        cout<<minVal<<endl;
        return;
    }
    if(v[idx]<minVal){
        minVal = v[idx];
    }
    minValue(v,idx+1,minVal,n);
}

int main(){
    vector<int> v = {11,3,5,2,7,4,9,3};
    int n = (int)v.size();
    int minVal = INT_MAX;
    minValue(v,0,minVal,n);
}
