#include<iostream>
#include<vector>
#include<unordered_set>
#include<list>
using namespace std;

vector<list<int>> graph;
int v; // no of vertices
unordered_set<int> visited;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

bool dfs(int curr, int dest){
    if(curr == dest) return true;
    visited.insert(curr);
    for(auto neighbour: graph[curr]){
        if(not visited.count(neighbour)){
            bool result = dfs(neighbour, dest);
            if(result) return true;
        }
    }
    return false;
}


int main(){
    cin>>v;
    graph.resize(v, list<int>());
    int e;
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }
    int s, d;
    cin>>s>>d;
    cout<<dfs(s,d)<<endl;
    return 0;

}