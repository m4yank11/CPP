//
//  main.cpp
//  Spiral Printing
//
//  Created by Mayank Raj Gupta on 02/01/24.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        size_t m = matrix.size();
        size_t n = matrix[0].size();
        //initializing/locating the pointers
        int minr = 0;
        int minc = 0;
        size_t maxr = m-1;
        size_t maxc = n-1;
        vector<int> a;
        while(minr<=maxr && minc<=maxc){
             //right
            for(int j=minc; j<= maxc; j++){
                a.push_back(matrix[minr][j]);
            }
            minr++;
        
            //down
            for(int i=minr; i<= maxr; i++){
                a.push_back(matrix[i][maxc]);
            }
            maxc--;
        
            if (minr <= maxr) { // Check to avoid duplicate printing in case of a single row
                for (size_t j = maxc; j >= minc; j--) {
                    a.push_back(matrix[maxr][j]);
                }
                maxr--;
            }

            // Up
            if (minc <= maxc) { // Check to avoid duplicate printing in case of a single column
                for (size_t i = maxr; i >= minr; i--) {
                    a.push_back(matrix[i][minc]);
                }
                minc++;
            }
        }
        return a;
    }

int main(){
    int m,n;
    cout<<"Enter the size of the rows and columns: ";
    cin>>m>>n;
    //initializing the matrix with 0
    vector<vector<int>> a(m, vector<int> (n,0));
    cout<<"Enter the elements of the matrix: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Output in spiral form is: "<<endl;
    vector<int>result = spiralOrder(a);
    for(int i=0; i<result.size();i++){
        cout<< result[i]<<" ";
    }
    cout<<endl;
}
