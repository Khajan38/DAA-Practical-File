#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//BFS Iterative
void BFS_Iterative (const vector<vector<bool>>& adj, int start){
    const int size = adj.size();
    vector <bool> visited(size, false);
    queue <int> hash ; hash.push(start);
    visited[start] = true;
    while (!hash.empty()){
        int cur = hash.front();
        hash.pop(); cout<<cur<<" ";
        for (int i = 0; i < size; ++i)
            if (!visited[i] && adj[cur][i] == 1){
                hash.push(i);
                visited[i] = true;
            }
    }
    return;
}

//BFS Recursive
void BFS_Recursive (const vector<vector<bool>>& adj, vector <bool>& visited, queue <int>& hash){
    if (hash.empty()) return;
    const int size = adj.size();
    while (!hash.empty()){
        int cur = hash.front();
        hash.pop(); cout<<cur<<" ";
        for (int i = 0; i < size; ++i)
            if (!visited[i] && adj[cur][i] == 1){
                hash.push(i);
                visited[i] = true;
            }
    }
    BFS_Recursive(adj, visited, hash);
    return;
}
void BFS_Recursive (const vector<vector<bool>>& adj, int start){
    vector <bool> visited(adj.size(), false);
    queue <int> hash; hash.push(start);
    visited[start] = true;
    BFS_Recursive(adj, visited, hash);
}

int main(){
    vector<vector<bool>> adj = {
        {false, true,  false, false, false, false, true,  false},
        {false, false, true,  false, false, false, false, false},
        {false, false, false, true,  false, false, false, true },
        {true,  false, false, false, true,  false, false, false},
        {false, false, false, false, false, true,  false, false},
        {false, false, false, false, false, false, true,  false},
        {false, false, false, false, false, false, false, true },
        {false, false, false, false, false, false, false, false}
    };
    cout<<"BFS : "; BFS_Iterative(adj, 0);
    cout<<"\nBFS : "; BFS_Recursive(adj, 0);
    return 0;
}