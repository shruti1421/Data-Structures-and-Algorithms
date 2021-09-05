#include<bits/stdc++.h>
using namespace std;

void CheckNegativeCycleBF(int src, map<int, vector<int>> edges)
{
        int V = edges.size();

        vector<int> dis(V, 1e9);

        dis[src] = 0;

        for (int i = 0; i < V - 1; i++)
        {
                for (auto &x : edges)
                {
                        vector<int> edge = x.second;
                        if (dis[edge[0]] + edge[2] < dis[edge[1]])
                                dis[edge[1]] = dis[edge[0]] + edge[2];
                }
        }

        for (auto &x : edges)
        {

                vector<int> edge = x.second;
                if (dis[edge[0]] + edge[2] < dis[edge[1]])
                {
                        cout << "This graph contains negative weight cycle\n";
                        return;
                }
        }


        for (int i = 0; i < V; i++)
        {
                if (dis[i] == 1e9)
                        cout << "INF ";
                else
                        cout << dis[i] << " ";
        }

        return;
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

        map<int, vector<int>> edges;

        for (int i = 0; i < E; i++)
        {
                int u, v, w;
                cin >> u >> v >> w;

                edges[i] = {u, v, w};
        }

        CheckNegativeCycleBF(0, edges);

        return 0;
}