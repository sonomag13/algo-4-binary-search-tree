//
// Created by strobe on 4/9/20.
//

#include "DataStruct.h"

#include <iostream>

class BST {

public:
    BST() {
        _root = NULL;
    };
    ~BST() = default;
    void insertNode(int val) {
        _root = _insertNode(_root, val);
    }
    TreeNode* getRoot() {
        return _root;
    }

private:
    int _numNode = 0;
    TreeNode* _root;
    TreeNode* _insertNode(TreeNode* currentRoot, int val) {
        if (currentRoot == NULL) {
            _numNode++;
            return new TreeNode(val);
        }
        if (val < currentRoot->val)
            currentRoot->left = _insertNode(currentRoot->left, val);
        else
            currentRoot->right = _insertNode(currentRoot->right, val);
        return currentRoot;
    }
};