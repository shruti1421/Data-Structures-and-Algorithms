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

        curr->word_end = 1;
}

bool isLastNode(struct TrieNode* root)
{
        for (int i = 0; i < 26; i++)
                if (root->child[i])
                        return 0;
        return 1;
}

void suggestionsRec(TrieNode* root, string Prefix)
{
        // found a string in Trie with the given prefix
        if (root->word_end == 1)
        {
                cout << Prefix << "\n";
        }

        // All children struct node pointers are NULL
        if (isLastNode(root))
        {
                return;
        }

        for (int i = 0; i < 26; i++)
        {

                if (root->child[i] != NULL)
                {
                        // append current character to currPrefix string
                        Prefix.push_back(97 + i);

                        // recur over the rest
                        suggestionsRec(root->child[i], Prefix);

                        Prefix.pop_back();
                }
        }
}

void searchWord(TrieNode* root, string s) {


        TrieNode *curr = root;

        string str = "";

        for (int i = 0; i < s.length(); i++)
        {
                int index = s[i] - 'a';


                str.append(1, s[i]);
                curr = curr->child[index];
        }


        suggestionsRec(curr, str);


}


int main() {

        init();

        insertWord("a");
        insertWord("ab");
        insertWord("bca");
        insertWord("bca");
        insertWord("bcab");
        insertWord("bbca");
        insertWord("bac");
        insertWord("howdoistartonlinecoding");
        insertWord("howtostartcooking");


        TrieNode *curr = root;


        searchWord(curr, "how");

        return 0;
}
