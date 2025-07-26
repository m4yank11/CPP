//
//  main.cpp
//  Array Printing
//
//  Created by Mayank Raj Gupta on 11/07/24.
//

#include <iostream>
using namespace std;
void display(int n , int arr[], int idx){
    if(idx == n) return;
    cout<<arr[idx]<<" ";
    display(n, arr, idx+1);
}
int main(){
    int arr[] = {2,4,1,6,3,1,7,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    display(n,arr,0);
    return 0;
}
