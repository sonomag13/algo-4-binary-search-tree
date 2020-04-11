//
// Created by strobe on 4/9/20.
//

#pragma once

#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
