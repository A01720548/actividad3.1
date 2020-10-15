#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include "TreeNode.h"
#include <iostream>
class BinarySearchTree
{
private:
    TreeNode* root;
    int size;
    int count;
    int pos;
    void printPreOrderRecursive(TreeNode* which);
    TreeNode* RecursiveInsert(TreeNode* where, int datum);
    int RecursiveTreeHeight(TreeNode* which);
    int RecursiveWhatLevelAmI(TreeNode* which, int datum, int);


public:
    BinarySearchTree(/* args */);
    ~BinarySearchTree();
    void insert(int datum);
    void Inorder(TreeNode* root);
    int getSize();
    void printPreOrder();
    int height();
    int whatLevelAmI(int);
};

BinarySearchTree::BinarySearchTree(/* args */)
{
    this->root = nullptr;
    this->size = 0;
    this->count = 0;
    this->pos = 0;
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::insert(int datum)
{
    this->root = RecursiveInsert(root, datum);
}

int BinarySearchTree::getSize()
{
    return size;
}


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
        std::cout << "Element already exists";
    }
    return root;
}

void BinarySearchTree::printPreOrder()
{
    printPreOrderRecursive(this->root);
}

int BinarySearchTree::height()
{
    return RecursiveTreeHeight(root);

}

int BinarySearchTree::whatLevelAmI(int datum)
{
    return RecursiveWhatLevelAmI(root, datum, count);
}

int BinarySearchTree::RecursiveTreeHeight(TreeNode* which)
{
    if (!which) {
        return 0;
    }
    else {
        /* compute the depth of each subtree */
        int leftHeight = RecursiveTreeHeight(which->left);
        int rightHeight = RecursiveTreeHeight(which->right);

        /* use the larger one */
        if (leftHeight > rightHeight)
            return(leftHeight + 1);
        else return(rightHeight + 1);
    }

}

int BinarySearchTree::RecursiveWhatLevelAmI(TreeNode* which, int datum, int count)
{
    if (!root) {
        return -1;
    }
    if (root->datum == datum) {
        return count;
    }

    int pos = RecursiveWhatLevelAmI(root->left, datum, count + 1);

    if (pos != -1) {
        return pos;
    }

    pos = RecursiveWhatLevelAmI(root->right, datum, count + 1);


    return pos;
}

void BinarySearchTree::printPreOrderRecursive(TreeNode* which) {
    if (which != nullptr) {
        std::cout << '[' << which->datum << ' ';
        printPreOrderRecursive(which->left);
        printPreOrderRecursive(which->right);
        std::cout << ']';

    }
    else
    {
        std::cout << "[]";
    }

}

#endif // __BINARYSEARCHTREE_H__