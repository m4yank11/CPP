//
//  main.cpp
//  BS assignment 1
//
//  Created by Mayank Raj Gupta on 24/03/24.
//

#include <iostream>
#include <vector>
using namespace std;

//Q1
int lastOccurence(vector<int>&v, int x){
    int n= (int)v.size();
    int lo = 0;
    int hi = n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid]==x){
            if(v[mid+1]==x){
                lo = mid+1;
            }
            else return mid;
        }
        else if(v[mid]>x) hi = mid-1;
        else lo = mid+1;
    }
    return -1;
}

//Q2
int countOnes(vector<int>&v){
    int count = 0;
    int n= (int)v.size();
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid= lo+(hi-lo)/2;
        if(v[mid]==1){
            count+=hi-mid+1;
            hi=mid-1;
            
        }
        else lo=mid+1;
    }
    return count;
}

//Q3
int maxOnes(vector<vector<int>>&nums){
    int maxcount = 0;
    int sol = -1;
    int rows = (int)nums.size();
    for(int i=0;i<rows;i++){
        if(countOnes(nums[i])>maxcount){
            //maxcount= countOnes(nums[i]);
            sol=i;
        }
    }
    return sol;
}

//Q4
int duplicate(vector<int>&v){
    int n=(int)v.size();
    int lo=0;
    int hi=n-1;
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        //count the number of elements before mid
        int count = 0;
        for(int i:v){
            if(i<=mid) count++;
        }
        //if the count is greater than mid then the duplicate element is present in left side of mid as elements start from 1
        if(count>mid) hi =mid;
        else lo=mid+1;
    }
    return v[lo];
}

//Q5
bool pfsq(int n){
    int lo=0;
    int hi=n;
    while(lo<=hi){
        long long mid= lo + (hi-lo)/2;
        if(mid*mid==n){
            return true;
            break;
        }
        else if (mid*mid<n) lo=(int)mid+1;
        else hi=(int)mid-1;
    }
    return false;
}


int main(){
    //q1
    vector<int>v1= {1,2,3,3,4,4,4,5};
    int target = 4;
    cout<<lastOccurence(v1, target)<<endl;
    //q2
    vector<int>v2= {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1};
    cout<<countOnes(v2)<<endl;
    //q3
    vector<vector<int>>v3={{0,1,1,1},
        {0,0,1,1},
        {1,1,1,1},
        {0,0,0,0}};
    cout<<"Row with maximum number of 1's is: "<<maxOnes(v3)<<endl;
    //q4
    vector<int>v4= {1,2,3,3,4,5};
    cout<<"Duplicated element is: "<<duplicate(v4)<<endl;
    
    //q5
    int num=45;
    cout<<pfsq(num)<<endl;
}
