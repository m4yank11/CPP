#include <iostream>
using namespace std;

int main(){
    // brute force approach 
    // TC -> O(n*k)
    int arr[] = {2,-3,4,4,-7,-1,4,-2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int ans[n-k+1];
    // for(int i = 0; i < n-k+1 ; i++){
    //     for(int j = i ; j < i + k ; j++){
    //         if(arr[j] < 0){
    //             ans[i] = arr[j];
    //             break;
    //         }
    //     }
    // }
    // for(int i = 0 ; i < n-k+1 ; i++){
    //     cout<<ans[i]<<" ";
    // }
    // sliding window approach
    // TC -> O(n)
    int i = 0, prev_neg = 0;
    // negative in the first window
    for(i = 0; i < k ; i++){
        if(arr[i] < 0){
            prev_neg = i;
            break;
        }
    }
    ans[0] = arr[prev_neg];
    i = 1;
    int j = k;
    while(j < n){
        // if prev_neg is still present in the current window then it will be the answer
        if(prev_neg > i) ans[i] = arr[prev_neg];
        else{
            for(prev_neg = i ; prev_neg <= j ; prev_neg++){
                if(arr[prev_neg] < 0){
                    ans[i] = arr[prev_neg];
                    break;
                }
            }
        }
        i++, j++;
    }
    for(int i = 0 ; i < n-k+1; i++){
        cout<< ans[i]<<" ";
    }


}