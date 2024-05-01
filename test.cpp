#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Trie node structure
struct TrieNode {
    char value;
    int frequency;
    bool isWordEnd;
    TrieNode* childNode[26]; // Assuming only lowercase English letters
    TrieNode* highestFreqNode[5]; // Array to store top 5 frequent nodes
};

// Function to initialize a new TrieNode
TrieNode* createNode(char value) {
    TrieNode* newNode = new TrieNode();
    newNode->value = value;
    newNode->frequency = 0;
    newNode->isWordEnd = false;
    for (int i = 0; i < 26; ++i) {
        newNode->childNode[i] = nullptr;
    }
    for (int i = 0; i < 5; ++i) {
        newNode->highestFreqNode[i] = nullptr;
    }
    return newNode;
}

// Function to insert a word into the trie
void insertWord(TrieNode* root, string word) {
    TrieNode* current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (current->childNode[index] == nullptr) {
            current->childNode[index] = createNode(ch);
        }
        current = current->childNode[index];
        current->frequency++; // Increment frequency for the word
    }
    current->isWordEnd = true;

}

// DFS traversal to update the top 5 frequent nodes at each trie node
void dfsUpdateTopFrequentNodes(TrieNode* node, vector<TrieNode*>& topNodes) {
    if (node == nullptr) return;

    // Update top 5 frequent nodes at this node
    for (int i = 0; i < 5; ++i) {
        if (node->highestFreqNode[i] == nullptr || 
            node->frequency > node->highestFreqNode[i]->frequency) {
            for (int j = 4; j > i; --j) {
                node->highestFreqNode[j] = node->highestFreqNode[j - 1];
            }
            node->highestFreqNode[i] = node;
            break;
        }
    }

    // Visit child nodes
    for (int i = 0; i < 26; ++i) {
        dfsUpdateTopFrequentNodes(node->childNode[i], topNodes);
    }
}

// Function to initialize and update top 5 frequent nodes in the trie
void updateTopFrequentNodes(TrieNode* root) {
    vector<TrieNode*> topNodes;
    dfsUpdateTopFrequentNodes(root, topNodes);
}

int main() {
    // Example usage
    TrieNode* root = createNode('/'); // Root node

    // Insert some words into the trie
    insertWord(root, "hello");
    insertWord(root, "world");
    insertWord(root, "hi");
    insertWord(root, "hello");
    insertWord(root, "world");
    insertWord(root, "hello");
    insertWord(root, "welcome");
    insertWord(root, "hi");

    // Update top 5 frequent nodes
    updateTopFrequentNodes(root);

    // Access top 5 frequent nodes at root
    cout << "Top 5 frequent nodes at root:" << endl;
    for (int i = 0; i < 5; ++i) {
        if (root->highestFreqNode[i] != nullptr) {
            cout << root->highestFreqNode[i]->value << " Frequency: " << root->highestFreqNode[i]->frequency << endl;
        }
    }

    return 0;
}
