#include "BST.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Główna funkcja programu, która implementuje menu do obsługi drzewa BST.
 *
 * Program umożliwia użytkownikowi wykonywanie operacji na drzewie binarnym wyszukiwania,
 * takich jak dodawanie, usuwanie elementów, wyświetlanie drzewa, zapisywanie drzewa do pliku
 * oraz usuwanie całego drzewa. Użytkownik wybiera operacje z menu.
 *
 * Funkcja działa w pętli, która trwa do momentu wybrania opcji "Exit".
 *
 * @return Zwraca 0 po zakończeniu działania programu.
 */
int main() {
    BST tree;  ///< Obiekt klasy BST, reprezentujący drzewo binarne wyszukiwania.
    int choice, value, orderType;  ///< Zmienna wyboru operacji, wartości do wstawienia/usunięcia, typ porządku do zapisu.
    string filename;  ///< Zmienna przechowująca nazwę pliku do zapisu.

    // Główna pętla programu z menu do wyboru operacji
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add element\n";
        cout << "2. Delete element\n";
        cout << "3. Delete BST Tree\n";
        cout << "4. Show BST Tree\n";
        cout << "5. Show Inorder, Preorder, Postorder\n";
        cout << "6. Save to file\n";
        cout << "7. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        // Obsługa wyboru użytkownika
        switch (choice) {
        case 1:
            // Dodawanie elementu
            cout << "Enter value to be added : ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            // Usuwanie elementu
            cout << "Enter value to be deleted: ";
            cin >> value;
            tree.remove(value);
            break;

        case 3:
            // Usuwanie całego drzewa
            tree.removeTree();
            cout << "BST Tree has been removed \n";
            break;

        case 4:
            // Wyświetlanie drzewa
            tree.displayTree();
            break;

        case 5:
            // Wyświetlanie elementów w porządku inorder, preorder, postorder
            cout << "1-Inorder, 2-Preorder, 3-Postorder: ";
            cin >> orderType;
            if (orderType == 1)
                tree.showInorder();
            else if (orderType == 2)
                tree.showPreorder();
            else if (orderType == 3)
                tree.showPostorder();
            else
                cout << "Incorrect choice!\n";
            break;

        case 6:
            // Zapis drzewa do pliku
            cout << "Enter file name: ";
            cin >> filename;
            cout << "1-Inorder, 2-Preorder, 3-Postorder: ";
            cin >> orderType;
            tree.saveToFile(filename, orderType);
            break;

        case 7:
            // Zakończenie programu
            cout << "The end\n";
            return 0;

        default:
            // Obsługa błędnego wyboru
            cout << "Incorrect choice!\n";
            break;
        }
    }
}
