/*
 * Erik Martin
 * CS 3505
 * A3 - Rule-of-Three and the Trie
 */

#include "Trie.h"

#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Default constructor
// Creates a Trie with an empty root node
Trie::Trie() {
    root = new Node();
}

// Copy constructor
// Allocates memory and copies the data
Trie::Trie(const Trie& other){
    root = other.root;
}

// Assignment= operator override
// Uses the copy-and-swap idiom
Trie& Trie::operator=(const Trie& other) {
    if(this != &other) {
        delete[] root;
        root = new Node(*other.root);
    }
    return *this;
}

// Adds a word to the Trie
void Trie::addWord(string word) {
    Node* current = root;

    // If it's an empty word, add a flag to the root
    if (word.length() == 0) {
        current->setFlag();
        return;
    }

    // Otherwise, create branches as necessary until the end of the word
    for(unsigned int i = 0; i < word.length(); i++) {
        Node* child = current->getBranch(word[i]);
        // If the branch already exists, go down a level
        if(child != NULL) {
            current = child;
        }
        // Otherwise, create a new branch and go down a level
        else {
            Node* temp = new Node();
            current->setBranch(word[i], temp);
            current = temp;
        }
    }

    // At the end of the word, add a flag to the node
    current->setFlag();
}

// Returns whether the word is in the Trie
bool Trie::isWord(string word) {
    if(word == "") {
        return false;
    }

    Node* current = root;

    if(current != NULL) {
        // Iterate through the word and descend the Trie
        for(unsigned int i = 0; i < word.length(); i++) {
            Node* temp = current->getBranch(word[i]);
            // If the next character doesn't exist, the whole word doesn't exist
            if(temp == NULL) {
                return false;
            }
            // Otherwise, more of the word exists
            current = temp;
        }

        // If the word ended on a flag, return true
        if(current->getFlag()) {
            return true;
        }
        // Otherwise, return false
        else {
            return false;
        }
    }

    // If the root is null, no words exist
    return false;
}

// Returns all words that start with the prefix
// A word that is just the prefix is acceptable
// An empty prefix returns all words in the Trie
vector<string> Trie::allWordsWithPrefix(string prefix) {
    Node* current = root;
    vector<string> words;

    if(current != NULL) { // Check for a nullptr
        // Iterate through the prefix and descend the Trie
        for(unsigned int i = 0; i < prefix.length(); i++) {
            Node* temp = current->getBranch(prefix[i]);
            // If the next character doesn't exist, the prefix doesn't exist
            if(temp == NULL) {
                return words; // Empty list
            }
            // Otherwise, more of the prefix exists
            current = temp;
        }

        // Now that the prefix has finished, return all branched words
        traverse(prefix, current, words);
        return words;
    }

    // If the root is null, no words exist
    return words; // Empty list
}

vector<string> Trie::wordsWithWildcardPrefix(string prefix) {
    return vector<string>();
}

// Helper for allWordsWithPrefix
void Trie::traverse(string& prefix, Node* node, vector<string>& words) {
    if(node == NULL) { // Check for nullptr
        return;
    }

    // If we are at the end of a word, add it to the list
    if(node->getFlag()) {
        words.push_back(prefix);
    }

    // Check for branches
    for(char index = 0; index < 26; index++) {
        char c = 'a' + index;
        Node* branch = node->getBranch(c);
        // If there is a branch, add the corresponding character to the prefix,
        // and traverse down the Trie.
        if(branch != NULL) {
            prefix.push_back(c);
            traverse(prefix, branch, words);
            prefix.pop_back();
        }
    }
}

// Destructor
Trie::~Trie() {
    cout << "Destructing Trie" << endl;
    delete[] root;
}
