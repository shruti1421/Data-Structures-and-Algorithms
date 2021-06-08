#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
        int word_end;
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

        root->word_end = 0;
}

TrieNode *getNode() {
        TrieNode *newNode = &nodepool[poolcount++];

        for (int i = 0; i < 26; i++)
        {
                newNode->child[i] = NULL;
        }

        newNode->word_end = 0;

        return newNode;
}

void insertWord(string s) {

        TrieNode *curr = root;

        for (int i = 0; i < s.length(); i++)
        {
                int index = s[i] - 'a';
                if (curr->child[index] == NULL)
                        curr->child[index] = getNode();

                curr = curr->child[index];
        }

        curr->word_end += 1;
}

bool searchWord(string s) {

        TrieNode *curr = root;

        for (int i = 0; i < s.length(); i++)
        {
                int index = s[i] - 'a';
                if (curr->child[index] == NULL)
                        return false;
                curr = curr->child[index];
        }

        if (curr->word_end == 0)
                return false;
        else
                return true;
}

void deleteWord(string s) {
        if (searchWord(s)) {

                TrieNode *curr = root;

                for (int i = 0; i < s.length(); i++)
                {
                        int index = s[i] - 'a';
                        curr = curr->child[index];
                }

                curr->word_end--;

        }
}

int main() {

        init();

        insertWord("a");
        insertWord("ab");
        insertWord("abca");


        cout << searchWord("abca") << " ";


        deleteWord("ab");

        cout << searchWord("ab");

        return 0;
}
