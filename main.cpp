// Este trabajo fue elaborado por el grandioso equipo de Esteban de la Maza, Ricardo Jasso, y Raul Jerlach

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
    
    // Print Preorder
    myTree.visit(1);
    // print inorder
    myTree.visit(2);
    // print postorder
    myTree.visit(3);
    // print level by level
    myTree.visit(4);

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
