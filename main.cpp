#include<iostream>
#include<bits/stdc++.h>
#define ALPHABET_SIZE 26
using namespace std;

struct TrieNode{ 
    char key;
    int freq;
    bool isWordEnd;
    TrieNode* childNode[ALPHABET_SIZE];
    TrieNode* highestFreqNode[5];
};

<<<<<<< Updated upstream
TrieNode* createTrieNode(char key)
{
    TrieNode* newnode = new TrieNode;
    newnode->key = key;
    newnode->freq = 1;
    newnode->isWordEnd = false;
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        newnode->childNode[i] = NULL;
=======
    if (success && check) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Insert a word" << std::endl;
        std::cout << "2. Delete a word" << std::endl;
        std::cout << "3. Search for a word" << std::endl;
        std::cout << "4. Display all words" << std::endl;
        std::cout << "5. Autocomplete" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "7. Top 5 Nodes" << std::endl;
        std::cout << "8. DisplayQueryTrie" << std::endl;

        while(true) 
        {
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch(choice) 
            {
                case 1:
                {
                    std::cout << "Enter the word to insert: ";
                    std::cin >> word;
                    {
                        bool isValidInput = true;
                        for (char c : word) 
                        {
                            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) 
                            {
                                isValidInput = false;
                                break;
                            }
                        }
                        if (isValidInput) 
                        {
                            insertTrieNode(root, word);
                        } 
                        else 
                        {
                            std::cout << "Invalid input! Please enter a word containing only alphabets." << std::endl;
                        }
                    }
                    break;
                }
                case 2:
                {
                    std::cout << "Enter the word to delete: ";
                    std::cin >> word;
                    {
                        bool isValidInput = true;
                        for (char c : word)
                        {
                            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) 
                            {
                                isValidInput = false;
                                break;
                            }
                        }
                        if (isValidInput) 
                        {
                            deleteTrieNode(root, word);
                        } 
                        else 
                        {
                            std::cout << "Invalid input! Please enter a word containing only alphabets." << std::endl;
                        }
                    }
                    break;
                }
                case 3:
                {
                    std::cout << "Enter the word to search: ";
                    std::cin >> word;
                    {
                        bool isValidInput = true;
                        for (char c : word) 
                        {
                            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) 
                            {
                                isValidInput = false;
                                break;
                            }
                        }
                        if (isValidInput) 
                        {
                            searchTrieNode(root, word);
                        } 
                        else 
                        {
                            std::cout << "Invalid input! Please enter a word containing only alphabets." << std::endl;
                        }
                    }
                    break;
                }
                case 4:
                {
                    std::cout << "All words in the trie:" << std::endl;
                    displayTrie(root, "");
                    break;
                }
                case 5:
                {
                    std::cout << "Enter the prefix for autocomplete: ";
                    std::cin >> word;
                    {
                         bool isValidInput = true;
                        for (char c : word) 
                        {
                            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) 
                            {
                                isValidInput = false;
                                break;
                            }
                        }
                        if (isValidInput) 
                        {
                             printAutoComplete(root, word,hmap);
                        } 
                        else 
                        {
                            std::cout << "Invalid input! Please enter a word containing only alphabets." << std::endl;
                        }
                    }
                    break;
                }
                case 6:
                {
                    std::cout << "Exiting program..." << std::endl;
                    return 0;
                }
                case 7:
                {    
                    TrieNode* currentNode = root->childNode[1];
                    
                    //for(int j = 0; j < ALPHABET_SIZE; j++)
                    {
                        std::cout << "The Top 5 Nodes for the current node are :- " << std::endl;
                        for(int i = 0; i < 5; ++i)
                        {
                            if(currentNode->highestFreqNode[i] != NULL)
                            {
                                printNode(currentNode->highestFreqNode[i]);
                            }
                            //currentNode = currentNode->childNode[j];
                        }
                    }
                }
                case 8:
                {
                    std::string query,prefix;
                    std::cin >> query;
                    displayQueryTrie(root,query,prefix="");
                }
            }
        }
    } 
    else 
    {
        cout << "internal error! cannot proceed\nexiting program...";
>>>>>>> Stashed changes
    }
    for(int i = 0; i < 5; i++)
    {
        newnode->highestFreqNode[i] = NULL;
    }
    return newnode;
}

void insertTrieNode(TrieNode* root, string word)
{
    if(root==NULL)
    {
        root = createTrieNode('#');
    }
    TrieNode* currentNode = root;
    for(auto key : word) //This is equivalent to for key in word where key is an auto data type (in our case auto to char)
    { 
        if(currentNode->childNode[key-'a'] == NULL)
        {
            TrieNode* newnode = createTrieNode(key);
            currentNode->childNode[key-'a'] = newnode;
        }
        currentNode = currentNode->childNode[key-'a'];
    }
    currentNode->isWordEnd = true;
}

<<<<<<< Updated upstream
int main(){
    cout << "Hello World!\n";
=======
    transform(query.begin(),query.end(),query.begin(), ::tolower);

<<<<<<< Updated upstream
    deleteTrieNode(root,query);
=======
    printAutoComplete(root, query);
    
>>>>>>> Stashed changes
    
>>>>>>> Stashed changes
    return 0;
}