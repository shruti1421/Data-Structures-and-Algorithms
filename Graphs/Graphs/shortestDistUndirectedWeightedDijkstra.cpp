#include<bits/stdc++.h>
using namespace std;

void shortestDistance(int src, vector<vector<pair<int, int>>> &adj)
{
        int V = adj.size();

        vector<int> vis(V, 0);

        multiset<pair<int, int>> minSet;

        vector<int> dis(V, 1e9);

        dis[src] = 0;
        minSet.insert({0, src});


        for (int i = 0; i < V; i++)
        {
                pair<int, int> curr = *minSet.begin();
                minSet.erase(minSet.begin());

                int node = curr.second;
                int nodeW = curr.first;

                if (vis[node]) continue;
                else
                        vis[node] = 1;

                for (int i = 0; i < adj[node].size(); i++)
                {
                        int nextNode = adj[node][i].first;
                        int nextW = adj[node][i].second;
                        if (dis[node] + nextW < dis[nextNode])
                        {
                                dis[nextNode] = dis[node] + nextW;

                                minSet.insert({dis[nextNode], nextNode});
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

        vector<vector<pair<int, int>>> adj(V);

        for (int i = 0; i < E; i++)
        {
                int u, v, w;
                cin >> u >> v >> w;

                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
        }

        shortestDistance(0, adj);

        return 0;
}