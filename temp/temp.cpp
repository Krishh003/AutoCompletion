

#include "header/trie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
void displayMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Insert a word" << std::endl;
    std::cout << "2. Delete a word" << std::endl;
    std::cout << "3. Search for a word" << std::endl;
    std::cout << "4. Display all words" << std::endl;
    std::cout << "5. Auto-complete" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int getChoice() {
    int choice;
    while (!(std::cin >> choice) || choice < 1 || choice > 6) {
        std::cout << "Invalid input. Please enter a number between 1 and 6: ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
    return choice;
}

bool isValidWord(const std::string& word) {
    for (char c : word) {
        if (std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

std::string getValidWord() {
    std::string word;
    while (true) {
        std::cin >> word;
        if (isValidWord(word)) {
            break;
        } else {
            std::cout << "Invalid word. Please enter a word without numbers: ";
        }
    }
    return word;
}

int main() {
    TrieNode* root = createTrieNode('#'); // Assuming '#' denotes the root node

    int choice;
    std::string word;

    do {
        displayMenu();
        choice = getChoice();

        switch(choice) {
            case 1:
                std::cout << "Enter word to insert: ";
                word = getValidWord();
                insertTrieNode(root, word);
                break;
            case 2:
                std::cout << "Enter word to delete: ";
                word = getValidWord();
                deleteTrieNode(root, word);
                break;
            case 3:
                std::cout << "Enter word to search: ";
                word = getValidWord();
                searchTrieNode(root, word);
                break;
            case 4:
                std::cout << "All words in Trie:" << std::endl;
                displayTrie(root, "");
                break;
            case 5:
                std::cout << "Enter query for auto-complete: ";
                word = getValidWord();
                printAutoComplete(root, word);
                break;
            case 6:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while(choice != 6);

    // Clean up resources
    // e.g., deleteTrie(root);

    return 0;
}









// int main(){
//     //creating the root of the trie
//     TrieNode* root = createTrieNode('#');

//     //reading from the file and inputting it to the trie
//     std::ifstream reader("myfile.txt");
//     std::string word="";
//     while(reader >> word)
//     {
//         insertTrieNode(root,word); //insert into trie
//     }
//     reader.close();

//     // display all the words in the trie
//     std::string ans=""; // passing an empty string to display function.
//     std::string query;
//     std::cout << "Enter query : ";
//     std::cin >> query;
//     std::cout << std::endl;

//     std::transform(query.begin(), query.end(), query.begin(), ::tolower);

//     printAutoComplete(root, query);
//     displayQueryTrie(root, query, ans);

//     // Autocorrect

    

//     std::string correctedWord = autoCorrect(root, query);
//     if (correctedWord != query) {
//         std::cout << "Did you mean: " << correctedWord << "?" << std::endl;
//     }

//     return 0;
// }

// #include "header/trie.h"
// #include<iostream>
// #include<fstream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     //creating the root of the trie
//     TrieNode* root = createTrieNode('#');

//     //reading from the file and inputing it the to trie
//     ifstream reader("myfile.txt");
//     string word="";
//     while(reader >> word)
//     {
//         insertTrieNode(root,word);//insert into trie
//     }
//     reader.close();

//     //display all the words in the trie
//     string ans=""; //passing empty string to display function.
//     string query;
//     cout << "Enter query : ";
//     cin >> query;
//     cout << endl;

//     transform(query.begin(),query.end(),query.begin(), ::tolower);

//     printAutoComplete(root, query);
//     displayQueryTrie(root,query,ans);

//     std::string inputWord;
//     std::cout << "Enter word for auto-correction: ";
//     std::cin >> inputWord;

//     std::string suggestion = autoCorrect(root, inputWord);
//     std::cout << "Auto-correct suggestion: " << suggestion << std::endl;

    
//     return 0;
// }


#include "headers/reader.h"
#include "headers/trie.h"
#include <iostream>
#include <unordered_map>

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

void displayMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Insert a word" << std::endl;
    std::cout << "2. Delete a word" << std::endl;
    std::cout << "3. Search for a word" << std::endl;
    std::cout << "4. Display all words" << std::endl;
    std::cout << "5. Auto-complete" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int getChoice() {
    int choice;
    while (!(std::cin >> choice) || choice < 1 || choice > 6) {
        std::cout << "Invalid input. Please enter a number between 1 and 6: ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
    return choice;
}

bool isValidWord(const std::string& word) {
    for (char c : word) {
        if (!std::isalpha(c) && !std::isspace(c)) { // Reject if not alphabetic or whitespace
            return false;
        }
    }
    return true;
}

std::string getValidWord() {
    std::string word;
    while (true) {
        std::cin >> word;
        if (isValidWord(word)) {
            break;
        } else {
            std::cout << "Invalid word. Please enter a word without symbols: ";
        }
    }
    return word;
}

sint main() {
    // creating the root of the trie
    TrieNode *root = createTrieNode('#');
    unordered_map<string, string> hmap;
    bool success = setup_trie(root);
    bool check = setup_emoji(hmap);
    if (!success || !check) {
        std::cout << "Internal error! Cannot proceed. Exiting program..." << std::endl;
        return 1;
    }

    int choice;
    std::string word;

    do {
        displayMenu();
        choice = getChoice();

        switch(choice) {
            case 1:
                std::cout << "Enter word to insert: ";
                word = getValidWord();
                insertTrieNode(root, word);
                break;
            case 2:
                std::cout << "Enter word to delete: ";
                word = getValidWord();
                deleteTrieNode(root, word);
                break;
            case 3:
                std::cout << "Enter word to search: ";
                word = getValidWord();
                searchTrieNode(root, word);
                break;
            case 4:
                std::cout << "All words in Trie:" << std::endl;
                displayTrie(root, "");
                break;
            case 5:
                std::cout << "Enter query for auto-complete: ";
                word = getValidWord();
                printAutoComplete(root, word, hmap);
                break;
            case 6:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while(choice != 6);

    // Clean up resources
    // e.g., deleteTrie(root);

    return 0;
}
