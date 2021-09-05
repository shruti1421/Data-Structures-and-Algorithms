#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    map<int, bool> vis;
    map<int, vector<int>> adj;

    void addEdge(int v, int w);

    void toposort(int v, stack<int> &topo);
};

void Graph :: addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph :: toposort(int v, stack<int> &topo)
{
    vis[v] = 1;

    for (auto &x : adj[v])
    {
        if (!vis[x])
        {
            toposort(x, topo);
        }
    }

    topo.push(v);

}

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);

    stack<int> topo;

    g.toposort(0, topo);

    while (!topo.empty())
    {
        cout << topo.top();
        topo.pop();
    }

    cout << "\n";


    return 0;
}