//
//  main.cpp
//  104. Maximum Depth of Binary Tree
//
//  Created by Guancheng Lai on 8/8/18.
//  Copyright © 2018 Guancheng Lai. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

struct TreeNode
{
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int visit(TreeNode* treeNode)
{
    int leftDepth = 1;
    int rightDepth = 1;
    
    if (treeNode->left != nullptr)
    {
        leftDepth += visit(treeNode->left);
    }
    
    if (treeNode->right != nullptr)
    {
        rightDepth += visit(treeNode->right);
    }
    
    return leftDepth >= rightDepth ? leftDepth : rightDepth;
}

int maxDepth(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    
    int depth = visit(root);
    return depth;
}

int main(int argc, const char * argv[])
{
    TreeNode* root = new TreeNode(0);
    
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(2);
    
    int depth = maxDepth(root);
    cout << depth << endl;
}
