//
//  main.cpp
//  Merge two binary trees
//
//  Created by Guancheng Lai on 7/31/18.
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

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
    if (t1 == nullptr)
    {
        return t2;
    }
    else if (t2 == nullptr)
    {
        return t1;
    }
    
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    
    return t1;
}

int main(int argc, const char * argv[])
{
    TreeNode t1(3);
    TreeNode t2(5);
    TreeNode t3(4);
    t1.left = &t2;
    t1.right = &t3;
    
    TreeNode t12(3);
    TreeNode t22(5);
    TreeNode t32(4);
    t21.left = &t22;
    t21.right = &t23;
    
    mergeTrees(t1, t21);
    
}
