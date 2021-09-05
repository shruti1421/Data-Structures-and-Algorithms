#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    map<int, bool> vis;
    map<int, vector<int>> adj;

    void addEdge(int v, int w);

    bool DetectCycle(int v);
};

void Graph :: addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph :: DetectCycle(int v)
{
    queue<pair<int, int>> q;
    q.push({v, -1});
    vis[v] = 1;

    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!vis[adj[node][i]])
            {
                vis[adj[node][i]] = 1;
                q.push({adj[node][i], node});
            } else if (adj[node][i] != par)
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
    g.addEdge(2, 1);

    cout << g.DetectCycle(0);
    return 0;
}