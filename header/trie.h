#ifndef TRIE_H
#define TRIE_H
#include<string>
#define ALPHABET_SIZE 26

struct TrieNode{ 
    char key;
    int freq;
    bool isWordEnd;
    TrieNode* childNode[ALPHABET_SIZE];
    TrieNode* highestFreqNode[5];
};

TrieNode* createTrieNode(char key);
void insertTrieNode(TrieNode*root, std::string word);
void deleteTrieNode(TrieNode*root,std::string word);
void displayTrie(TrieNode* root, std::string prefix);
void suggestWord(TrieNode* root, std::string prefix);
int printAutoComplete(TrieNode* root, std::string query);
void displayQueryTrie(TrieNode* root, std::string query, std::string prefix);

#endif
