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
	unordered_map<string, string> hmap;
	bool success = setup_trie(root);
	bool check = setup_emoji(hmap);
	if (success && check)
	{

		string query;
		cout << "Enter query : ";
		cin >> query;
		cout << endl;

		
		printAutoComplete(root, query, hmap);
	}
	else
	{
		cout << "internal error! cannot proceed\nexiting program...";
	}

	return 0;
}
