#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include "TreeNode.h"
#include <iostream>
using namespace std;

class BinarySearchTree
{
private:
    TreeNode* root;
    int size;
    int count;
    void printPreOrderRecursive(TreeNode* which);
    TreeNode* RecursiveInsert(TreeNode* where, int datum);
    int RecursiveTreeHeight(TreeNode* which);
    int RecursiveWhatLevelAmI(TreeNode* which, int datum, int);
    bool RecursiveAncestors(TreeNode* which, int datum);
    void visitPreorder(TreeNode* which);
    void visitInorder(TreeNode* which);
    void visitPostorder(TreeNode* which);
    void visitLevel(TreeNode* which);


public:
    BinarySearchTree();
    void insert(int datum);
    void Inorder(TreeNode* root);
    int getSize();
    void printPreOrder();
    int height();
    int whatLevelAmI(int);
    void ancestors(int);
    void visit(int counter)
};

BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
    this->size = 0;
    this->count = 0;
}


/**
 * @brief Wrapper function to call recursive insert
 *
 * @param datum Int that will be inserted
 */
void BinarySearchTree::insert(int datum)
{
    this->root = RecursiveInsert(root, datum);
}

/**
 * @brief Get Size returns the size of the BST
 * Complexity: O(1)
 * @return int size
 */
int BinarySearchTree::getSize()
{
    return size;
}

/**
 * @brief Inserts element into BST if it isn't already
 *Complexity: O(n)
 * @param root Current tree, starting from the root
 * @param datum Int that will be added into list
 * @return TreeNode* The tree but with the added node
 */
TreeNode* BinarySearchTree::RecursiveInsert(TreeNode* root, int datum)
{
    if (!root) {
        root = new TreeNode(datum);
        this->size++;

    }
    else if (datum > root->datum) {
        root->right = RecursiveInsert(root->right, datum);
    }
    else if (datum < root->datum) {
        root->left = RecursiveInsert(root->left, datum);
    }
    else
    {
        cout << "Element already exists";
    }
    return root;
}

/**
 * @brief Wrapper function to print PreOrder
 * Complexity: O(1)
 */
void BinarySearchTree::printPreOrder()
{
    printPreOrderRecursive(this->root);
}

/**
 * @brief Wrapper function that calls the tree height function
 * Complexity: O(1)
 * @return int Tree height, starting at 0
 */
int BinarySearchTree::height()
{
    return RecursiveTreeHeight(this->root);

}

/**
 * @brief Wrapper function to call whatlevelamI function
 * Complexity: O(1)
 * @param datum Integer that will be searched
 * @return int Level if found or -1 if not found
 */
int BinarySearchTree::whatLevelAmI(int datum)
{
    return RecursiveWhatLevelAmI(this->root, datum, this->count);
}

/**
 * @brief Recursive function to tell user height of tree starting at 0
 * Complexity: O(n)
 * @param which Tree that will be searched
 * @return int Height of Tree, -1 if it has no nodes
 */
int BinarySearchTree::RecursiveTreeHeight(TreeNode* which)
{
    if (!which) {
        return -1;
    }
    else {

        int leftHeight = RecursiveTreeHeight(which->left);
        int rightHeight = RecursiveTreeHeight(which->right);


        if (leftHeight > rightHeight)
            return(leftHeight + 1);
        else return(rightHeight + 1);
    }

}

/**
 * @brief Recursive function that tells user level
 * Complexity: O(n)
 * @param which Tree being searched
 * @param datum Int that will be searched
 * @param count Int that will be added everytime we go down a level
 * @return int Level of node or -1 if not found
 */
int BinarySearchTree::RecursiveWhatLevelAmI(TreeNode* which, int datum, int count)
{
    if (!which) {
        return -1;
    }
    if (which->datum == datum) {
        return count;
    }

    int pos = RecursiveWhatLevelAmI(which->left, datum, count + 1);

    if (pos != -1) {
        return pos;
    }

    pos = RecursiveWhatLevelAmI(which->right, datum, count + 1);

    return pos;
}

/**
 * @brief Recursive function that prints tree in order
 * Complexity: O(n)
 * @param which Tree being printed
 */
void BinarySearchTree::printPreOrderRecursive(TreeNode* which) {
    if (which != nullptr) {
        cout << '[' << which->datum << ' ';
        printPreOrderRecursive(which->left);
        printPreOrderRecursive(which->right);
        cout << ']';

    }
    else
    {
        cout << "[]";
    }

}

/**
 * @brief Wrapper function to call ancestors function
 * Complexity: O(1)
 * @param datum int that will be used to find ancestors
 */
void BinarySearchTree::ancestors(int datum)
{
    RecursiveAncestors(this->root, datum);
}

/**
 * @brief Recursive function that will print a nodes ancestors
 * Complexity: O(n)
 * @param which Tree being used
 * @param datum Int that will be found and used to print parent nodes
 * @return true If node is equal to current root
 * @return false If node is not equal
 */
bool BinarySearchTree::RecursiveAncestors(TreeNode* which, int datum)
{

    if (!which)
        return false;

    if (which->datum == datum)
        return true;


    if (RecursiveAncestors(which->left, datum) || RecursiveAncestors(which->right, datum))
    {
        cout << which->datum << " ";
        return true;
    }

    return false;
}

/**
 * @brief Preorder printing
 * Complexity: O(n)
 * @param which, a pointer to a TreeNode
 */
void BinarySearchTree::visitPreorder(TreeNode* which) {
    if (!which) 
        return; 
  
    cout << which->datum << " "; 
  
    visitPreorder(which->left);  
  
    visitPreorder(which->right); 
}

/**
 * @brief Level by Level printing
 * Complexity: O(n)
 * @param which, a pointer to a TreeNode
 */
void BinarySearchTree::visitInorder(TreeNode* which) {
    if (!which) 
        return; 
  
    visitInorder(which->left); 
  
    cout << which->datum << " "; 
  
    visitInorder(which->right); 
}

/**
 * @brief Postorder printing
 * Complexity: O(n)
 * @param which, a pointer to a TreeNode
 */
void BinarySearchTree::visitPostorder(TreeNode* which) {
    if (!which) 
        return; 
  
    visitPostorder(which->left); 
  
    visitPostorder(which->right); 
  
    cout << which->datum << " "; 
}

/**
 * @brief Level by Level printing
 * Complexity: O(n)
 * @param which, a pointer to a TreeNode
 */
void BinarySearchTree::visitLevel(TreeNode* which) {

    if (!which)  
        return; 
  
    queue<TreeNode *> que; 
  
    que.push(which); 
    while (que.empty() == false) 
    { 
        TreeNode *currentNode = que.front(); 
        cout << currentNode->datum << " "; 
        que.pop(); 
  
        if (currentNode->left != NULL) 
            que.push(currentNode->left); 
  
        if (currentNode->right != NULL) 
            que.push(currentNode->right); 
    } 
}

/**
 * @brief recieves a number and chooses appropiate function
 * @param counter, the choosing number
 */
void BinarySearchTree::visit(int counter) {
    if (counter == 1) {
        visitPreorder(this->root);
    } else if (counter == 2) {
        visitInorder(this->root);
    } else if (counter == 3) {
        visitPostorder(this->root);
    } else {
        visitLevel(this->root);
    }
    
}


#endif // __BINARYSEARCHTREE_H__
