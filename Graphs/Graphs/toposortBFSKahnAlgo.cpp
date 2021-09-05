//https://www.geeksforgeeks.org/detect-cycle-in-a-directed-graph-using-bfs/?ref=rp
#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    map<int, bool> vis;
    map<int, int> indeg;
    map<int, vector<int>> adj;

    void addEdge(int v, int w);

    vector<int> toposort(int V);
};

void Graph :: addEdge(int v, int w)
{
    adj[v].push_back(w);
}

vector<int> Graph :: toposort(int V)
{
    for (int i = 0; i < V; i++)
        indeg[i] = 0;

    for (int i = 0; i < V; i++)
    {
        for (auto &x : adj[i])
        {
            indeg[x]++;
        }
    }

    vector<int> st;

    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
            st.push_back(i);
    }

    queue<int> q;

    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto &x : adj[node])
        {
            if (!vis[x])
            {
                q.push(x);

                indeg[x]--;

                if (indeg[x] == 0)
                    st.push_back(x);
            }
        }
    }

    return st;

}

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);

    vector<int> topo = g.toposort(4);

    for (auto &x : topo)
        cout << x << " ";

    cout << "\n";


    return 0;
}