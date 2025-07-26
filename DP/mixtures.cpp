#include<iostream>
#include <vector>
using namespace std;

vector<vector<int>>dp;

int sum(int i, int j, vector<int>& arr) {
    int s = 0;
    for(int x=i; x<=j; x++) s = (s + arr[x]) % 100;
    return s;
}

int f(int i, int j, vector<int>& arr){
    if(i == j) return dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    for(int k = i ; k < j ; k++){
        mini = min(mini, f(i, k, arr) + f(k+1, j, arr) + sum(i,k,arr)*sum(k+1,j,arr));
    }
    return dp[i][j] = mini;
}

int main(){
    int n;
    while(cin>>n){
        dp.clear();
        dp.resize(n + 1, vector<int>(n+1, -1));
        vector<int> arr(n);
        for(int i = 0 ; i < n ; i++) cin>>arr[i];
        cout<<"\n"<<f(0, n - 1, arr)<<'\n';
    }
}