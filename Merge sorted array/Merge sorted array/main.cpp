//
//  main.cpp
//  Merge sorted array
//
//  Created by Mayank Raj Gupta on 21/12/23.


#include <iostream>
#include <vector>
using namespace std;

vector<int> Merge(vector<int>& v1, vector<int>& v2) {
    int i = 0, j = 0;
    int m = v1.size();
    int n = v2.size();
    vector<int> v;
    while (i < m && j < n) {
        if (v1[i] < v2[j]) {
            v.push_back(v1[i]);
            i++;
        } else if (v2[j] < v1[i]) {
            v.push_back(v2[j]);
            j++;
        }
    }
    while (i < m) {
        v.push_back(v1[i]);
        i++;
    }
    while (j < n) {
        v.push_back(v2[j]);
        j++;
    }
    return v;
}


int main(){
    vector<int> v1;
    vector<int> v2;
    int size1;
    cout<<"Enter the size of first array: ";
    cin>>size1;
    for(int i=0; i<size1; i++){
        int x;
        cin>>x;
        v1.push_back(x);
    }
    
    int size2;
    cout<<"Enter the size of second array: ";
    cin>>size2;
    for(int i=0; i<size2; i++){
        int x;
        cin>>x;
        v2.push_back(x);
    }
    for(int i=0; i< size1 ; i++){
        cout<< v1[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<size2; i++){
        cout<< v2[i]<<" ";
    }
    cout<<endl;
    vector<int> v = Merge(v1, v2);
    for(int i=0; i< (size1 + size2); i++){
        cout<< v[i]<<" ";
    }
    cout<<endl;
}

