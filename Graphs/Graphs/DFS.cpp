#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    map<int, bool> vis;
    map<int, vector<int>> adj;

    void addEdge(int v, int w);

    void DFS(int v);
};

void Graph :: addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph :: DFS(int v)
{
    cout << v << " ";
    for (int i = 0; i < adj[v].size(); i++)
    {
        if (!vis[adj[v][i]])
        {
            vis[adj[v][i]] = 1;
            DFS(adj[v][i]);
        }
    }
}

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
         " (starting from vertex 2) \n";
    g.vis[2] = 1;
    g.DFS(2);
    return 0;
}