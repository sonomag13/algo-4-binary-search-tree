//
// Created by strobe on 4/9/20.
//

#pragma once

#include "DataStruct.h"

class CommonAncestor {

public:
    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* A, TreeNode* B) {
        // write your code here
        TreeNode* ancesterNodeA{NULL};
        TreeNode* ancesterNodeB{NULL};
        int idxA = 0, idxB = 0;
        // search for the ancester of node A
        if (A->val == root->val)
            ancesterNodeA = root;
        else
            ancesterNodeA = searchAncestorNode(root, A->val, idxA);
        // search for the ancester of node B
        if (B->val == root->val)
            ancesterNodeB = root;
        else
            ancesterNodeB = searchAncestorNode(root, B->val, idxB);
        // if both A and B have ancester
        if (ancesterNodeA == NULL || ancesterNodeB == NULL)
            return NULL;
        // compare the depth of each node
        if (idxA < idxB)
            return ancesterNodeA;
        else
            return ancesterNodeB;
    }

private:
    static TreeNode* searchAncestorNode(TreeNode* currentNode, int val, int& idx) {
        if (currentNode->left == NULL && currentNode->right == NULL) {
            return NULL;
        }
        if (currentNode->val > val) {
            if (currentNode->left == NULL) {
                return NULL;
            }
            if (currentNode->left->val == val) {
                return currentNode;
            } else {
                idx++;
                TreeNode* ancesterNode = searchAncestorNode(currentNode->left, val, idx);
            }
        } else {
            if (currentNode->right == NULL) {
                return NULL;
            }
            if (currentNode->right->val == val) {
                return currentNode;
            } else {
                idx++;
                TreeNode* ancesterNode = searchAncestorNode(currentNode->right, val, idx);
            }
        }
    }

};
