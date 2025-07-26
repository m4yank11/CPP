//
//  main.cpp
//  daa lab evaluation
//
//  Created by Mayank Raj Gupta on 25/04/24.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string ans;

// Part 1
// fn (i,sum)  = fn(i+1,sum+a[i]) || fn(i+1,sum+b[i])

bool issolvable(int i,vector<int> &a,vector<int> &b,int n,int t,int sum,vector<vector<int>> &dp,string &p)
{

    if(i==n){
        if(sum==t){
            ans = p;
          
            return dp[i][sum+1000]=1;
        }
        else return dp[i][sum+1000]=0;
    }
    if(dp[i][sum+1000]!=-1)return dp[i][sum+1000];
    p.push_back('a');
    bool l = issolvable(i+1,a,b,n,t,sum+a[i],dp,p);
    p.pop_back();
    p.push_back('b');
    bool r = issolvable(i+1,a,b,n,t,sum+b[i],dp,p);
    p.pop_back();
    if(l||r)return dp[i][sum+1000]= 1;
    else return dp[i][sum+1000]= 0;
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int>a(n);
    vector<int>b(n);
    cout<<"Enter the elements of array A: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the elements of array B: ";
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    string p="";
    vector<vector<int>> dp(n+1,vector<int>(t+1000,-1));
    if(issolvable(0,a,b,n,t,0,dp,p)==0)cout<<"No solution found."<<endl;
    else{
        cout<<"Solution found."<<endl;
        int suma = 0;
        int sumb = 0;
        for(int i = 0;i<n;i++){
            if(ans[i]== 'a'){
                suma += a[i];
                cout<<  a[i]<<" ";
            }
            
            else {
               cout<<"  ";
            }
        }
        cout<<endl;
        for(int i = 0;i<n;i++){
        if(ans[i]== 'b'){
                sumb += b[i];
                cout<<  b[i]<<" ";
            }
            
            else {
               cout<<"  ";
            }
        }
        
            cout<<endl;
            cout<<"Sum of a: "<<suma<<endl;
            cout<<"Sum of b: "<<sumb<<endl;

    }
    
}
