#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
        int prefix_count;
        TrieNode *child[26];
};

TrieNode nodepool[100000] ; //Pool of 100k trie nodes
TrieNode *root;
int poolcount;  //Always points to the next free trie node

void init() {
        poolcount = 0;
        root = &nodepool[poolcount++];

        for (int i = 0; i < 26; i++)
        {
                root->child[i] = NULL;
        }

        root->prefix_count = 0;
}

TrieNode *getNode() {
        TrieNode *newNode = &nodepool[poolcount++];

        for (int i = 0; i < 26; i++)
        {
                newNode->child[i] = NULL;
        }

        newNode->prefix_count = 1;

        return newNode;
}

void insertWord(string s) {

        TrieNode *curr = root;

        for (int i = 0; i < s.length(); i++)
        {
                int index = s[i] - 'a';
                if (curr->child[index] == NULL)
                        curr->child[index] = getNode();

                curr->prefix_count += 1;

                curr = curr->child[index];
        }


}

int prefix_count(string s) {

        TrieNode *curr = root;

        for (int i = 0; i < s.length(); i++)
        {
                int index = s[i] - 'a';

                curr = curr->child[index];
        }

        return curr->prefix_count;
}

int main() {

        init();

        insertWord("a");
        insertWord("ab");
        insertWord("abca");
        insertWord("acac");


        cout << prefix_count("abca") << " ";



        cout << prefix_count("a");

        return 0;
}
