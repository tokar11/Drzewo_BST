#include "BST.h"
#include <iomanip>

/**
 * @class BST
 * @brief Implementacja drzewa BST (Binary Search Tree).
 *
 * Ta klasa implementuje drzewo binarne wyszukiwania, oferuj�c operacje takie jak:
 * wstawianie, usuwanie, oraz wy�wietlanie drzewa w r�nych porz�dkach (inorder, preorder, postorder).
 */
BST::BST() : root(nullptr) {}

/**
 * @brief Destruktor klasy BST.
 *
 * Usuwa ca�e drzewo binarne poprzez wywo�anie metody removeTree.
 */
BST::~BST() {
    removeTree();
}

/**
 * @brief Rekurencyjna funkcja do wstawiania elementu do drzewa.
 *
 * Funkcja ta wstawia nowy w�ze� z podan� warto�ci� do odpowiedniego miejsca w drzewie.
 *
 * @param node Wska�nik na bie��cy w�ze�.
 * @param value Warto�� do wstawienia.
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
 * Funkcja wywo�uje rekurencyjn� wersj� insert, przekazuj�c root jako pocz�tkowy w�ze�.
 *
 * @param value Warto�� do wstawienia.
 */
void BST::insert(int value) {
    insert(root, value);
}

/**
 * @brief Rekurencyjna funkcja do usuwania elementu z drzewa.
 *
 * Funkcja ta usuwa w�ze� o okre�lonej warto�ci, zachowuj�c struktur� drzewa.
 *
 * @param node Wska�nik na bie��cy w�ze�.
 * @param value Warto�� do usuni�cia.
 * @return Wska�nik na nowy korze� (lub null, je�li drzewo jest puste).
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
 * Funkcja wywo�uje rekurencyjn� wersj� remove, przekazuj�c root jako pocz�tkowy w�ze�.
 *
 * @param value Warto�� do usuni�cia.
 */
void BST::remove(int value) {
    root = remove(root, value);
}

/**
 * @brief Rekurencyjna funkcja do usuwania ca�ego drzewa.
 *
 * Funkcja ta usuwa wszystkie w�z�y drzewa, zachowuj�c porz�dek.
 *
 * @param node Wska�nik na bie��cy w�ze�.
 */
void BST::removeTree(Node*& node) {
    if (!node) return;
    removeTree(node->left);
    removeTree(node->right);
    delete node;
    node = nullptr;
}

/**
 * @brief Usuwa ca�e drzewo.
 *
 * Funkcja wywo�uje rekurencyjn� wersj� removeTree, przekazuj�c root jako pocz�tkowy w�ze�.
 */
void BST::removeTree() {
    removeTree(root);
}

/**
 * @brief Rekurencyjna funkcja do przej�cia drzewa w porz�dku inorder.
 *
 * Funkcja ta przechodzi po drzewie w porz�dku inorder (lewy, korze�, prawy),
 * zapisuj�c warto�ci w wektorze wynik�w.
 *
 * @param node Wska�nik na bie��cy w�ze�.
 * @param result Wektor wynik�w przechowuj�cy warto�ci w�z��w.
 */
void BST::inorder(Node* node, vector<int>& result) const {
    if (!node) return;
    inorder(node->left, result);
    result.push_back(node->data);
    inorder(node->right, result);
}

/**
 * @brief Rekurencyjna funkcja do przej�cia drzewa w porz�dku preorder.
 *
 * Funkcja ta przechodzi po drzewie w porz�dku preorder (korze�, lewy, prawy),
 * zapisuj�c warto�ci w wektorze wynik�w.
 *
 * @param node Wska�nik na bie��cy w�ze�.
 * @param result Wektor wynik�w przechowuj�cy warto�ci w�z��w.
 */
void BST::preorder(Node* node, vector<int>& result) const {
    if (!node) return;
    result.push_back(node->data);
    preorder(node->left, result);
    preorder(node->right, result);
}

/**
 * @brief Rekurencyjna funkcja do przej�cia drzewa w porz�dku postorder.
 *
 * Funkcja ta przechodzi po drzewie w porz�dku postorder (lewy, prawy, korze�),
 * zapisuj�c warto�ci w wektorze wynik�w.
 *
 * @param node Wska�nik na bie��cy w�ze�.
 * @param result Wektor wynik�w przechowuj�cy warto�ci w�z��w.
 */
void BST::postorder(Node* node, vector<int>& result) const {
    if (!node) return;
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->data);
}

/**
 * @brief Wy�wietla drzewo w porz�dku inorder.
 *
 * Funkcja ta wypisuje elementy drzewa w porz�dku inorder (lewy, korze�, prawy).
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
 * @brief Wy�wietla drzewo w porz�dku preorder.
 *
 * Funkcja ta wypisuje elementy drzewa w porz�dku preorder (korze�, lewy, prawy).
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
 * @brief Wy�wietla drzewo w porz�dku postorder.
 *
 * Funkcja ta wypisuje elementy drzewa w porz�dku postorder (lewy, prawy, korze�).
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
 * @brief Wy�wietla drzewo w formie graficznej (strukturalnej).
 *
 * Funkcja ta wy�wietla drzewo w spos�b wizualny, pokazuj�c jego struktur�.
 *
 * @param node Wska�nik na bie��cy w�ze�.
 * @param indent Liczba spacji do wci�cia w zale�no�ci od poziomu g��boko�ci w�z�a.
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
 * @brief Wy�wietla drzewo w formie graficznej.
 *
 * Funkcja ta wywo�uje rekurencyjn� wersj� displayTree, aby wy�wietli� struktur� ca�ego drzewa.
 */
void BST::displayTree() const {
    if (!root) {
        cout << "BST tree is empty.\n";
        return;
    }
    displayTree(root);
}

/**
 * @brief Zapisuje drzewo do pliku w okre�lonym porz�dku.
 *
 * Funkcja zapisuje elementy drzewa do pliku w jednym z trzech porz�dk�w:
 * inorder, preorder, postorder.
 *
 * @param filename Nazwa pliku, do kt�rego zostanie zapisane drzewo.
 * @param orderType Typ porz�dku (1 - inorder, 2 - preorder, 3 - postorder).
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
