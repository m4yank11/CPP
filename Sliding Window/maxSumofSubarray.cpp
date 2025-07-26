#include<iostream>
using namespace std;

//using sliding window
int maxSum(int arr[],int n, int k){
    // first calculate the sum of first window denoted by prev_sum
    int prev_sum = 0;
    for(int i=0;i<k;i++){
        prev_sum += arr[i];
    }
    int max_sum = prev_sum;
    // now we will calulate the sum of remaining windows
    int i = 1;
    int j = k;
    while(j < n){
        prev_sum = prev_sum + arr[j] - arr[i-1];
        max_sum = max(max_sum, prev_sum);
        j++;
        i++;
    }
    return max_sum;
    // TC = O(n)
}

int main(){
    int arr[] = {7,1,4,2,5,6,8,3,9,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int maxsum = INT_MIN;
    for(int i = 0; i<= n-k; i++){
        int sum = 0;
        for(int j= i; j<i+k; j++){
            sum += arr[j];
        }
        maxsum = max(maxsum, sum);
    }
    cout<<maxsum<<endl;
    // TC = O(n*k)
    cout<<maxSum(arr,n,k)<<endl;

    
}