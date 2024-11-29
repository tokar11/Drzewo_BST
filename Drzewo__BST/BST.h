#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/**
 * @class BST
 * @brief Klasa implementuj�ca drzewo binarne wyszukiwania (Binary Search Tree).
 * 
 * Klasa ta implementuje drzewo binarne wyszukiwania i oferuje metody do wstawiania,
 * usuwania, wy�wietlania i zapisywania element�w drzewa w r�nych porz�dkach.
 */
class BST {
private:
    /**
     * @struct Node
     * @brief Struktura reprezentuj�ca w�ze� drzewa binarnego.
     * 
     * Struktura zawiera dane oraz wska�niki do lewego i prawego dziecka.
     */
    struct Node {
        int data;  ///< Warto�� przechowywana w w�le.
        Node* left;  ///< Wska�nik na lewe dziecko w�z�a.
        Node* right;  ///< Wska�nik na prawe dziecko w�z�a.

        /**
         * @brief Konstruktor w�z�a.
         * 
         * Tworzy w�ze� z podan� warto�ci� i ustawia wska�niki na lewe i prawe dziecko na nullptr.
         * 
         * @param value Warto�� wstawiana do w�z�a.
         */
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;  ///< Wska�nik na korze� drzewa.

    /**
     * @brief Rekurencyjna funkcja do wstawiania elementu do drzewa.
     * 
     * Funkcja ta wstawia nowy w�ze� do odpowiedniego miejsca w drzewie.
     * 
     * @param node Wska�nik na bie��cy w�ze�.
     * @param value Warto�� do wstawienia.
     */
    void insert(Node*& node, int value);

    /**
     * @brief Rekurencyjna funkcja do usuwania elementu z drzewa.
     * 
     * Funkcja ta usuwa w�ze� o okre�lonej warto�ci, zachowuj�c struktur� drzewa.
     * 
     * @param node Wska�nik na bie��cy w�ze�.
     * @param value Warto�� do usuni�cia.
     * @return Wska�nik na nowy korze� (lub null, je�li drzewo jest puste).
     */
    Node* remove(Node* node, int value);

    /**
     * @brief Rekurencyjna funkcja do usuwania ca�ego drzewa.
     * 
     * Funkcja ta usuwa wszystkie w�z�y drzewa, zachowuj�c porz�dek.
     * 
     * @param node Wska�nik na bie��cy w�ze�.
     */
    void removeTree(Node*& node);

    /**
     * @brief Rekurencyjna funkcja do przej�cia drzewa w porz�dku inorder.
     * 
     * Funkcja ta przechodzi po drzewie w porz�dku inorder (lewy, korze�, prawy),
     * zapisuj�c warto�ci w wektorze wynik�w.
     * 
     * @param node Wska�nik na bie��cy w�ze�.
     * @param result Wektor wynik�w przechowuj�cy warto�ci w�z��w.
     */
    void inorder(Node* node, vector<int>& result) const;

    /**
     * @brief Rekurencyjna funkcja do przej�cia drzewa w porz�dku preorder.
     * 
     * Funkcja ta przechodzi po drzewie w porz�dku preorder (korze�, lewy, prawy),
     * zapisuj�c warto�ci w wektorze wynik�w.
     * 
     * @param node Wska�nik na bie��cy w�ze�.
     * @param result Wektor wynik�w przechowuj�cy warto�ci w�z��w.
     */
    void preorder(Node* node, vector<int>& result) const;

    /**
     * @brief Rekurencyjna funkcja do przej�cia drzewa w porz�dku postorder.
     * 
     * Funkcja ta przechodzi po drzewie w porz�dku postorder (lewy, prawy, korze�),
     * zapisuj�c warto�ci w wektorze wynik�w.
     * 
     * @param node Wska�nik na bie��cy w�ze�.
     * @param result Wektor wynik�w przechowuj�cy warto�ci w�z��w.
     */
    void postorder(Node* node, vector<int>& result) const;

    /**
     * @brief Rekurencyjna funkcja do wizualnego wy�wietlania struktury drzewa.
     * 
     * Funkcja ta wy�wietla drzewo w spos�b graficzny, pokazuj�c struktur� drzewa z uwzgl�dnieniem wci��.
     * 
     * @param node Wska�nik na bie��cy w�ze�.
     * @param indent Liczba spacji do wci�cia w zale�no�ci od poziomu g��boko�ci w�z�a.
     */
    void displayTree(Node* node, int indent = 0) const;

public:
    /**
     * @brief Konstruktor klasy BST.
     * 
     * Inicjalizuje drzewo jako puste (root = nullptr).
     */
    BST();

    /**
     * @brief Destruktor klasy BST.
     * 
     * Usuwa ca�e drzewo poprzez wywo�anie metody removeTree.
     */
    ~BST();

    /**
     * @brief Wstawia element do drzewa.
     * 
     * Funkcja wywo�uje rekurencyjn� wersj� insert, przekazuj�c root jako pocz�tkowy w�ze�.
     * 
     * @param value Warto�� do wstawienia.
     */
    void insert(int value);

    /**
     * @brief Usuwa element z drzewa.
     * 
     * Funkcja wywo�uje rekurencyjn� wersj� remove, przekazuj�c root jako pocz�tkowy w�ze�.
     * 
     * @param value Warto�� do usuni�cia.
     */
    void remove(int value);

    /**
     * @brief Usuwa ca�e drzewo.
     * 
     * Funkcja wywo�uje rekurencyjn� wersj� removeTree, aby usun�� wszystkie w�z�y drzewa.
     */
    void removeTree();

    /**
     * @brief Wy�wietla drzewo w porz�dku inorder.
     * 
     * Funkcja ta wypisuje elementy drzewa w porz�dku inorder (lewy, korze�, prawy).
     */
    void showInorder() const;

    /**
     * @brief Wy�wietla drzewo w porz�dku preorder.
     * 
     * Funkcja ta wypisuje elementy drzewa w porz�dku preorder (korze�, lewy, prawy).
     */
    void showPreorder() const;

    /**
     * @brief Wy�wietla drzewo w porz�dku postorder.
     * 
     * Funkcja ta wypisuje elementy drzewa w porz�dku postorder (lewy, prawy, korze�).
     */
    void showPostorder() const;

    /**
     * @brief Wy�wietla drzewo w formie graficznej (strukturalnej).
     * 
     * Funkcja ta wywo�uje rekurencyjn� wersj� displayTree, aby wy�wietli� struktur� ca�ego drzewa.
     */
    void displayTree() const;

    /**
     * @brief Zapisuje drzewo do pliku w okre�lonym porz�dku.
     * 
     * Funkcja zapisuje elementy drzewa do pliku w jednym z trzech porz�dk�w:
     * inorder, preorder, postorder.
     * 
     * @param filename Nazwa pliku, do kt�rego zostanie zapisane drzewo.
     * @param orderType Typ porz�dku (1 - inorder, 2 - preorder, 3 - postorder).
     */
    void saveToFile(const string& filename, int orderType) const;
};

#endif
