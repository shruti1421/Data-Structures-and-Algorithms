#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    map<int, bool> vis;
    map<int, vector<int>> adj;

    void addEdge(int v, int w);

    bool DetectCycle(int v, int par);
};

void Graph :: addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph :: DetectCycle(int v, int par)
{
    for (int i = 0; i < adj[v].size(); i++)
    {
        if (!vis[adj[v][i]])
        {
            vis[adj[v][i]] = 1;
            if (DetectCycle(adj[v][i], v) == 1)
                return true;
        } else if (adj[v][i] != par)
        {
            return true;
        }
    }

    return false;
}

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);


    g.vis[0] = 1;
    cout << g.DetectCycle(0, -1);
    return 0;
}