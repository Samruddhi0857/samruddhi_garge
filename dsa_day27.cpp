#include <bits/stdc++.h>
using namespace std;

int shortestPath(int V, vector<vector<int>>& edges, int start, int end)
{
  
    vector<vector<int>> adj(V);
    for (auto &edge : edges)
      {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);
    queue<pair<int,int>> q; 
         q.push({start, 0});
        visited[start] = true;

    while (!q.empty())
      {
           auto [node, dist] = q.front();
        q.pop();

        if (node == end) return dist;

        for (int nei : adj[node]) 
        {
            if (!visited[nei]) 
            {
                visited[nei] = true;
                q.push({nei, dist + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    cout << "Enter edges (u v):\n";
      for (int i = 0; i < E; i++) 
      {
        cin >> edges[i][0] >> edges[i][1];
    }

    int start, end;
       cout << "Enter start node: ";
       cin >> start;
        cout << "Enter end node: ";
           cin >> end;

    int result = shortestPath(V, edges, start, end);
       cout << "Shortest path length: " << result << endl;

    return 0;
}
