#include <iostream>
#include "IntBinaryTree.h"
#include <string>
#include <fstream>
using namespace std;

const int MAX_OPTIONS = 5;

int main_menu();

int main() {
    IntBinaryTree tree; // Create a IntBinaryTree  instance.
    bool again = true;  // Variable to control the main menu loop.
    string code;

    // Load codes from codes.txt file
    ifstream inFile("codes.txt");
    if (inFile.is_open()) {
        cout << "Loading codes from file...\n";
        while (getline(inFile, code)) {
            if (!code.empty()) {  // Skip empty lines
                tree.insertNode(code);
            }
        }
        inFile.close();
        cout << "File loaded successfully.\n\n";
    } else {
        cout << "Could not open codes.txt file.\n";
    }

    // Main menu loop
    while (again) {
        int sel = main_menu();
        switch (sel) {
            case 1:
                cout << "Enter code to add --> ";
                cin >> code;
                tree.insertNode(code);
                break;

            case 2:
                cout << "Enter code to delete --> ";
                cin >> code;
                tree.remove(code);
                break;

            case 3:
                cout << "Enter code to search --> ";
                cin >> code;
                if (tree.searchNode(code))
                    cout << "Found " << code << " in the tree.\n";
                else
                    cout << code << " is not in the tree.\n";
                break;

            case 4:
                cout << "Enter code to modify --> ";
                cin >> code;
                if (tree.searchNode(code)) {
                    cout << "Found " << code << " in the tree.\n";
                    cout << "Enter new code --> ";
                    string new_code;
                    cin >> new_code;
                    tree.remove(code);
                    tree.insertNode(new_code);
                } else
                    cout << code << " is not in the tree.\n";
                break;

            case 5:
                again = false;
            break;

            default:
                cout << "\nInvalid selection.\n";
                break;
        }
    }
    return 0;
}

int main_menu() {
    cout << "\n*** Main Menu ***\n";
    cout << "[1] Add Node\n";
    cout << "[2] Delete Node\n";
    cout << "[3] Search Node\n";
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