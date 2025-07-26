//
//  main.cpp
//  Permutation and combination
//
//  Created by Mayank Raj Gupta on 16/09/23.
//

#include <iostream>
#include <vector>
using namespace std;

//int fact(int n){
//    int f=1;
//    for(int i=1;i<=n;i++){
//        f=f*i;
//    }
//    return f;
//}
int fact(int n){
    vector<int>dp(n);
    dp[0]=1;
    dp[1]=1;
    for(int i=0;i<n;i++){
        dp[i] = i*dp[i-1];
    }
    return dp[n];
}

void combination(int n,int r){
    cout<<fact(n)/(fact(n-r)*fact(r))<<endl;
}

int permutation(int n,int r){
    int p=fact(n)/fact(n-r);
    return p;
}

int main(){
    int n,r;
    cout<<"enter n and r : ";
    cin>>n>>r;
    cout<<fact(n)<<endl;
    combination(n, r);
    cout<<permutation(n, r)<<endl;
}
