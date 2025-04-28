#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Iterative DFS
void DFS_Iterative (const vector<vector<bool>>& adj, int start){
    const int size = adj.size();
    vector <bool> visited (size, false);
    stack <int> hash; hash.push(start);
    visited[start] = true;
    while (!hash.empty()){
        int cur = hash.top();
        hash.pop(); cout<<cur<<" ";
        for (int i = size - 1; i >= 0; --i)
            if (!visited[i] && adj[cur][i] == 1){
                hash.push(i);
                visited[i] = true;
            }
    }
    return;
}

//Recursive DFS
void DFS_Recursive (const vector<vector<bool>>& adj, vector <bool>& visited, int cur){
    if (visited[cur]) return;
    visited[cur] = true;
    cout<<cur<<" ";
    const int size = adj.size();
    for (int i = 0; i < size; ++i)
        if (!visited[i] && adj[cur][i] == 1)
            DFS_Recursive(adj, visited, i);
    return;
}
void DFS_Recursive(const vector<vector<bool>>& adj, int start){
    vector <bool> visited (adj.size(), false);
    return DFS_Recursive(adj, visited, start);
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
    cout<<"DFS : "; DFS_Iterative(adj, 0);
    cout<<"\nDFS : "; DFS_Recursive(adj, 0);
    return 0;
}