#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sub(vector<int>& a, vector<int>& ans, vector<vector<int> > & result, int idx){
    if(idx == a.size()){
        result.push_back(ans);
        return;
    }
    sub(a, ans, result, idx+1);
    if(ans.size()<1 || a[idx]-ans[ans.size()-1]==1){
        ans.push_back(a[idx]);
        sub(a, ans, result, idx+1);
        ans.pop_back();
    }
    
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int> ans;
    vector<vector<int> > result;
    sub(a,ans,result,0);
    sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}