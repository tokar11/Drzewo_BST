#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, int value);
    Node* remove(Node* node, int value);
    void removeTree(Node*& node);
    void inorder(Node* node, vector<int>& result) const;
    void preorder(Node* node, vector<int>& result) const;
    void postorder(Node* node, vector<int>& result) const;
    void displayTree(Node* node, int indent = 0) const;

public:
    BST();
    ~BST();

    void insert(int value);
    void remove(int value);
    void removeTree();
    void showInorder() const;
    void showPreorder() const;
    void showPostorder() const;
    void displayTree() const;
    void saveToFile(const string& filename, int orderType) const;
};

#endif
