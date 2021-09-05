//https://leetcode.com/problems/possible-bipartition/
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>> dislikes) {
        vector<vector<int>> adj(N + 1);

        for (int i = 0; i < dislikes.size(); i++)
        {
            int x = dislikes[i][0];
            int y = dislikes[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        queue<int> q;

        vector<int> color(N + 1, -1);

        for (int i = 1; i <= N; i++) {

            if (color[i] != -1)
                continue;
            q.push(i);
            color[i] = 0;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int x : adj[node])
                {
                    if (color[x] == color[node])
                        return false;
                    if (color[x] == -1)
                    {
                        color[x] = 1 - color[node];
                        q.push(x);
                    }
                }
            }
        }

        return true;
    }
};