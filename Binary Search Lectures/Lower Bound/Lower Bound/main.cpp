//
//  main.cpp
//  Lower Bound
//
//  Created by Mayank Raj Gupta on 24/03/24.
//

#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int>&v, int x){
    int n=(int)v.size();
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid]==x){
            return v[mid-1];
            break;
        }
        else if(v[mid]<x) lo = mid+1;
        else if(v[mid]>x) hi = mid-1;
    }
    return v[hi];
}

int main(){
    vector<int> v = {1,2,4,5,9,15,18,21,24 };
    int target = 12;
    cout<<"The lower bound of the target given is : "<<lowerBound(v,target)<<endl;
}
