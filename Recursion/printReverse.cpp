#include<iostream>
#include <vector>
using namespace std;

void printReverse(vector<int>&v,int idx){
    if(idx==v.size()){
        return;
    }
    printReverse(v,idx+1);
    cout<<v[idx]<<" ";
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){cin>>v[i];}
    printReverse(v,0);
}