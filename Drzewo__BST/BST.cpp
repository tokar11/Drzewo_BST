#include "BST.h"
#include <iomanip>

/**
 * @class BST
 * @brief Implementacja drzewa BST (Binary Search Tree).
 *
 * Ta klasa implementuje drzewo binarne wyszukiwania, oferuj¹c operacje takie jak:
 * wstawianie, usuwanie, oraz wyœwietlanie drzewa w ró¿nych porz¹dkach (inorder, preorder, postorder).
 */
BST::BST() : root(nullptr) {}

/**
 * @brief Destruktor klasy BST.
 *
 * Usuwa ca³e drzewo binarne poprzez wywo³anie metody removeTree.
 */
BST::~BST() {
    removeTree();
}

/**
 * @brief Rekurencyjna funkcja do wstawiania elementu do drzewa.
 *
 * Funkcja ta wstawia nowy wêze³ z podan¹ wartoœci¹ do odpowiedniego miejsca w drzewie.
 *
 * @param node WskaŸnik na bie¿¹cy wêze³.
 * @param value Wartoœæ do wstawienia.
 */
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

/**
 * @brief Wstawia element do drzewa.
 *
 * Funkcja wywo³uje rekurencyjn¹ wersjê insert, przekazuj¹c root jako pocz¹tkowy wêze³.
 *
 * @param value Wartoœæ do wstawienia.
 */
void BST::insert(int value) {
    insert(root, value);
}

/**
 * @brief Rekurencyjna funkcja do usuwania elementu z drzewa.
 *
 * Funkcja ta usuwa wêze³ o okreœlonej wartoœci, zachowuj¹c strukturê drzewa.
 *
 * @param node WskaŸnik na bie¿¹cy wêze³.
 * @param value Wartoœæ do usuniêcia.
 * @return WskaŸnik na nowy korzeñ (lub null, jeœli drzewo jest puste).
 */
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
            node->data = successor->data;
            node->right = remove(node->right, successor->data);
        }
    }
    return node;
}

/**
 * @brief Usuwa element z drzewa.
 *
 * Funkcja wywo³uje rekurencyjn¹ wersjê remove, przekazuj¹c root jako pocz¹tkowy wêze³.
 *
 * @param value Wartoœæ do usuniêcia.
 */
void BST::remove(int value) {
    root = remove(root, value);
}

/**
 * @brief Rekurencyjna funkcja do usuwania ca³ego drzewa.
 *
 * Funkcja ta usuwa wszystkie wêz³y drzewa, zachowuj¹c porz¹dek.
 *
 * @param node WskaŸnik na bie¿¹cy wêze³.
 */
void BST::removeTree(Node*& node) {
    if (!node) return;
    removeTree(node->left);
    removeTree(node->right);
    delete node;
    node = nullptr;
}

/**
 * @brief Usuwa ca³e drzewo.
 *
 * Funkcja wywo³uje rekurencyjn¹ wersjê removeTree, przekazuj¹c root jako pocz¹tkowy wêze³.
 */
void BST::removeTree() {
    removeTree(root);
}

/**
 * @brief Rekurencyjna funkcja do przejœcia drzewa w porz¹dku inorder.
 *
 * Funkcja ta przechodzi po drzewie w porz¹dku inorder (lewy, korzeñ, prawy),
 * zapisuj¹c wartoœci w wektorze wyników.
 *
 * @param node WskaŸnik na bie¿¹cy wêze³.
 * @param result Wektor wyników przechowuj¹cy wartoœci wêz³ów.
 */
void BST::inorder(Node* node, vector<int>& result) const {
    if (!node) return;
    inorder(node->left, result);
    result.push_back(node->data);
    inorder(node->right, result);
}

/**
 * @brief Rekurencyjna funkcja do przejœcia drzewa w porz¹dku preorder.
 *
 * Funkcja ta przechodzi po drzewie w porz¹dku preorder (korzeñ, lewy, prawy),
 * zapisuj¹c wartoœci w wektorze wyników.
 *
 * @param node WskaŸnik na bie¿¹cy wêze³.
 * @param result Wektor wyników przechowuj¹cy wartoœci wêz³ów.
 */
void BST::preorder(Node* node, vector<int>& result) const {
    if (!node) return;
    result.push_back(node->data);
    preorder(node->left, result);
    preorder(node->right, result);
}

/**
 * @brief Rekurencyjna funkcja do przejœcia drzewa w porz¹dku postorder.
 *
 * Funkcja ta przechodzi po drzewie w porz¹dku postorder (lewy, prawy, korzeñ),
 * zapisuj¹c wartoœci w wektorze wyników.
 *
 * @param node WskaŸnik na bie¿¹cy wêze³.
 * @param result Wektor wyników przechowuj¹cy wartoœci wêz³ów.
 */
void BST::postorder(Node* node, vector<int>& result) const {
    if (!node) return;
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->data);
}

/**
 * @brief Wyœwietla drzewo w porz¹dku inorder.
 *
 * Funkcja ta wypisuje elementy drzewa w porz¹dku inorder (lewy, korzeñ, prawy).
 */
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

/**
 * @brief Wyœwietla drzewo w porz¹dku preorder.
 *
 * Funkcja ta wypisuje elementy drzewa w porz¹dku preorder (korzeñ, lewy, prawy).
 */
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

/**
 * @brief Wyœwietla drzewo w porz¹dku postorder.
 *
 * Funkcja ta wypisuje elementy drzewa w porz¹dku postorder (lewy, prawy, korzeñ).
 */
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

/**
 * @brief Wyœwietla drzewo w formie graficznej (strukturalnej).
 *
 * Funkcja ta wyœwietla drzewo w sposób wizualny, pokazuj¹c jego strukturê.
 *
 * @param node WskaŸnik na bie¿¹cy wêze³.
 * @param indent Liczba spacji do wciêcia w zale¿noœci od poziomu g³êbokoœci wêz³a.
 */
void BST::displayTree(Node* node, int indent) const {
    if (!node) return;

    if (node->right) displayTree(node->right, indent + 4);

    if (indent)
        cout << setw(indent) << " ";
    cout << node->data << "\n";

    if (node->left) displayTree(node->left, indent + 4);
}

/**
 * @brief Wyœwietla drzewo w formie graficznej.
 *
 * Funkcja ta wywo³uje rekurencyjn¹ wersjê displayTree, aby wyœwietliæ strukturê ca³ego drzewa.
 */
void BST::displayTree() const {
    if (!root) {
        cout << "BST tree is empty.\n";
        return;
    }
    displayTree(root);
}

/**
 * @brief Zapisuje drzewo do pliku w okreœlonym porz¹dku.
 *
 * Funkcja zapisuje elementy drzewa do pliku w jednym z trzech porz¹dków:
 * inorder, preorder, postorder.
 *
 * @param filename Nazwa pliku, do którego zostanie zapisane drzewo.
 * @param orderType Typ porz¹dku (1 - inorder, 2 - preorder, 3 - postorder).
 */
void BST::saveToFile(const string& filename, int orderType) const {
    if (!root) {
        cout << "BST tree is empty. Can't save to file.\n";
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
        cerr << "Can't open file.\n";
        return;
    }

    for (int value : result)
        file << value << " ";
    file.close();

    cout << "BST tree has been saved to file: " << filename << endl;
}
