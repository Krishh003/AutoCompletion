#include "headers/reader.h"
#include "headers/trie.h"
#include <Windows.h>
#include <iostream>
#include <unordered_map>
#include <algorithm> //used for transform function

using namespace std;

int main() {
    // creating the root of the trie
    SetConsoleOutputCP(CP_UTF8); //for emojis
    TrieNode *root = createTrieNode('#');
    int choice;
    std::string word;
    unordered_map<string, string> hmap;
    bool success = setup_trie(root);
    bool check = setup_emoji(hmap);

    if (success && check) {
        while (true) {
            std::cout << "Menu:" << std::endl;
            std::cout << "1. Autocomplete" << std::endl;
            std::cout << "2. Additional functionalities" << std::endl;
            std::cout << "3. Exit" << std::endl;

            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Enter the prefix for autocomplete: ";
                    std::cin >> word;
                    transform(word.begin(), word.end(), word.begin(), ::tolower);
                    {
                        bool isValidInput = true;
                        for (char c : word) {
                            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                                isValidInput = false;
                                break;
                            }
                        }
                        if (isValidInput) {
                            printAutoComplete(root, word, hmap);
                        } else {
                            std::cout << "Invalid input! Please enter a word containing only alphabets." << std::endl;
                        }
                    }
                    break;
                case 2:
                    while (true) {
                        std::cout << "Additional functionalities:" << std::endl;
                        std::cout << "1. Insert a word" << std::endl;
                        std::cout << "2. Search a word" << std::endl;
                        std::cout << "3. Delete a word" << std::endl;
                        std::cout << "4. Display all words" << std::endl;
                        std::cout << "5. Return to main menu" << std::endl;
                        std::cout << "6. Exit program" << std::endl;

                        std::cout << "Enter your choice: ";
                        int additionalChoice;
                        std::cin >> additionalChoice;
                        switch (additionalChoice) {
                            case 1:
                                std::cout << "Enter the word to insert: ";
                                std::cin >> word;
                                transform(word.begin(), word.end(), word.begin(), ::tolower);
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
                                std::cout << "Enter the word to search: ";
                                std::cin >> word;
                                transform(word.begin(), word.end(), word.begin(), ::tolower);
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
                            case 3:
                                std::cout << "Enter the word to delete: ";
                                std::cin >> word;
                                transform(word.begin(), word.end(), word.begin(), ::tolower);
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
                            case 4:
                                std::cout << "All words in the trie:" << std::endl;
                                displayTrie(root, "");
                                break;
                            case 5:
                                std::cout << "Returning to main menu..." << std::endl;
                                break;
                            case 6:
                                std::cout << "Exiting program..." << std::endl;
                                return 0;
                            default:
                                std::cout << "Invalid choice. Please try again." << std::endl;
                        }

                        if (additionalChoice == 5) {
                            break; // Return to the main menu
                        }
                    }
                    break;
                case 3:
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
