/*
LintCode 900. Closest Binary Search Tree Value
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Example
Example1

Input: root = {5,4,9,2,#,8,10} and target = 6.124780
Output: 5
Explanation：
Binary tree {5,4,9,2,#,8,10},  denote the following structure:
        5
       / \
     4    9
    /    / \
   2    8  10
Example2

Input: root = {3,2,4,1} and target = 4.142857
Output: 4
Explanation：
Binary tree {3,2,4,1},  denote the following structure:
     3
    / \
  2    4
 /
1
Notice
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
*/

#include <iostream>

// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        // write your code here
        double minDelta, currentDelta, currentVal;
        int cloesetVal; 
        minDelta = abs(root->val - target); 
        while (root != NULL) {
            currentVal = root->val; 
            currentDelta = abs(currentVal - target); 
            if(currentDelta <= minDelta) {
                minDelta = currentDelta; 
                cloesetVal = currentVal; 
            }
            (target < currentVal) ? (root = root->left) : (root = root->right); 
        }
        return cloesetVal; 
    }
};


class Solution2 {
public:
    int closestValue(TreeNode* root, double target) {
        
        // target = target; 
        
        dfs(root, target);
        
        return result; 
    }
    
private:
    int result; 
    double minDelta{INT_MAX};
    // double target; 
    
    void dfs(TreeNode* root, const double target) {        
        if (!root) {
            // base case
            return; 
        }
        
        double delta = abs(root->val - target);
        
        if (delta < minDelta) {
            result = root->val;
            minDelta = delta; 
        }
                
        if (target > root->val) {
            dfs(root->right, target);   
        }
        else {
            dfs(root->left, target);
        }
        
    }
};