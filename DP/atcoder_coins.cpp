#include<iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Finding the probability of having more heads than tails

vector<vector<double>> dp;

double f(int i, int x, vector<double>& p){
    if(x == 0) return 1;
    if(i == -1) return 0;
    if(dp[i][x] > -0.9) return dp[i][x]; // comparing to -1 will always give ulta answer because of double integers
    return dp[i][x] = f(i-1, x-1, p)*p[i] + f(i-1, x, p)*(1-p[i]);
}


int main(){
    int n ;
    cin>>n;
    vector<double>p(n);
    dp.clear();
    dp.resize(3003, vector<double>(3003, -1));
    for(int i = 0 ; i < n ; i++) cin>>p[i];

    cout<<fixed<<setprecision(9)<<f(n - 1, (n/2)+1, p)<<'\n';

}