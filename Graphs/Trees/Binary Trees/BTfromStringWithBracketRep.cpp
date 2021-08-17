//https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/
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

int findIndex(string str, int start, int end)
{
        stack<char> s;

        if (start > end)
                return -1;


        for (int i = start; i <= end; i++)
        {

                if (str[i] == '(')
                        s.push('(');
                else if (str[i] == ')')
                {

                        if (s.top() == '(')
                        {
                                s.pop();

                                if (s.empty())
                                        return i;
                        }
                }
        }

        return -1;
}

Node* StringToBT(string str, int start, int end)
{

        if (start > end)
                return NULL;
        Node *root = newNode(str[start] - '0');



        int index = findIndex(str, start + 1, end);

        if (index != -1)
        {
                root->left = StringToBT(str, start + 2, index - 1);
                root->right = StringToBT(str, index + 2, end - 1);
        }

        return root;
}

void print(Node* root)
{
        if (root == NULL)
                return;

        cout << root->data << " ";;

        print(root->left);
        print(root->right);
}

int main()
{

        string str = "4(2(3(6(7))(5))(1))";
        int len = str.length();



        Node* root = StringToBT(str, 0, len - 1);



        print(root);

        return 0;
}