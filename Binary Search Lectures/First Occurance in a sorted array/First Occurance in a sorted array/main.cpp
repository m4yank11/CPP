//
//  main.cpp
//  First Occurance in a sorted array
//
//  Created by Mayank Raj Gupta on 24/03/24.
//

#include <iostream>
#include <vector>
using namespace std;

int firstOccurance(vector<int>&v, int x){
    int n=(int)v.size();
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid]==x){
            if(v[mid-1]==x) hi = mid-1;
            else return mid;
        }
        else if(v[mid]<x) lo = mid+1;
        else if(v[mid]>x) hi = mid-1;
    }
    return -1;
}

int main(){
    vector<int> v = {1,2,2,3,3,3,3,3,4,4,5,5,9};
    int target = 6;
    cout<<"The first occurance of the target given is : "<<firstOccurance(v,target)<<endl;
}

