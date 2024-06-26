#include "trie.h"
#include "reader.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

TrieNode *createTrieNode(char key)
{
    TrieNode *newnode = new TrieNode;
    newnode->key = key;
    newnode->freq = 1;
    newnode->isWordEnd = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        newnode->childNode[i] = NULL;
    }
    return newnode;
}

void insertTrieNode(TrieNode *root, std::string word)
{
    TrieNode *currentNode = root;
    transform(word.begin(),word.end(),word.begin(), ::tolower);

    for (char key : word)
    {
        if (currentNode->childNode[key - 'a'] == NULL)
        {
            TrieNode *newnode = createTrieNode(key);
            currentNode->childNode[key - 'a'] = newnode;
        }
        currentNode = currentNode->childNode[key - 'a'];
        currentNode->freq += 1;
    }
    currentNode->isWordEnd = true;
}

void deleteTrieNode(TrieNode *root, std::string word)
{
    transform(word.begin(),word.end(),word.begin(), ::tolower);
    if (word.length() == 0)
    {
        root->isWordEnd = false;
        return;
    }
    int index = word[0] - 'a';

    TrieNode *child;
    if (root->childNode[index] != NULL)
    {
        child = root->childNode[index];
    }
    else
    {
        std::cout << "No such word exists" << std::endl;
        return;
    }
    deleteTrieNode(child, word.substr(1));
}

void searchTrieNode(TrieNode *root, std::string word)
{
    transform(word.begin(),word.end(),word.begin(), ::tolower);
    bool ans = searchUtil(root, word);
    if (ans)
    {
        std::cout << "Word exists in the Trie" << std::endl;
    }
    else
    {
        std::cout << "Word does not exist" << std::endl;
    }
}

bool searchUtil(TrieNode *root, std::string word)
{
    if (word.length() == 0)
    {
        return root->isWordEnd;
    }
    int index = word[0] - 'a';

    TrieNode *child;
    if (root->childNode[index] != NULL)
    {
        child = root->childNode[index];
    }
    else
    {
        return false;
    }
    return searchUtil(child, word.substr(1));
}

void displayTrie(TrieNode *root, std::string prefix)
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

void displayQueryTrie(TrieNode *root, std::string query, std::string prefix)
{
    TrieNode *currentNode = root;
    for (auto c : query)
    {
        int index = c - 'a';
        if (!currentNode->childNode[index])
        {
            return;
        }
        currentNode = currentNode->childNode[index];
    }
    displayTrie(currentNode, query + prefix);
}

void suggestWord(TrieNode *root, std::string prefix, std::unordered_map<std::string, std::string> &hmap, std::vector<std::string> &ans,int ctr)
{
    if(ctr==0) return;
    if(ans.size() == 5)
        return;
    if(root->isWordEnd)
    {
        std::string emoji = get_emoji(prefix, hmap);
        ans.push_back(prefix + emoji);
    }

    int m = -1, m2 = -1,m3=-1;
    int index = -1, index2 = -1,index3=-1;
    for(int i = 0; i < 26; i++)
    {
        if(root->childNode[i])
        {
            if (m < root->childNode[i]->freq)
            {
                m = root->childNode[i]->freq;
                index = i;
            }
        }
    }
    for(int i = 0; i < 26; i++)
    {
        if(root->childNode[i])
        {
            if (m != root->childNode[i]->freq && m2 < root->childNode[i]->freq)
            {
                m2 = root->childNode[i]->freq;
                index2 = i;
            }
        }
    }
    for (int i = 0; i < 26;i++){
        if(root->childNode[i]){
            if(m!=root->childNode[i]->freq && m2!=root->childNode[i]->freq && m3<root->childNode[i]->freq){
                m3 = root->childNode[i]->freq;
                index3 = i;
            }
        }
    }
        char child = 'a' + index;
    if (index != -1)
        suggestWord(root->childNode[index], prefix + child, hmap, ans,ctr-1);
    child = 'a' + index2;
    if (ans.size() == 5)
        return;
    if (index2 != -1)
        suggestWord(root->childNode[index2], prefix + child, hmap, ans,ctr-1);
    if(ans.size()==5)
        return;
    child = 'a' + index3;
    if(index3!=-1)
        suggestWord(root->childNode[index3], prefix + child, hmap, ans,ctr-1);
    return;
}

void printAutoComplete(TrieNode *root, std::string query, std::unordered_map<std::string, std::string> &hmap)
{
    transform(query.begin(), query.end(), query.begin(), ::tolower);

    TrieNode *currentNode = root;
    for (auto c : query)
    {
       
        int index = c - 'a';
        if(currentNode->childNode[index] != NULL)
        {
            currentNode = currentNode->childNode[index];
        }
        else
        {
            std::cout << "Could not complete the word\n" << std::endl;
            return;
        }
    }
    std::vector<std::string>  ans;
    suggestWord(currentNode, query, hmap, ans,40);
    if (ans.size() == 0)
        std::cout << "Could not complete the word\n";
    else
    {
        for (auto x : ans)
        {
            std::cout << x << std::endl;
        }
    }
}

void autoCorrect(TrieNode *root, std::string word, std::string prefix)
{
    int count=0;
    TrieNode*temp;
    bool ans = searchIsMatch(root, word,temp,count);
    
    if(ans)
    {
        std::cout << word << std::endl;
    }
    else
    {
        int i;
        std::string correct;
        correct = word.substr(0,count-1);
    
        displayTrie(temp,correct+prefix);
    }
}

bool searchIsMatch(TrieNode *root, std::string word,TrieNode *&tempNode,int &count)
{

    if (word.length() == 0)
    {
        return root->isWordEnd;
    }
    tempNode = root;
    int index = word[0] - 'a';
    count++;
    TrieNode *child;

    if (root->childNode[index] != NULL)
    {
        child = root->childNode[index];
    }
    else
    {
        return false;
    }
    return searchIsMatch(child, word.substr(1),tempNode,count);
}
