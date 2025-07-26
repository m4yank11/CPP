//
//  main.cpp
//  Sort 0's & 1's
//
//  Created by Mayank Raj Gupta on 21/12/23.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> Sort(vector<int>&v){
    int i= 0, j= (int)v.size()-1;
    while(i<=j){
        if(v[i]==0) i++;
        else if (v[j]==1) j--;
        else if (v[i]==1 && v[j]==0){
            v[i]=0;
            v[j]=1;
            i++;
            j--;
        }
    }
    return v;
}

int main(){
    
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    vector<int> v(size);
    for(int i=0; i<size; i++){
        cin>>v[i];
    }
    v= Sort(v);
    for(int i=0; i< size; i++){
        cout<< v[i]<<" ";
    }
    cout<<endl;
}

