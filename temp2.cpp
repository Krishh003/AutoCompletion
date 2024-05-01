while (true) {
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
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
                case 3:
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
                case 4:
                    std::cout << "All words in the trie:" << std::endl;
                    displayTrie(root, "");
                    break;
                case 5:
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



            while (true) {
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
            std::cout << "Additional functionalities:" << std::endl;
            std::cout << "1. Insert a word" << std::endl;
            std::cout << "2. Search a word" << std::endl;
            std::cout << "3. Delete a word" << std::endl;
            std::cout << "4. Display all words" << std::endl;
            std::cout << "5. Return to main menu" << std::endl;
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
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
            break;
        case 3:
            std::cout << "Exiting program..." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
    }
}
