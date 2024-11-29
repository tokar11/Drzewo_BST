#include "BST.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    BST tree;
    int choice, value, orderType;
    string filename;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Dodaj element\n";
        cout << "2. Usun element\n";
        cout << "3. Usun cale drzewo\n";
        cout << "4. Pokaz drzewo (graficznie)\n";
        cout << "5. Pokaz Inorder/Preorder/Postorder\n";
        cout << "6. Zapisz drzewo do pliku\n";
        cout << "7. Wyjdz\n";
        cout << "Wybor: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Podaj wartosc do dodania: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "Podaj wartosc do usuniecia: ";
            cin >> value;
            tree.remove(value);
            break;

        case 3:
            tree.removeTree();
            cout << "Drzewo zostalo usuniete\n";
            break;

        case 4:
            tree.displayTree();
            break;

        case 5:
            cout << "1-Inorder, 2-Preorder, 3-Postorder: ";
            cin >> orderType;
            if (orderType == 1)
                tree.showInorder();
            else if (orderType == 2)
                tree.showPreorder();
            else if (orderType == 3)
                tree.showPostorder();
            else
                cout << "Nieprawidlowy wybor\n";
            break;

        case 6:
            cout << "Podaj nazwe pliku: ";
            cin >> filename;
            cout << "1-Inorder, 2-Preorder, 3-Postorder: ";
            cin >> orderType;
            tree.saveToFile(filename, orderType);
            break;

        case 7:
            cout << "Koniec programu\n";
            return 0;

        default:
            cout << "Nieprawidlowy wybor\n";
            break;
        }
    }
}
