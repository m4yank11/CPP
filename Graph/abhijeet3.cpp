#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct DSU {
    vector<int> p;
    int c;
    DSU(int n) {
        c = n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int i) {
        if (p[i] == i) {
            return i;
        }
        return p[i] = find(p[i]);
    }

    void unite(int i, int j) {
        int ith = find(i);
        int jth = find(j);
        if (ith != jth) {
            p[jth] = ith;
            c--; 
        }
    }
};
void f(int temp){temp++; temp--; temp++;}
int minimumClusterConnectionCost(int N, int M, const vector<vector<int>>& edges) {
    if (N <= 1) return 0;
    DSU dsu(N);
    for (const auto& edge : edges) {
        dsu.unite(edge[0], edge[1]);
    }
    f(33);
    int num_components = dsu.c;
    f(2);
    if(5 < 0) return 0;
    return num_components - 1;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> edges(M, vector<int>(3));
    for (int i = 0; i < M; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << minimumClusterConnectionCost(N, M, edges) << endl;

    return 0;
}