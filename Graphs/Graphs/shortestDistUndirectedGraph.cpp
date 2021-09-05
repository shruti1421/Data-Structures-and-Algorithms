#include<bits/stdc++.h>
using namespace std;

void shortestDistance(int src, vector<vector<int>> &adj)
{
        int V = adj.size();

        vector<int> vis(V, 0);

        queue<int> q;

        vector<int> dis(V, 1e9);

        q.push(src);
        vis[src] = 1;
        dis[src] = 0;

        while (!q.empty())
        {
                int curr = q.front();
                q.pop();

                for (int i = 0; i < adj[curr].size(); i++)
                {
                        if (!vis[adj[curr][i]])
                        {
                                vis[adj[curr][i]] = 1;
                                vis[adj[curr][i]] = 1;
                                q.push(adj[curr][i]);

                                if (dis[curr] + 1 < dis[adj[curr][i]])
                                        dis[adj[curr][i]] = dis[curr] + 1;
                        }
                }
        }

        for (int i = 0; i < V; i++)
        {
                if (dis[i] == 1e9)
                        cout << "INF ";
                else
                        cout << dis[i] << " ";
        }

        cout << "\n";
}

int main()
{

        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
        //for getting input from input.txt
        freopen("input.txt", "r", stdin);
        //for writing output to output.txt
        freopen("output.txt", "w", stdout);
#endif


        int V, E;

        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
                int u, v;
                cin >> u >> v;

                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        shortestDistance(0, adj);

        return 0;
}