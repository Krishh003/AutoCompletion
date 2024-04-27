#include "header/trie.h"
#include<iostream>
#include<fstream>
using namespace std;

int main(){
    //creating the root of the trie
    TrieNode* root = createTrieNode('#');

    //reading from the file and inputing it the to trie
    ifstream reader("myfile.txt");
    string word="";
    while(reader >> word)
    {
        insertTrieNode(root,word);//insert into trie
    }
    reader.close();

    //display all the words in the trie
    string ans=""; //passing empty string to display function.
    
    printAutoComplete(root, "un");
    
    return 0;
}