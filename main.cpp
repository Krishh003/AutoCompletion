#include "header/trie.h"
#include<iostream>
#include<fstream>

int main(){
    //creating the root of the trie
    TrieNode*root=createTrieNode('#');

    //reading from the file and inputing it the to trie
    std::ifstream reader("myfile.txt");
    std::string word="";
    while(reader >> word){
        insertTrieNode(root,word);//insert into trie
    }
    reader.close();

    //display all the words in the trie
    std::string ans=""; //passing empty string to display function.
    displayTrie(root,ans);
    
    return 0;
}