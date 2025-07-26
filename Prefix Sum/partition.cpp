#include<iostream>
#include<vector>
using namespace std;

bool checkPartition(vector<int> & arr){
    int n = arr.size();
    //convert it into prefix sum
    for(int i = 1; i<n ; i++){
        arr[i] = arr[i] + arr[i-1];
    }
    //checking
    for(int i = 0 ; i<n ; i++){
        if(2*arr[i]==arr[n-1]) return true;
    }
    return false;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(10);
    arr.push_back(2);
    cout<<checkPartition(arr)<<endl;
}