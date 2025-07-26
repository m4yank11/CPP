//
//  main.cpp
//  Assignment 2
//
//  Created by Mayank Raj Gupta on 02/01/24.
//

#include <iostream>
#include<vector>
using namespace std;
//Q1
void diagonalPrint(vector<vector<int>> &a){
    size_t m=a.size();
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j || i+j==m-1){
                cout<<a[i][j]<<" ";
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}

//Q2
vector<vector<int>> rotateAnti(vector<vector<int>> &a){
    //reverse
    for(int i=0; i<a.size(); i++){
        reverse(a[i].begin(),a[i].end());
    }
    //transpose
    for(int i=0; i<a.size(); i++){
        for(int j=i+1; j<a[0].size(); j++){
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    return a;
}

//Q3
void wavePrint(vector<vector<int>> &a){
    size_t m = a.size();
    size_t n = a[0].size();

    for (int j = 0; j < n; j++) {
        if (j % 2 != 0) {
            // Odd column: top to bottom
            for (int i = 0; i < m; i++) {
                    cout << a[i][j] << " ";
            }
        } else {
            // Even column: bottom to top
            for (size_t i = m - 1; i >= 0; i--) {
                cout << a[i][j] << " ";
            }
        }
        
    }
}

//Q4
vector<vector<int>> spiralPrint(int n){
    int k=1;
    //pointers
    int minr=0;
    int maxr=n-1;
    int minc=0;
    int maxc=n-1;
    vector<vector<int>> a(n,vector<int>(n,0));
    while(k<=(n*n) && minr<=maxr && minc<=maxc){
        
        //right
        for(int j=minc; j<=maxc; j++){
            a[minr][j]=k;
            k++;
        }
        minr++;
        //down
        for(int i=minr; i<=maxr; i++){
            a[i][maxc]=k;
            k++;
        }
        maxc--;
        //left
        if(minc<=maxc){//yaha par hume check krna padega ki kahi minc maxc se bada na ho jaye
            for(int j=maxc; j>=minc; j--){
                a[maxr][j]=k;
                k++;
            }
            maxr--;
        }
        //top
        if(maxr>=minr){
            for(int i=maxr; i>=minr; i--){
                a[i][minc]=k;
                k++;
            }
            minc++;
        }
        
    }
    return a;
}

int main() {
    /*int m;
    cout<<"Enter the size of the square matrix: ";
    cin>>m;
    vector<vector<int>> a(m,vector<int>(m,0));
    cout<<"Enter the elements of the matrix: "<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }*/
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    diagonalPrint(a);
    cout<<endl;
    a= rotateAnti(a);
    /*for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<endl;
    cout<<"Answer 3: ";
    wavePrint(a);
    cout<<endl;
    int m;
    cout<<"Enter the order of the square matrix:";
    cin>>m;
    cout<<"Answer 4: "<<endl;
    vector<vector<int>> matrix(m,vector<int>(m,0));
    matrix= spiralPrint(m);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
