#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited)) return true;
        } 
        else if (neighbor != parent) {
            return true; 
        }
    }
    return false;
}

bool containsCycle(int V, vector<pair<int,int>> &edges) {
    vector<vector<int>> adj(V);

    // Build adjacency list
    for (auto &e : edges) {
        int u = e.first, v = e.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) return true;
        }
    }
    return false;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<pair<int,int>> edges(E);
    cout << "Enter edges (u v) one per line:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    bool ans = containsCycle(V, edges);
    cout << (ans ? "true" : "false") << endl;

    return 0;
}
