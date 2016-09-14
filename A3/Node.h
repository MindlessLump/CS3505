/*
 * Erik Martin
 * CS 3505
 * A3 - Rule-of-Three and the Trie
 */

#include <vector>
using namespace std;

class Node {
    bool flag; // Whether the node is a leaf
    vector<Node*> branches; // Branches (children) of this node

public:
    Node(); // Default constructor
    ~Node(); // Destructor
    Node(const Node& other); // Copy-constructor
    Node& operator=(const Node& other); // assignment= operator override
    bool getFlag(); // Returns the flag
    void setFlag(); // Sets the end-of-word flag to true
    Node* getBranch(char c); // Returns a branch with the given content, if any
    void setBranch(char c, Node* branch); // Adds a branch to this node
    vector<Node*> getBranches(); // Returns the branches of this node
};
