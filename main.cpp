#include "headers/reader.h"
#include "headers/trie.h"
#include <Windows.h>
#include <iostream>
#include <unordered_map>
#include <algorithm> //used for transform function

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);

    TrieNode *root = createTrieNode('#');
    int choice, additionalChoice;
    string strchoice,stradditionalChoice;
    string word;
    unordered_map<string, string> hmap;
    bool success = setup_trie(root);
    bool check = setup_emoji(hmap);

    if(success && check) 
    {
        cout << endl << endl;
        cout << "\t\t\t© A&A Company 2024\t\t\t" << endl << endl;
        cout << "\tThe AutoComplete and AutoCorrect Program\t\t" << endl;
        while(true) 
        {   
            cout << endl  << endl;
            cout<<"********************************************************\n";
            cout << "\t\t\tMain Menu\t\t\t" << endl;
            cout << "1. Auto Complete" << endl;
            cout << "2. Auto Correct" << endl;
            cout << "3. Additional Functionalities" << endl;
            cout << "4. Exit" << endl << endl;
            cout<<"********************************************************\n";
            cout << "Enter your choice: ";
            cin >> strchoice;
            if(strchoice.length() > 1 || strchoice[0] >= 97 && strchoice[0] <= 123)
            {
                cout << "Invalid Input. Please try with valid input." << endl;
                continue;
            }
            choice = stoi(strchoice);
            cout << choice << endl;
            if(choice < 1 || choice > 4)
            {
                cout << "Enter valid input!!\n";
                continue;
            }
            
            cout << endl << endl;
            switch(choice) 
            {
                case 1:
                {
                    cout << "Enter the prefix for autocomplete: ";
                    cin >> word;
                    {
                        bool isValidInput = true;
                        for(char c : word) 
                        {
                            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) 
                            {
                                isValidInput = false;
                                break;
                            }
                        }
                        if(isValidInput) 
                        {
                            printAutoComplete(root, word,hmap);
                        } 
                        else 
                        {
                            cout << "Invalid input! Please enter a word containing only alphabets." << endl;
                        }
                    }
                    break;
                }
                case 2:
                {
                    string query;
                    cout << "Enter query: " ;
                    cin >> query;
                    string prefix = "";
                    autoCorrect(root,query,prefix);
                    break;
                }
                case 3:
                {
                    while(true) 
                    {
                        cout << "Additional Functionalities:" << endl;
                        cout << "1. Insert a word" << endl;
                        cout << "2. Delete a word" << endl;
                        cout << "3. Search for a word" << endl;
                        cout << "4. Display all words" << endl;
                        cout << "5. Display Words After Query" << endl;
                        cout << "6. Return to Main Menu" << endl;
                        cout << "7. Exit Program" << endl;
                        cout << "Enter your choice: ";
                        cin >> stradditionalChoice;
                        if(stradditionalChoice.length() > 1 || stradditionalChoice[0] >= 97 && stradditionalChoice[0] <= 123)
                        {
                            cout << "Invalid Input. Please try again with valid input" << endl;
                            continue;
                        }
                        additionalChoice = stoi(stradditionalChoice);

                        if(additionalChoice < 1 || additionalChoice > 7 )
                        {
                            cout << "Enter valid input!!\n";
                            return 1;
                        }
                        

                        switch(additionalChoice) 
                        {
                            case 1:
                            {
                                cout << "Enter the word to insert: ";
                                cin >> word;
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
                                        cout << "Invalid input! Please enter a word containing only alphabets." << endl;
                                    }
                                }
                                break;
                            }
                            case 2:
                            {
                                cout << "Enter the word to delete: ";
                                cin >> word;
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
                                        cout << "Invalid input! Please enter a word containing only alphabets." << endl;
                                    }
                                }
                                break;
                            }
                            case 3:
                            {
                                cout << "Enter the word to search: ";
                                cin >> word;
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
                                        cout << "Invalid input! Please enter a word containing only alphabets." << endl;
                                    }
                                }
                                break;
                            }
                            case 4:
                            {
                                cout << "All words in the trie:" << endl;
                                displayTrie(root, "");
                                break;
                            }
                            case 5:
                            {
                                string query;
                                string prefix;
                                cout << "Enter Query : ";
                                cin >> query;
                                displayQueryTrie(root, query, prefix);
                            }
                            case 6:
                            {
                                cout << "Returning to main menu.." << endl;
                                break; // Return to Main Menu
                            }
                            case 7:
                            {
                                cout << "Exiting program..." << endl;
                                return 0;
                            }
                            default:
                            {
                                cout << "Invalid choice. Please try again." << endl;
                            }
                        }
                        if(additionalChoice == 6)
                        {
                            break;
                        }
                    }
                    break;
                }
                case 4:
                {
                    cout << "Exiting program..." << endl;
                    return 0;
                }
                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
        }
    } 
    else 
    {
        cout << "internal error! cannot proceed\nexiting program...";
    }

  return 0;
}