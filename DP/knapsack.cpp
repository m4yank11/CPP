#include<iostream>
#include<vector>
using namespace std;



vector<vector<int>>dp;
int f(int idx, int W, vector<int> &val, vector<int> &wt){
    if(idx == val.size()) return 0;
    if(dp[idx][W] != -1) return dp[idx][W];
    int notpick = f(idx + 1, W, val, wt);
    int pick = INT_MIN;
    if(W - wt[idx] >=0){
        pick = val[idx] + f(idx + 1, W - wt[idx], val, wt);
    }
    return dp[idx][W] = max(pick, notpick);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> wt(n);
        vector<int> val(n);
        for(int i = 0 ; i < n ; i++){
            cin>>wt[i];
        }
        for(int i = 0 ; i < n ; i++){
            cin>>val[i];
        }

        int W;
        cin>>W;

        dp.clear();
        dp.resize(val.size() + 1, vector<int>(W + 1, -1));
        cout<< f(0, W, val, wt)<<endl;
    }
}



