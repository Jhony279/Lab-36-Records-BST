#include <iostream>
#include "IntBinaryTree.h"
#include <string>
using namespace std;

const int MAX_OPTIONS = 5;

int main_menu();

int main() {
    IntBinaryTree tree;
    bool again = true;
    string code;

    tree.displayInOrder();
    tree.displayPreOrder();
    tree.displayPostOrder();

    while (again) {
        int sel = main_menu();
        switch (sel) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;

            case 4:
                break;

            default:
                cout << "\nInvalid selection.\n";
                break;
        }
    }

    return 0;
}

int main_menu() {
    cout << "\n*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add Node\n";
    cout << "[2] Delete Node\n";
    cout << "[2] Search Node\n";
    cout << "[4] Modify Node\n";
    cout << "[5] Quit\n";
    cout << "Choice --> ";

    int choice;
    cin >> choice;
    while (choice < 1 || choice > MAX_OPTIONS) {
        cout << "Invalid, again --> ";
        cin >> choice;
    }
    return choice;
}