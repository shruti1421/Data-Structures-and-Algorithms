//https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/#:~:text=Given%20the%20array%20representation%20of,it%20into%20Binary%20Search%20Tree.&text=Swap%201%3A%20Swap%20node%208,node%209%20with%20node%2010.
#include<bits/stdc++.h>
using namespace std;

struct Node {
        int data;
        Node *left;
        Node *right;
};

Node *newNode(int x)
{
        Node* temp = new Node;
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
}

void inorder(int arr[], vector<int> &v, int n)
{
        if (n == 0)
                return;

        int i = 0;
        int curr = i;

        stack<int> st;

        while (!st.empty() || curr < n)
        {
                if (curr < n)
                {
                        st.push(curr);
                        curr = 2 * curr + 1;
                }
                else
                {
                        int x = st.top();
                        st.pop();

                        v.push_back(arr[x]);

                        curr = 2 * x + 2;
                }
        }
}

int minswaps(vector<int> v, int n)
{
        vector<int> sortedV = v;

        sort(sortedV.begin(), sortedV.end());

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
                mp.insert({sortedV[i], i});
        }

        vector<int> vis(1000, 0);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
                if (vis[v[i]] == 0)
                {
                        int c = 0;

                        int x = v[i];

                        while (vis[x] == 0)
                        {
                                vis[x] = 1;
                                x = v[mp[x]];
                                c++;
                        }

                        if (c > 0)
                                ans += c - 1;
                }
        }

        return ans;
}

int main()
{
        int arr[] = { 5, 6, 7, 8, 9, 10, 11 } ;
        int n = sizeof(arr) / sizeof(arr[0]);
        vector<int> v;
        inorder(arr, v, n);

        cout << minswaps(v, n);

        return 0;
}