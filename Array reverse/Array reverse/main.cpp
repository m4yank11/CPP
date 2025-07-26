//
//  main.cpp
//  Array reverse
//
//  Created by Mayank Raj Gupta on 19/12/23.
//

#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &v){
    for(int k=0;k<v.size();k++){
        cout<< v[k]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v;
    v.push_back(6);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(4);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    display(v);
    int i=0, j= v.size()-1;
    while(i<=j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
    display(v);
    // vector also provides the facility to reverse the array just like sort was inbuilt
    reverse(v.begin(), v.end());
    display(v);
}
