#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

vector<vector<ll>>dp;

ll f(int i, int j , vector<int>& arr){
    if(i == j) return arr[i];
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max((arr[i] - f(i+1,j,arr)), (arr[j] - f(i, j-1,arr)));
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(3005, vector<ll>(3005, -1));
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    cout<<f(0,n-1,arr)<<endl;

}