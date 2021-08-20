//https://www.geeksforgeeks.org/check-given-graph-tree/#:~:text=Since%20the%20graph%20is%20undirected,graph%20is%20connected%2C%20otherwise%20not.
#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
        int V;
        list<int> *adj;
        bool isCyclic(int v, bool vis[], int parent);
        Graph(int V);//Constructor
        void addEdge(int v, int w);
        bool isTree();
};

Graph :: Graph(int V)
{
        this->V = V;
        this->adj = new list<int>[V];
}

void Graph :: addEdge(int v, int w)
{
        adj[v].push_back(w);
        adj[w].push_back(v);
}

bool Graph :: isCyclic(int v, bool vis[], int parent)
{
        vis[v] = 1;

        for (auto it = adj[v].begin(); it != adj[v].end(); it++)
        {
                if (vis[*it] == 0)
                {
                        if (isCyclic(*it, vis, v))
                                return true;
                } else if (*it != parent)
                        return true;
        }

        return false;
}

bool Graph :: isTree()
{
        bool *vis = new bool[V];

        for (int u = 0; u < V; u++)
                vis[u] = false;

        if (isCyclic(0, vis, -1))
                return false;

        for (int u = 0; u < V; u++)
        {
                if (vis[u] == false)
                        return false;
        }

        return true;
}

int main() {
        Graph g1(5);
        g1.addEdge(1, 0);
        g1.addEdge(0, 2);
        g1.addEdge(0, 3);
        g1.addEdge(3, 4);
        g1.isTree() ? cout << "Graph is Tree\n" :
                           cout << "Graph is not Tree\n";

        Graph g2(5);
        g2.addEdge(1, 0);
        g2.addEdge(0, 2);
        g2.addEdge(2, 1);
        g2.addEdge(0, 3);
        g2.addEdge(3, 4);
        g2.isTree() ? cout << "Graph is Tree\n" :
                           cout << "Graph is not Tree\n";

        return 0;
}