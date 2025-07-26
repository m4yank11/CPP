#include<iostream>
#include <vector>
using namespace std;

int printIndex(vector<int>&v,int idx,int x){
    if(idx == v.size()){
        return -1;
    }
    if(v[idx]==x) return idx;
    return printIndex(v,idx+1,x);
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){cin>>v[i];}
    cout<<printIndex(v,0,3)<<endl;  

}