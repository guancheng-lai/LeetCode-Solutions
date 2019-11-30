//
//  main.cpp
//  226. Invert Binary Tree
//
//  Created by Guancheng Lai on 8/19/18.
//  Copyright © 2018 Guancheng Lai. All rights reserved.
//

#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return nullptr;
    }
    else
    {
        
    }
    
    return nullptr;
}

int main(int argc, const char * argv[])
{
    
}
