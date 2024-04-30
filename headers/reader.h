#ifndef READER_H
#define READER_H
#include "trie.h"
#include <unordered_map>
bool setup_trie(TrieNode*root);
bool setup_emoji(std::unordered_map<std::string,std::string>&hmap);
std::string get_emoji(std::string word,std::unordered_map<std::string,std::string>&hmap);

#endif