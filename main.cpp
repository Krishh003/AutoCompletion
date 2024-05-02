#include "headers/reader.h"
#include "headers/trie.h"
#include <Windows.h>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	// creating the root of the trie
    TrieNode *root = createTrieNode('#');
    int choice;
    std::string word;
    unordered_map<string, string> hmap;
    bool success = setup_trie(root);
    bool check = setup_emoji(hmap);

    if (success && check) 
    {
        while (true) 
        {
    std::cout << "Main Menu:" << std::endl;
    std::cout << "1. Auto Complete" << std::endl;
    std::cout << "2. Auto Correct" << std::endl;
    std::cout << "3. Additional Functionalities" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) 
    {
        case 1:
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
        case 2:
        {
            std::string query;
            cout << "Enter query: " ;
            cin >> query;
            std::string prefix = "";
            autocorrect(root,query,prefix);
        }
        case 3:
        {
            while(true) 
            {
                std::cout << "Additional Functionalities:" << std::endl;
                std::cout << "1. Insert a word" << std::endl;
                std::cout << "2. Delete a word" << std::endl;
                std::cout << "3. Search for a word" << std::endl;
                std::cout << "4. Display all words" << std::endl;
                std::cout << "5. Return to Main Menu" << std::endl;
                std::cout << "6. Exit Program" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> choice;

                switch (choice) 
                {
                    case 1:
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
                        break; // Return to Main Menu
                    case 6:
                        std::cout << "Exiting program..." << std::endl;
                        return 0;
                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                }
                if (choice == 5) break;
            }
            break;
        }
        case 4:
        {
            std::cout << "Exiting program..." << std::endl;
            return 0;
        }
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
    }
}


    } 
    else 
    {
        cout << "internal error! cannot proceed\nexiting program...";
    }

	return 0;
}