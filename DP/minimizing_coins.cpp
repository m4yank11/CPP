#include<iostream>
#include <vector>
#include<climits>
using namespace std;

vector<int>dp;

int f(vector<int>& coins, int amount){
    if(amount == 0) return 0;
    if(dp[amount] != -1) return dp[amount];

    int result = INT_MAX;
    for(int i = 0 ; i < coins.size() ; i++){
        if(amount - coins[i] >= 0){
            result = min(result, f(coins, amount - coins[i]));
        }
    }
    return dp[amount] = (result == INT_MAX ? INT_MAX : result + 1);
}

int coinChange(vector<int>& coins, int amount) {
    // recurrence 
    // f(target) -> minimum coins required with this target remaining
    // f(target) = 1 + min(f(target-ith coin))
    dp.clear();
    dp.resize(amount+1, -1);
    return f(coins, amount) == INT_MAX ? -1 : f(coins, amount);
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i = 0 ; i < n ; i++){
        cin>>coins[i];
    }
    cout<<coinChange(coins, x)<<endl;

}