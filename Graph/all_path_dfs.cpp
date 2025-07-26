#include<iostream>
#include<vector>
#include<unordered_set>
#include<list>
using namespace std;

vector<list<int>> graph;
int v; // no of vertices
unordered_set<int> visited;
vector<vector<int>> result;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void dfs(int curr, int dest, vector<int>& path){
    if(curr == dest){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
    }
    visited.insert(curr);
    for(auto neighbour: graph[curr]){
        if(not visited.count(neighbour)){
            dfs(neighbour, dest, path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;

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
    vector<int> path;

    dfs(s,d, path);
    for(auto p: result){
        for(auto el : p){
            cout<<el<<" ";
        }
        cout<<endl;
    }
    return 0;

}