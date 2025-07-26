//
//  main.cpp
//  BS Assignment 2
//
//  Created by Mayank Raj Gupta on 01/04/24.
//

#include <iostream>
#include <vector>
using namespace std;

//Q1
bool binarysearch(vector<int>&nums,int lo,int hi, int target){
    int idx = -1;
    while(lo<=hi){
        int mid =(hi+lo)/2;
        if(nums[mid]== target) return true;
        else if(nums[mid]>target) lo=mid+1;
        else hi=mid-1;
    }
    return false;
}

//Q2
int bsinfinte(vector<int>&nums, int target){
    int lo = 0;
    int hi = 100;
    while(hi<nums.size() && target>nums[hi]){
        lo= hi;
        hi = hi*2;
    }
    int idx=binarysearch(nums,lo,hi,target);
    return idx;
}

//Q3
bool matrixbs(vector<vector<int>>&matrix, int target){
    int lo=0,k=0;
    int hi=(int)matrix[k].size()-1;
    while(target>matrix[k][hi] && k<=matrix.size()){
        lo=hi+1;
        k++;
        hi=(int)matrix[k].size()-1;
    }
    bool flag = binarysearch(matrix[k], lo, hi, target);
    return flag;
}

int main() {
    //Q1
   /* vector<int>nums = {15,13,11,10,8,6,5,3,1,0};
    cout<<binarysearch(nums,0,int(nums.size())-1, 4)<<endl;
    //Q2
    vector<int>arr ;
    for(int i=0;i<10000;i++){
        arr.push_back(i);
    }
    cout<<bsinfinte(arr,100000)<<endl;*/
    //Q3
    vector<vector<int>>matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<matrixbs(matrix,3)<<endl;
    return 0;
}

