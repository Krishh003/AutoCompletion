#include<iostream>
#include<bits/stdc++.h>
#define ALPHABET_SIZE 26
using namespace std;

struct TrieNode{ 
    char key;
    int freq;
    bool isWordEnd;
    TrieNode* childNode[ALPHABET_SIZE];
    TrieNode* highestFreqNode[5];
};

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

void insertTrieNode(TrieNode** root, string word)
{
    TrieNode* currentNode = *root;

    for(auto key : word) //This is equivalent to for k in word where k is an auto data type (in our case auto to char)
    {
        if(currentNode->childNode[key-'a'] == NULL)
        {
            TrieNode* newnode = createTrieNode(key);
            currentNode->childNode[key-'a'] = newnode;
        }
        currentNode = currentNode->childNode[key-'a'];
    }
    currentNode->isWordEnd = true;
}

int main(){
    cout << "Hello World!\n";
    return 0;
}