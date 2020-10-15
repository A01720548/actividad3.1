#include <iostream>
#include "BinarySearchTree.h"


using namespace std;

int main() {
    BinarySearchTree myTree = BinarySearchTree();;

    //Casos de prueba
    //Insert
    myTree.insert(50);
    myTree.insert(20);
    myTree.insert(65);
    myTree.insert(10);
    myTree.insert(60);
    myTree.insert(70);
    myTree.insert(5);


    //Get Size
    cout << endl << myTree.getSize();

    //Print Tree Preorder
    myTree.printPreOrder();

    //Tree Height
    int height = myTree.height();

    cout << "Height: " << height << endl;
    // What Level Am I
    int level = myTree.whatLevelAmI(5);

    cout << "Level: " << level << endl;

    //Ancestors
    myTree.ancestors(5);


    return 0;
}