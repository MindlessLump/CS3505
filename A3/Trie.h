/*
 * Erik Martin
 * CS 3505
 * A3 - Rule-of-Three and the Trie
 */

#include "Node.h"
#include <vector>
#include <string>
using namespace std;

class Trie {
private:
    Node *root; // Root node
    void traverse(string& prefix, Node* node, vector<string>& words); // Helper for allWordsWithPrefix

public:
    Trie(); // Default constructor
    ~Trie(); // Destructor
    Trie(const Trie& other); // Copy-constructor
    Trie& operator=(const Trie& other); // assignment= operator override
    void addWord(string word); // Adds a word to the Trie
    bool isWord(string word); // Returns whether the word is in the Trie
    vector<string> allWordsWithPrefix(string prefix); // Returns all words that start with the prefix
    vector<string> wordsWithWildcardPrefix(string prefix); // Advanced method
};
