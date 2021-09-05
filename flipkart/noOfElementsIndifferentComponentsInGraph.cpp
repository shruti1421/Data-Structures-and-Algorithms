//https://www.geeksforgeeks.org/flipkart-internship-interview-experience-on-campus-2021/
The first question was based on Graphs DFS. It was simply related to finding the no. of elements in different components.

#include<bits/stdc++.h>
using namespace std;

int countCmp(int u, vector<int> adj[], vector<int> &vis)
{
        queue<int> q;

        q.push(u);

        vis[u] = 1;

        int c = 1;

        while (!q.empty())
        {
                int v = q.front();
                q.pop();

                for (int i = 0; i < adj[v].size(); i++)
                {
                        if (!vis[adj[v][i]])
                        {
                                vis[adj[v][i]] = 1;
                                q.push(adj[v][i]);
                                c++;
                        }
                }

        }

        return c;
}

int main() {

        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
        //for getting input from input.txt
        freopen("input.txt", "r", stdin);
        //for writing output to output.txt
        freopen("output.txt", "w", stdout);
#endif


        int n, m;

        cin >> n >> m;

        vector<int> adj[n + 1];

        while (m--)
        {
                int x, y;
                cin >> x >> y;

                adj[x].push_back(y);
                adj[y].push_back(x);
        }

        vector<int> vis(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
                if (!vis[i])
                {
                        cout << countCmp(i, adj, vis) << "\n";
                }
        }
}