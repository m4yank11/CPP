#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,4,1,5,2,4,2};
    int n = 7;
    int res = 0;
    for(int i = 0 ; i < n ; i++){
        res = res ^ arr[i];
    }
    cout<<res<<endl;
}