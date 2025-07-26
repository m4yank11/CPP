//
//  main.cpp
//  sum of doublet
//
//  Created by Mayank Raj Gupta on 19/12/23.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(6);
    int x;
    cout<<"Enter the sum: ";
    cin>>x;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]+v[j]==x) cout<<i<<" "<<j<<endl;
        }
    }
}
