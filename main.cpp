#include <iostream>
#include "BinarySearchTree.h"


using namespace std;

int main() {
    BinarySearchTree myTree = BinarySearchTree();;
    myTree.insert(50);
    myTree.insert(20);
    myTree.insert(30);

    cout << endl << myTree.getSize();
    myTree.printPreOrder();

    return 0;
}