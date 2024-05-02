#include "reader.h"
#include "trie.h"
#include <fstream>
#include <unordered_map>


bool setup_trie(TrieNode *root) {

  // reading from the file and inputing it the to trie
  std::ifstream reader("myfile.txt");
  if (!reader.is_open()) {
    return false;
  }
  std::string word = "";
  while (reader >> word) 
  {
    insertTrieNode(root, word); // insert into trie
  }
  reader.close();
  return true;
}

bool setup_emoji(std::unordered_map<std::string,std::string>&hmap) {
  std::string str = "", emoji = "";
  std::ifstream reader("emoji.txt");
  if (!reader.is_open()) {
    return false;
  } else {
    while (reader >> str) {
      reader >> emoji;
      hmap[str] = emoji;
    }
    return true;
  }
}

std::string get_emoji(std::string word,std::unordered_map<std::string, std::string>&hmap){
  if(hmap[word]!=""){
    return hmap[word];
  }
  else{
    return "";
  }
}