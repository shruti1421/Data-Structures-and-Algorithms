#include<bits/stdc++.h>
using namespace std;

void shortestPairDist(vector<vector<int>> &dist)
{
        int V = dist.size();

        for (int x = 0; x < V; x++)
        {
                for (int i = 0; i < V; i++)
                {
                        for (int j = 0; j < V; j++)
                        {
                                if (dist[i][x] + dist[x][j] < dist[i][j])
                                        dist[i][j] = dist[i][x] + dist[x][j];

                                if (i == j && dist[i][j] < 0)
                                {
                                        cout << "This Graph contains negative cycle";
                                        return;
                                }
                        }
                }
        }


        for (int i = 0; i < V; i++)
        {
                for (int j = 0; j < V; j++)
                {
                        if (dist[i][j] == 1e9)
                                cout << i << "-" << j << " : " << "INF\n";
                        else
                                cout << i << "-" << j << " : " << dist[i][j] << "\n";
                }
        }
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

        vector<vector<int>> dist(V, vector<int>(V, 1e9));

        for (int i = 0; i < V; i++)
        {

                for (int j = 0; j < V; j++)
                {
                        if (i == j)
                                dist[i][j] = 0;
                }
        }

        for (int i = 0; i < E; i++)
        {
                int u, v, w;
                cin >> u >> v >> w;

                dist[u][v] = w;
        }


        shortestPairDist(dist);





        return 0;
}