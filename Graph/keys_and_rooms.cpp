#include<iostream>
#include <vector>
#include <list>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
    vector<list<int>> graph;
    int v;
    unordered_set<int> visited;

    void bfs(int src){
        queue<int> q;
        visited.clear();
        q.push(src);
        visited.insert(src);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto neighbour : graph[cur]){
                if(visited.find(neighbour) == visited.end()){
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        v = rooms.size();
        graph.resize(v, list<int>());
        for(int i = 0 ; i < v; i++){
            for(int j = 0 ; j < rooms[i].size(); j++){
                graph[i].push_back(rooms[i][j]);
            }
        }
        bfs(0);
        return visited.size() == v? true : false;
    }
};
int main(){
    
}