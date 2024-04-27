#include<iostream>
#include "header/trie.h"
using namespace std;


int main(){
    //creating the root of the trie
    TrieNode*root=createTrieNode('#');

    //inserting a word
    insertTrieNode(root,"akshat");

    //display all the words in the trie
    string ans=""; //passing empty string to display function.
    displayTrie(root,ans);
    
    cout<<"Hello world";
    
    return 0;
}