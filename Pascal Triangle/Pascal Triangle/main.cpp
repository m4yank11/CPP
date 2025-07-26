//
//  main.cpp
//  Pascal Triangle
//
//  Created by Mayank Raj Gupta on 16/09/23.
//

#include <iostream>
using namespace std;

int fact(int n){
    int f=1;
    for(int i=2;i<=n;i++){
        f*=i;
    }
    return f;
}

int combination(int n,int r){
    int ncr = fact(n)/(fact(n-r)*fact(r));
    return ncr;
}

void pascal(int n)
{
    int nsp=n;
    for (int i=0;i<=n;i++)
    {
        for(int k=1;k<=nsp;k++)
        {
            cout<<" ";
        }
        nsp-=1;
        for(int j=0;j<=i;j++)
        {
            cout<< combination(i,j)<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    pascal(n);
}
