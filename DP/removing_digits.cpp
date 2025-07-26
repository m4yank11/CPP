#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> dp;

vector<int> get_digits(int n){
    vector<int> digits;
    while(n){
        digits.push_back(n%10);
        n/=10;
    }
    return digits;
}

int f(int n){
    if(n == 0) return 0;
    if(n <= 9) return 1;

    if(dp[n] != -1) return dp[n];

    vector<int> digits = get_digits(n);

    int result = INT_MAX;

    for(int i = 0; i < digits.size(); i++){
        if(digits[i] > 0){
            result = min(result, f(n - digits[i]));
        }
    }
    return dp[n] = 1 + result;

}

int main(){
    int n;
    cin >> n;
    dp.clear();
    dp.resize(n+1, -1);
    cout << f(n) << endl;
    return 0;
}