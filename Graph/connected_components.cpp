#include<iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<list<int>>graph;
int v;
void add_edge(int src, int dest){
    graph[src].push_back(dest);
}

void dfs(int node, unordered_set<int>& visited){
    visited.insert(node);
    for(auto neighbor : graph[node]){
        if(not visited.count(neighbor)){
            dfs(neighbor, visited);
        }
    }
}

int connectedComponents(){
    unordered_set<int> visited;
    int count = 0;
    for(int i = 0 ; i < v ; i++){
        // go to every vertex, if from one vertex we can initialize a DFS then we got a new cc
        if(visited.count(i) == 0){
            count++;
            dfs(i, visited);
        }
    }
    return count;
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
    cout<<connectedComponents()<<endl;
    return 0;
}