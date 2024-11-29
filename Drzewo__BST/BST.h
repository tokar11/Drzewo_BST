#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/**
 * @class BST
 * @brief Klasa implementuj¹ca drzewo binarne wyszukiwania (Binary Search Tree).
 * 
 * Klasa ta implementuje drzewo binarne wyszukiwania i oferuje metody do wstawiania,
 * usuwania, wyœwietlania i zapisywania elementów drzewa w ró¿nych porz¹dkach.
 */
class BST {
private:
    /**
     * @struct Node
     * @brief Struktura reprezentuj¹ca wêze³ drzewa binarnego.
     * 
     * Struktura zawiera dane oraz wskaŸniki do lewego i prawego dziecka.
     */
    struct Node {
        int data;  ///< Wartoœæ przechowywana w wêŸle.
        Node* left;  ///< WskaŸnik na lewe dziecko wêz³a.
        Node* right;  ///< WskaŸnik na prawe dziecko wêz³a.

        /**
         * @brief Konstruktor wêz³a.
         * 
         * Tworzy wêze³ z podan¹ wartoœci¹ i ustawia wskaŸniki na lewe i prawe dziecko na nullptr.
         * 
         * @param value Wartoœæ wstawiana do wêz³a.
         */
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;  ///< WskaŸnik na korzeñ drzewa.

    /**
     * @brief Rekurencyjna funkcja do wstawiania elementu do drzewa.
     * 
     * Funkcja ta wstawia nowy wêze³ do odpowiedniego miejsca w drzewie.
     * 
     * @param node WskaŸnik na bie¿¹cy wêze³.
     * @param value Wartoœæ do wstawienia.
     */
    void insert(Node*& node, int value);

    /**
     * @brief Rekurencyjna funkcja do usuwania elementu z drzewa.
     * 
     * Funkcja ta usuwa wêze³ o okreœlonej wartoœci, zachowuj¹c strukturê drzewa.
     * 
     * @param node WskaŸnik na bie¿¹cy wêze³.
     * @param value Wartoœæ do usuniêcia.
     * @return WskaŸnik na nowy korzeñ (lub null, jeœli drzewo jest puste).
     */
    Node* remove(Node* node, int value);

    /**
     * @brief Rekurencyjna funkcja do usuwania ca³ego drzewa.
     * 
     * Funkcja ta usuwa wszystkie wêz³y drzewa, zachowuj¹c porz¹dek.
     * 
     * @param node WskaŸnik na bie¿¹cy wêze³.
     */
    void removeTree(Node*& node);

    /**
     * @brief Rekurencyjna funkcja do przejœcia drzewa w porz¹dku inorder.
     * 
     * Funkcja ta przechodzi po drzewie w porz¹dku inorder (lewy, korzeñ, prawy),
     * zapisuj¹c wartoœci w wektorze wyników.
     * 
     * @param node WskaŸnik na bie¿¹cy wêze³.
     * @param result Wektor wyników przechowuj¹cy wartoœci wêz³ów.
     */
    void inorder(Node* node, vector<int>& result) const;

    /**
     * @brief Rekurencyjna funkcja do przejœcia drzewa w porz¹dku preorder.
     * 
     * Funkcja ta przechodzi po drzewie w porz¹dku preorder (korzeñ, lewy, prawy),
     * zapisuj¹c wartoœci w wektorze wyników.
     * 
     * @param node WskaŸnik na bie¿¹cy wêze³.
     * @param result Wektor wyników przechowuj¹cy wartoœci wêz³ów.
     */
    void preorder(Node* node, vector<int>& result) const;

    /**
     * @brief Rekurencyjna funkcja do przejœcia drzewa w porz¹dku postorder.
     * 
     * Funkcja ta przechodzi po drzewie w porz¹dku postorder (lewy, prawy, korzeñ),
     * zapisuj¹c wartoœci w wektorze wyników.
     * 
     * @param node WskaŸnik na bie¿¹cy wêze³.
     * @param result Wektor wyników przechowuj¹cy wartoœci wêz³ów.
     */
    void postorder(Node* node, vector<int>& result) const;

    /**
     * @brief Rekurencyjna funkcja do wizualnego wyœwietlania struktury drzewa.
     * 
     * Funkcja ta wyœwietla drzewo w sposób graficzny, pokazuj¹c strukturê drzewa z uwzglêdnieniem wciêæ.
     * 
     * @param node WskaŸnik na bie¿¹cy wêze³.
     * @param indent Liczba spacji do wciêcia w zale¿noœci od poziomu g³êbokoœci wêz³a.
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
     * Usuwa ca³e drzewo poprzez wywo³anie metody removeTree.
     */
    ~BST();

    /**
     * @brief Wstawia element do drzewa.
     * 
     * Funkcja wywo³uje rekurencyjn¹ wersjê insert, przekazuj¹c root jako pocz¹tkowy wêze³.
     * 
     * @param value Wartoœæ do wstawienia.
     */
    void insert(int value);

    /**
     * @brief Usuwa element z drzewa.
     * 
     * Funkcja wywo³uje rekurencyjn¹ wersjê remove, przekazuj¹c root jako pocz¹tkowy wêze³.
     * 
     * @param value Wartoœæ do usuniêcia.
     */
    void remove(int value);

    /**
     * @brief Usuwa ca³e drzewo.
     * 
     * Funkcja wywo³uje rekurencyjn¹ wersjê removeTree, aby usun¹æ wszystkie wêz³y drzewa.
     */
    void removeTree();

    /**
     * @brief Wyœwietla drzewo w porz¹dku inorder.
     * 
     * Funkcja ta wypisuje elementy drzewa w porz¹dku inorder (lewy, korzeñ, prawy).
     */
    void showInorder() const;

    /**
     * @brief Wyœwietla drzewo w porz¹dku preorder.
     * 
     * Funkcja ta wypisuje elementy drzewa w porz¹dku preorder (korzeñ, lewy, prawy).
     */
    void showPreorder() const;

    /**
     * @brief Wyœwietla drzewo w porz¹dku postorder.
     * 
     * Funkcja ta wypisuje elementy drzewa w porz¹dku postorder (lewy, prawy, korzeñ).
     */
    void showPostorder() const;

    /**
     * @brief Wyœwietla drzewo w formie graficznej (strukturalnej).
     * 
     * Funkcja ta wywo³uje rekurencyjn¹ wersjê displayTree, aby wyœwietliæ strukturê ca³ego drzewa.
     */
    void displayTree() const;

    /**
     * @brief Zapisuje drzewo do pliku w okreœlonym porz¹dku.
     * 
     * Funkcja zapisuje elementy drzewa do pliku w jednym z trzech porz¹dków:
     * inorder, preorder, postorder.
     * 
     * @param filename Nazwa pliku, do którego zostanie zapisane drzewo.
     * @param orderType Typ porz¹dku (1 - inorder, 2 - preorder, 3 - postorder).
     */
    void saveToFile(const string& filename, int orderType) const;
};

#endif
