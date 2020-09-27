//
// Created by luther on 9/27/20.
//

#pragma once

#include <vector>
#include "DataStructure.h"

using namespace std;

class Solution {
public:
    /**
     * @param numbers: the given list
     * @param node1: the given node1
     * @param node2: the given node2
     * @return: the distance between two nodes
     */
    int bstDistance(vector<int> &numbers, int node1, int node2) {

        if (numbers.size() < 2) {
            return -1;
        }

        // first convert the vector into binary search tree
        for (auto val : numbers) {
            this->root = insertNode(this->root, val);
        }

        // check if node1 and node2 exist in the tree
        bool flag1 = searchNode(node1);
        bool flag2 = searchNode(node2);
        if (!flag1 || !flag2) {
            return -1;
        }

        /**
         * calculate the distance
         * - first find the bifurcation node, i.e. node1 and node2 are on the two sides of bifurcation point
         * - second, find the distance of node1 and node 2 to the bifurcation point
         */
        TreeNode* currentNode = root;
        while (true) {
            bool cond1 = (node1 > currentNode->val) && (node2 > currentNode->val);
            bool cond2 = (node1 < currentNode->val) && (node2 < currentNode->val);
            if (!cond1 && !cond2) {
                // the current node is the common ancestor of both nodes
                break;
            }
            if (cond1) {
                // both nodes are on the right side of the current node
                currentNode = currentNode->right;
            }
            if (cond2) {
                // both nodes are on the left side of the current node
                currentNode = currentNode->left;
            }
        }
        return getDist(currentNode, node1) + getDist(currentNode, node2);
    }

    TreeNode* getRoot() {
        return this->root;
    }

private:
    TreeNode* root{nullptr};

    TreeNode* insertNode(TreeNode* currentNode, int val) {
        // the BST is empty
        if (currentNode == nullptr) {
            return new TreeNode(val);
        }

        if (val > currentNode->val) {
            // go right if the val is greater than the value of the currentNode
            currentNode->right = insertNode(currentNode->right, val);
        }
        else {
            // go left if the val is less than the value of the currentNode
            currentNode->left = insertNode(currentNode->left, val);
        }
        return currentNode;
    }

    bool searchNode(int val) {
        bool flag = false;
        TreeNode* currentNode = this->root;
        while (currentNode) {
            if (currentNode->val == val) {
                flag = true;
                break;
            }
            if (val > currentNode->val) {
                currentNode = currentNode->right;
            }
            else {
                currentNode = currentNode->left;
            }
        }
        return flag;
    }

    static int getDist(TreeNode* currentNode, int nodeVal) {
        int dist = 0;

        while(currentNode) {
            if (currentNode->val == nodeVal) {
                break;
            }
            dist++;
            if (nodeVal > currentNode->val) {
                currentNode = currentNode->right;
            }
            else {
                currentNode = currentNode->left;
            }
        }
        return dist;
    }

};