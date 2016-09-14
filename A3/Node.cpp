/*
 * Erik Martin
 * CS 3505
 * A3 - Rule-of-Three and the Trie
 */

#include "Node.h"

#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Default constructor
Node::Node() {
    flag = false;
    vector<Node*> temp(26);
    branches = temp;
}

// Copy-constructor
Node::Node(const Node& other)
    : flag(other.flag) {
    for(unsigned i = 0; i < branches.size(); i++) {
        delete branches[i];
        branches[i] = other.branches[i];
    }
}

// Assignment= operator override
Node& Node::operator=(const Node& other) {
    if(this != &other) {
        flag = other.flag;
        vector<Node*> temp(26);
        for(int i = 0; i < 26; i++) {
            temp[i] = other.branches[i];
            delete branches[i];
        }
        branches = temp;
    }
    return *this;
}

// Returns the end-of-word flag
bool Node::getFlag() {
    return flag;
}

// Sets the end-of-word flag to true
void Node::setFlag() {
    flag = true;
}

// Returns a branch with the given content, if any exists
// Otherwise, it returns NULL
Node* Node::getBranch(char c) {
    int index = (int)c - (int)'a';
    return branches[index];
}

// Sets the branch for the character
void Node::setBranch(char c, Node* branch) {
    int index = (int)c - (int)'a';
    delete branches[index];
    branches[index] = branch;
}

// Returns the branches of this node
vector<Node*> Node::getBranches() {
    return branches;
}

// Destructor
Node::~Node() {
    cout << "Destructing node" << endl;
    delete &flag;
    for(unsigned int i = 0; i < branches.size(); i++) {
        delete branches[i];
    }
    delete &branches;
}
