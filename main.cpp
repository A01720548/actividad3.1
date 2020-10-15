#include <iostream>
#include "BinarySearchTree.h"


using namespace std;

int main() {
    BinarySearchTree myTree = BinarySearchTree();;
    myTree.insert(50);
    myTree.insert(20);
    myTree.insert(65);
    myTree.insert(10);
    myTree.insert(60);
    myTree.insert(70);
    myTree.insert(5);

    //cout << endl << myTree.getSize();
    myTree.printPreOrder();

    int height = myTree.height();

    cout << "Height: " << height << endl;

    int level = myTree.whatLevelAmI(5);

    cout << "Level: " << level << endl;
    myTree.ancestors(5);


    return 0;
}