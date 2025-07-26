//
//  main.cpp
//  Matrix print in wave
//
//  Created by Mayank Raj Gupta on 01/01/24.
//

#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int>> &a){
    for(int i=0;i<a.size();i++){
        if(i%2==0){
            for(int j=0;j<a[0].size();j++){
                cout<<a[i][j]<<" ";
            }
        }
        else{
            for(int j=a[0].size()-1; j>=0;j--){
                cout<<a[i][j]<<" ";
            }
        }
    }
}

// for reverse wave matrix

void displayreverse(vector<vector<int>> &a){
    for(int i=a.size()-1;i>=0;i--){
        if(i%2==0){
            for(int j=0;j<a[0].size();j++){
                cout<<a[i][j]<<" ";
            }
        }
        else{
            for(int j=a[0].size()-1; j>=0;j--){
                cout<<a[i][j]<<" ";
            }
        }
    }
}
//for column wise printing
void displaycol(vector<vector<int>> &a){
    for(int j=0;j<a[0].size();j++){
        if(j%2==0){
            for(int i=0; i<a.size();i++){
                cout<<a[i][j]<<" ";
            }
        }
        else{
            for(int i=a.size()-1;i>=0;i--){
                cout<<a[i][j]<<" ";
            }
        }
        
    }
}


int main() {

    int m, n;
    cout << "Enter the number of rows and columns in the matrix: ";
    cin >> m >> n;
    //Initializing the matrix with 0
    vector<vector<int>> a(m, vector<int>(n, 0));
    
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout<<"Matrix in wave form: "<<endl;
    display(a);
    cout<<endl;
    cout<<"Matrix in reverse wave form: "<<endl;
    displayreverse(a);
    cout<<endl;
    cout<<"Matrix in reverse wave column wise form: "<<endl;
    displaycol(a);
}

