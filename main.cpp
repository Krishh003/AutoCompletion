#include "header/trie.h"
#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
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
    string query;
    cout << "Enter query : ";
    cin >> query;
    cout << endl;

    transform(query.begin(),query.end(),query.begin(), ::tolower);

    printAutoComplete(root, query);
    displayQueryTrie(root,query,ans);
    
    return 0;
}