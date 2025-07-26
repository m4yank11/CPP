#include<iostream>
#include <vector>
using namespace std;

int sum(int v[],int n,int idx,int ans){
    if(idx==n){
        return ans;
    }
    ans+=v[idx];
    return sum(v,n,idx+1,ans);
}

int main(){
    int v[] = {1,5,2,5};
    int n = sizeof(v)/sizeof(v[0]);
    int ans = 0;
    cout<<sum(v,n,0,ans)<<endl;
}