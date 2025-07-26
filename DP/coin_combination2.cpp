#include<iostream>
#include <vector>
#include<climits>
using namespace std;
#define ll long long
#define mod 1000000007
vector<vector<ll>>dp;

int f(int idx, int x, vector<int>& coins){
    if(x == 0) return 1;
    if(idx == coins.size()) return 0;
    if(dp[idx][x] != -1) return dp[idx][x];
    
    ll nottake = f(idx+1, x, coins) % mod;
    ll take = 0;
    if(x - coins[idx] >= 0){
        take = f(idx, x - coins[idx], coins) % mod;
    }

    return dp[idx][x] = (take + nottake) % mod;
}

int fbu(int x, vector<int>& coins){
    
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    dp.clear();
    dp.resize(n + 1, vector<ll>(x + 1, -1));
    cout<<f(0, x, arr)<<endl;
}