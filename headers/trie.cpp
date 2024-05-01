#include "trie.h"
#include "reader.h"
#include<iostream>
#include<algorithm>
#include <unordered_map>

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

void findTopFive(TrieNode* currentNode) 
{
    if(currentNode == NULL) 
    {
      return;
    }
    for(int i = 0; i < 26; ++i) 
    {
        if(currentNode->childNode[i] != NULL) 
        {
            findTopFive(currentNode->childNode[i]);
            for (int i = 0; i < 5; ++i) 
            {
                if(currentNode->childNode[i] != NULL)
                {
                    if(currentNode->highestFreqNode[i] == NULL || currentNode->childNode[i]->freq > currentNode->highestFreqNode[i]->freq) 
                    {
                        for(int j = 4; j > i; --j) 
                        {
                            currentNode->highestFreqNode[j] = currentNode->highestFreqNode[j - 1];
                        }
                        currentNode->highestFreqNode[i] = currentNode;
                        break;
                    }
                }
            }
        }
    }
}

void printNode(TrieNode* currentNode, int i)
{
    if(currentNode == NULL)
    {
        return;
    }
    std::cout << i << " .Value : " << currentNode->key << " and frequency : " << currentNode->freq << std::endl;
}

void findTopFiveForAllNodes(TrieNode* root) 
{
    if(root == NULL) 
    {
        return;
    }
    findTopFive(root);

    for(int i = 0; i < 26; ++i) 
    {
        findTopFiveForAllNodes(root->childNode[i]);
    }
}

void insertTrieNode(TrieNode* root, std::string word)
{
    TrieNode* currentNode = root;

    for(auto key : word) //This is equivalent to for k in word where k is an auto data type (in our case auto to char)
    {
        if(currentNode->childNode[key-'a'] == NULL) //if the child is NULL
        {
            TrieNode* newnode = createTrieNode(key);
            currentNode->childNode[key-'a'] = newnode;
        }
        currentNode = currentNode->childNode[key-'a'];
        currentNode->freq += 1;
    }
    currentNode->isWordEnd = true;
    findTopFiveForAllNodes(currentNode);
}

void deleteTrieNode(TrieNode *root, std::string word)
{
    if(word.length() == 0)
    {
        root->isWordEnd = false;
        return;
    }
    int index = word[0]-'a';

    TrieNode* child;
    if(root->childNode[index] != NULL)
    {
        child = root->childNode[index];
    }
    else
    {
        std::cout << "No such word exists" << std::endl;
        return;
    }
    deleteTrieNode(child,word.substr(1));
}

void searchTrieNode(TrieNode* root, std::string word)
{
    bool ans = searchUtil(root,word);
    if(ans)
    {
        std::cout << "Word exists in the Trie" << std::endl;
    }
    else
    {
        std::cout << "Word does not exists" << std::endl;
    }
}

bool searchUtil(TrieNode* root,std::string word)
{
    if(word.length() == 0)
    {
        return root->isWordEnd;
    }
    int index = word[0]-'a';

    TrieNode* child;
    if(root->childNode[index] != NULL)
    {
        child = root->childNode[index];

    }
    else
    {
        return false;
    }
    return searchUtil(child,word.substr(1));
}

void displayTrie(TrieNode* root, std::string prefix) 
{
    if (root == nullptr) 
    {
        return;
    }
    if (root->isWordEnd) 
    {
        std::cout << prefix << std::endl;
    }
    for (int i = 0; i < 26; ++i) 
    {
        if (root->childNode[i] != nullptr) 
        {
            displayTrie(root->childNode[i], prefix + char('a' + i));
        }
    }
}

void displayQueryTrie(TrieNode* root, std::string query, std::string prefix)
{
    TrieNode* currentNode = root;
    for(auto c : query)
    {
        int index = c - 'a';
        if(!currentNode->childNode[index])
        {
            return;
        }
        currentNode = currentNode->childNode[index];
    }
    displayTrie(currentNode, query + prefix);
}

void suggestWord(TrieNode* root, std::string prefix,std::unordered_map<std::string,std::string>&hmap)
{
    if (root->isWordEnd)
    {
        std::cout << prefix;
        std::string emoji=get_emoji(prefix,hmap);
        if(emoji!=""){
            std::cout<<emoji<<std::endl;
        }
        else{
            std::cout<<std::endl;
        }
    }
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if(root->childNode[i]) 
        {
            char child = 'a' + i;
            suggestWord(root->childNode[i], prefix + child,hmap);
        }
    }
}

int printAutoComplete(TrieNode* root, std::string query,std::unordered_map<std::string,std::string>&hmap)
{
    transform(query.begin(), query.end(), query.begin(), ::tolower);

    TrieNode* currentNode = root;
    for(auto c : query)
    {
        int index = c - 'a';
        if(!currentNode->childNode[index])
        {
            return 0;
        }
        currentNode = currentNode->childNode[index];
    }

    if(currentNode->isWordEnd == true)
    {
        std::cout << query << std::endl;
        return -1;
    }

    suggestWord(currentNode, query,hmap);
    return 1;
}