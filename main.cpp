#include "header/trie.h"
#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

<<<<<<< Updated upstream
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
=======
int main() {
    // creating the root of the trie
    TrieNode *root = createTrieNode('#');
    int choice;
    std::string word;
    unordered_map<string, string> hmap;
    bool success = setup_trie(root);
    bool check = setup_emoji(hmap);

    if (success && check) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Insert a word" << std::endl;
        std::cout << "2. Delete a word" << std::endl;
        std::cout << "3. Search for a word" << std::endl;
        std::cout << "4. Display all words" << std::endl;
        std::cout << "5. Autocomplete" << std::endl;
        std::cout << "6. Exit" << std::endl;

        while (true) {
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Enter the word to insert: ";
                    std::cin >> word;
                    {
                        bool isValidInput = true;
                        for (char c : word) {
                            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                                isValidInput = false;
                                break;
                            }
                        }
                        if (isValidInput) {
                            insertTrieNode(root, word);
                        } else {
                            std::cout << "Invalid input! Please enter a word containing only alphabets." << std::endl;
                        }
                    }
                    break;
                case 2:
                    std::cout << "Enter the word to delete: ";
                    std::cin >> word;
                    {
                        bool isValidInput = true;
                        for (char c : word) {
                            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                                isValidInput = false;
                                break;
                            }
                        }
                        if (isValidInput) {
                            deleteTrieNode(root, word);
                        } else {
                            std::cout << "Invalid input! Please enter a word containing only alphabets." << std::endl;
                        }
                    }
                    break;
                case 3:
                    std::cout << "Enter the word to search: ";
                    std::cin >> word;
                    {
                        bool isValidInput = true;
                        for (char c : word) {
                            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                                isValidInput = false;
                                break;
                            }
                        }
                        if (isValidInput) {
                            searchTrieNode(root, word);
                        } else {
                            std::cout << "Invalid input! Please enter a word containing only alphabets." << std::endl;
                        }
                    }
                    break;
                case 4:
                    std::cout << "All words in the trie:" << std::endl;
                    displayTrie(root, "");
                    break;
                case 5:
                    std::cout << "Enter the prefix for autocomplete: ";
                    std::cin >> word;
                    {
                         bool isValidInput = true;
                        for (char c : word) {
                            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                                isValidInput = false;
                                break;
                            }
                        }
                        if (isValidInput) {
                             printAutoComplete(root, word,hmap);
                        } else {
                            std::cout << "Invalid input! Please enter a word containing only alphabets." << std::endl;
                        }
                    }
                    break;
                case 6:
                    std::cout << "Exiting program..." << std::endl;
                    return 0;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    } else {
        cout << "internal error! cannot proceed\nexiting program...";
    }

    return 0;
}
>>>>>>> Stashed changes
