//
//  main.cpp
//  Max value in array(mast)
//
//  Created by Mayank Raj Gupta on 11/07/24.
//

#include <iostream>
#include <vector>
using namespace std;

int printMax(int n, int arr[],int idx){
    if(idx == n) return INT_MIN;
    return max(arr[idx],printMax(n, arr, idx+1));
}

int main(){
    int arr[] = {2,4,1,6,3,1,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<printMax(n,arr,0)<<endl;
    return 0;
}
