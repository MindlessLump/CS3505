/*
 * Erik Martin
 * CS 3505
 * A3 - Rule-of-Three and the Trie
 */

#include "Trie.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
  {
    // Parse command-line arguments
    // argv[0] is "TrieTest"
    // argv[1] is the filename for the dictionary
    // argv[2] is the filename for the queries
    if(argc < 3) {
        cout << "Missing filename(s)." << endl;
        return 0;
    }
    else {
        string fnameWords = argv[1];
        string fnameQueries = argv[2];

        // Put the words into the Trie
        Trie trie;
        ifstream wfile(fnameWords);
        string word;
        while(getline(wfile, word)) {
            trie.addWord(word);
        }

        // Test each of the queries
        ifstream qfile(fnameQueries);
        while(getline(qfile, word)) {
            if(trie.isWord(word)) {
                // Word successfully found
                cout << word << " is found." << endl;
            }
            else {
                cout << word << " is not found, did you mean:" << endl;
                vector<string> words = trie.allWordsWithPrefix(word);
                if(words.size() > 0) {
                    // Word not found, but there are alternatives
                    vector<string>::iterator it;
                    for(it = words.begin(); it < words.end(); it++) {
                        cout << "   " << *it << endl;
                    }
                }
                else {
                    // Word not found, and no alternatives
                    cout << "   no alternatives found" << endl;
                }
            }
        }
    }
  }
  cout << "Trie successfully destructed." << endl;
}
