#include<iostream>
#include <vector>
#include<climits>
using namespace std;
#define ll long long
#define mod 1000000007
vector<int>dp;

int f(int n, int x, vector<int>&arr){
    if(x == 0) return 1;
    if(dp[x] != -1) return dp[x];
    ll sum = 0;
    for(int i = 0 ; i < n ; i++){
        if(x - arr[i] < 0) continue;
        sum = (sum + (f(n, x - arr[i], arr) % mod)) % mod;
    }
    return dp[x] =  sum % mod;
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    dp.clear();
    dp.resize(x+1, -1);
    cout<<f(n, x, arr)<<endl;
}