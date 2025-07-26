//
//  main.cpp
//  Binary Search
//
//  Created by Mayank Raj Gupta on 23/03/24.
//

#include <iostream>
#include <vector>
using namespace std;

void binary_search(vector<int> &v, int target, int low, int high){
    if(low>high){
        cout<<"Target cannot be found "<<endl;
        return;
    }
    
    int mid = (low+high)/2;
    if(target<v[mid]){
        high = mid-1;
        binary_search(v,target,low,high);
    }
    else if(target>v[mid]){
        low = mid+1;
        binary_search(v,target,low,high);
    }
    else if(target==v[mid]){
        cout<< "Target found "<<endl;
       
    }
    
    
}

int main(){
    vector<int> v = {1,2,5,7,12,15,18,20,23,26,29};
    int n= (int)v.size();
    int low=0;
    int high=n-1;
    int target;
    cout<<"Enter the target: ";
    cin>>target;
    binary_search(v,target,low,high);
}
