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
        cout << "1. Add element\n";
        cout << "2. Delete element\n";
        cout << "3. Delete BST Tree\n";
        cout << "4. Show BST Tree\n";
        cout << "5. Show Inorder, Preorder, Postorder\n";
        cout << "6. Save to file\n";
        cout << "7. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to be added : ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "Enter value to be deleted: ";
            cin >> value;
            tree.remove(value);
            break;

        case 3:
            tree.removeTree();
            cout << "BST Tree has been removed \n";
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
                cout << "Incorrect choice!\n";
            break;

        case 6:
            cout << "Enter file name: ";
            cin >> filename;
            cout << "1-Inorder, 2-Preorder, 3-Postorder: ";
            cin >> orderType;
            tree.saveToFile(filename, orderType);
            break;

        case 7:
            cout << "The end\n";
            return 0;

        default:
            cout << "Incorrect choice!\n";
            break;
        }
    }
}
