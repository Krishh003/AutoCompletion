#include "trie.h"
#include<iostream>


TrieNode* createTrieNode(char key)
{
    TrieNode* newnode = new TrieNode;
    newnode->key = key;
    newnode->freq = 1;
    newnode->isWordEnd = false;
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        newnode->childNode[i] = NULL;
    }
    for(int i = 0; i < 5; i++)
    {
        newnode->highestFreqNode[i] = NULL;
    }
    return newnode;
}


void insertTrieNode(TrieNode* root, std::string word)
{
    TrieNode* currentNode = root;

    for(auto key : word) //This is equivalent to for k in word where k is an auto data type (in our case auto to char)
    {
        if(currentNode->childNode[key-'a'] == NULL) //if the child is not NULL
        {
            TrieNode* newnode = createTrieNode(key);
            currentNode->childNode[key-'a'] = newnode;
        }
        currentNode = currentNode->childNode[key-'a'];
    }
    currentNode->isWordEnd = true;
}


void displayTrie(TrieNode* root, std::string prefix) {
    if (root == nullptr) {
        return;
    }
    if (root->isWordEnd) {
        std::cout << prefix << std::endl;
    }
    for (int i = 0; i < 26; ++i) {
        if (root->childNode[i] != nullptr) {
            displayTrie(root->childNode[i], prefix + char('a' + i));
        }
    }
}