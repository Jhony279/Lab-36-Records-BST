#include <iostream>
#include "IntBinaryTree.h"
#include <string>
using namespace std;

int main() {
    IntBinaryTree tree;
    tree.insertNode("D");
    tree.insertNode("B");

    tree.displayInOrder();
    tree.displayPreOrder();
    tree.displayPostOrder();

    return 0;
}