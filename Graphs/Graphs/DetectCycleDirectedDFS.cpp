#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    map<int, bool> vis;
    map<int, bool> dfsvis;
    map<int, vector<int>> adj;

    void addEdge(int v, int w);

    bool DetectCycle(int v);
};

void Graph :: addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph :: DetectCycle(int v)
{
    vis[v] = 1;
    dfsvis[v] = 1;
    for (int i = 0; i < adj[v].size(); i++)
    {
        if (!vis[adj[v][i]])
        {
            if (DetectCycle(adj[v][i]))
                return true;
        } else if (dfsvis[adj[v][i]])
            return true;
    }

    dfsvis[v] = 0;

    return false;
}

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(1, 2);

    g.vis[0] = 1;
    g.dfsvis[0] = 1;
    cout << g.DetectCycle(0);
    return 0;
}