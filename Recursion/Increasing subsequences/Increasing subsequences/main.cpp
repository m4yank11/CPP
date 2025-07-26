//
//  main.cpp
//  Increasing subsequences
//
//  Created by Mayank Raj Gupta on 30/07/24.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void incSub(int arr[],vector<int>ans,int n,int idx,int k){
    if(idx==n){
        if(ans.size()==k){
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    incSub(arr, ans, n, idx+1, k);
    ans.push_back(arr[idx]);
    incSub(arr, ans, n, idx+1, k);
}

int main() {
    int arr[] = {1,2,3,4,5};
    vector<int>ans;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    incSub(arr, ans, n, 0, k);
    return 0;
}
