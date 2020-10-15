#ifndef __TreeNode_H__
#define __TreeNode_H__

#include <iostream>

class TreeNode
{
public:
    int datum;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int);

};

/**
 * @brief Construct a new node with a parameter
 *
 * @param datum Data that will go into tree
 */
TreeNode::TreeNode(int datum)
{
    this->datum = datum;
    this->right = this->left = nullptr;
}



#endif // __TreeNode_H__