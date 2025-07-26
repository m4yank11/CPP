#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
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

void bfs(int src, vector<int>& dist){
    queue<int> q;
    visited.clear();
    dist.resize(v, INT_MAX);
    q.push(src);
    visited.insert(src);
    dist[src] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto neighbour : graph[cur]){
            if(visited.find(neighbour) == visited.end()){
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[cur] + 1;
            }
        }
    }
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
    vector<int> dist;
    bfs(s, dist);
    for(int i = 0 ; i < dist.size() ; i++){
        cout<<dist[i]<< " ";
    }
    cout<<endl;

    return 0;

}