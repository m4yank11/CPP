//  Rotation in Array
//  Created by Mayank Raj Gupta on 20/12/23.

#include <iostream>
#include <vector>
using namespace std;

void reversepart(int i, int j, vector<int> &v){
    while(i<=j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
    
    return;
}
void display(vector<int>&v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);
    v.push_back(7);
    v.push_back(4);
    v.push_back(8);
    v.push_back(5);
    
//    int size;
//    cout<<"Enter the size of the array: ";
//    cin>>size;
//    for(int i=0; i<size; i++){
//        int x;
//        cin>>x;
//        v.push_back(x);
//    }
    display(v);
    int k, n= (int)v.size();
    cout<<"Enter the no. of the rotation: ";
    cin>>k;
    if(k>n) k=k%n;
    reversepart(0,n-k-1, v);
    reversepart(n-k,n-1, v);
    reversepart(0,n-1, v);
    display(v);
}
