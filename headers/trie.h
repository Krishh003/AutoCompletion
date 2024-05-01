#ifndef TRIE_H
#define TRIE_H
#include<unordered_map>
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
void suggestWord(TrieNode* root, std::string prefix,std::unordered_map<std::string,std::string>&hmap);
int printAutoComplete(TrieNode* root, std::string query,std::unordered_map<std::string,std::string>&hmap);
void displayQueryTrie(TrieNode* root, std::string query, std::string prefix);
void deleteTrieNode(TrieNode* root, std::string word);
void searchTrieNode(TrieNode* root, std::string word);
bool searchUtil(TrieNode* root,std::string word);
void printNode(TrieNode* currentNode);
void findTopFiveForAllNodes(TrieNode* root);
void findTopFive(TrieNode* currentNode);

#endif
