//
//  main.cpp
//  Matrix Multiplication
//
//  Created by Mayank Raj Gupta on 27/12/23.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
    // here size_t is used instead of int just to tackle a warning
    size_t m = a.size(); // rows of first matrix
    size_t n = a[0].size(); // col of first matrix
    size_t p = b.size(); // rows of second matrix
    size_t q = b[0].size(); // col of second matrix

    if (n != p) {
        cout << "Multiplication not possible " << endl;
        return vector<vector<int>>(); // Return an empty matrix
    }

    vector<vector<int>> result(m, vector<int>(q, 0));

    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < q; j++) {
            // res[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j]*....
            for (size_t k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

int main() {

    int m, n;
    cout << "Enter the number of rows and columns in the first matrix: ";
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n, 0));

    int p, q;
    cout << "Enter the number of rows and columns in the second matrix: ";
    cin >> p >> q;
    vector<vector<int>> b(p, vector<int>(q, 0));
    
    cout << "Enter the elements of the first matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << "Enter the elements of the second matrix: " << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> b[i][j];
        }
    }
    vector<vector<int>> res = multiply(a, b);

    if (!res.empty()) {
        cout << "Resulting matrix after multiplication:" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < q; j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

