#include "BST.h"
#include <iomanip>

BST::BST() : root(nullptr) {}

BST::~BST() {
    removeTree();
}

void BST::insert(Node*& node, int value) {
    if (!node) {
        node = new Node(value);
        return;
    }
    if (value < node->data)
        insert(node->left, value);
    else
        insert(node->right, value);
}

void BST::insert(int value) {
    insert(root, value);
}

BST::Node* BST::remove(Node* node, int value) {
    if (!node) return nullptr;

    if (value < node->data) {
        node->left = remove(node->left, value);
    }
    else if (value > node->data) {
        node->right = remove(node->right, value);
    }
    else {
        if (!node->left) {
            Node* rightChild = node->right;
            delete node;
            return rightChild;
        }
        else if (!node->right) {
            Node* leftChild = node->left;
            delete node;
            return leftChild;
        }
        else {
            Node* successor = node->right;
            while (successor->left)
                successor = successor->left;
            node->data = successor->data
            node->right = remove(node->right, successor->data);
        }
    }
    return node;
}

void BST::remove(int value) {
    root = remove(root, value);
}

void BST::removeTree(Node*& node) {
    if (!node) return;
    removeTree(node->left); 
    removeTree(node->right);
    delete node;
    node = nullptr;
}

void BST::removeTree() {
    removeTree(root);
}

void BST::inorder(Node* node, vector<int>& result) const {
    if (!node) return;
    inorder(node->left, result);
    result.push_back(node->data); 
    inorder(node->right, result);
}

void BST::preorder(Node* node, vector<int>& result) const {
    if (!node) return;
    result.push_back(node->data);
    preorder(node->left, result);
    preorder(node->right, result);
}

void BST::postorder(Node* node, vector<int>& result) const {
    if (!node) return;
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->data);
}

void BST::showInorder() const {
    if (!root) {
        cout << "BST tree is empty.\n";
        return;
    }
    vector<int> result;
    inorder(root, result);
    for (int value : result)
        cout << value << " ";
    cout << endl;
}

void BST::showPreorder() const {
    if (!root) {
        cout << "BST tree is empty.\n";
        return;
    }
    vector<int> result;
    preorder(root, result);
    for (int value : result)
        cout << value << " ";
    cout << endl;
}

void BST::showPostorder() const {
    if (!root) {
        cout << "BST tree is empty.\n";
        return;
    }
    vector<int> result;
    postorder(root, result);
    for (int value : result)
        cout << value << " ";
    cout << endl;
}

void BST::displayTree(Node* node, int indent) const {
    if (!node) return;

    if (node->right) displayTree(node->right, indent + 4);

    if (indent)
        cout << setw(indent) << " ";
    cout << node->data << "\n";

    if (node->left) displayTree(node->left, indent + 4);
}

void BST::displayTree() const {
    if (!root) {
        cout << "BST tree is empty.\n";
        return;
    }
    displayTree(root);
}

void BST::saveToFile(const string& filename, int orderType) const {
    if (!root) {
        cout << "BST tree is empty.Can't save to file.\n";
        return;
    }

    vector<int> result;
    switch (orderType) {
    case 1:
        inorder(root, result);
        break;
    case 2:
        preorder(root, result);
        break;
    case 3:
        postorder(root, result);
        break;
    default:
        cerr << "Incorrect type to save\n";
        return;
    }

    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Cant open file.\n";
        return;
    }

    for (int value : result)
        file << value << " ";
    file.close();

    cout << "BST tree has been saved to file: " << filename << endl;
}
