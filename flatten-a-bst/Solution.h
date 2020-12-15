/*
453. Flatten Binary Tree to Linked List
中文English
Flatten a binary tree to a fake "linked list" in pre-order traversal.

Here we use the right pointer in TreeNode as the next pointer in ListNode.

Example
Example 1:

Input:{1,2,5,3,4,#,6}
Output：{1,#,2,#,3,#,4,#,5,#,6}
Explanation：
     1
    / \
   2   5
  / \   \
 3   4   6

1
\
 2
  \
   3
    \
     4
      \
       5
        \
         6
Example 2:

Input:{1}
Output:{1}
Explanation：
         1
         1
Challenge
Do it in-place without any extra memory.

Notice
Don't forget to mark the left child of each node to null. Or you will get Time Limit Exceeded or Memory Limit Exceeded.
*/

#include "DataStructure.h"

class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    static void flatten(TreeNode * root) {
        TreeNode* currentNode{root};
        while (currentNode) {
            if (currentNode->left) {
                TreeNode* searchNode = currentNode->left; 
                while (searchNode->right) {
                    searchNode = searchNode->right;
                }
                /**
                 * The search node end up at the right bottom corner of the left
                 * subtree of the current node; 
                 * Then move right subtree of the current node to the right 
                 * pointer of the search node. 
                 */ 
                searchNode->right = currentNode->right;
                /**
                 * disconnect the right subtree from the current node
                 * the right child is replaced by the left subtree
                 */ 
                currentNode->right = currentNode->left;
                // nullify the left child of the current node
                currentNode->left = nullptr;
            }
            currentNode = currentNode->right; 
        }
    }

    static void recursiveFlatten(TreeNode * root) {
        // write your code here
        _recursive_flatten_binary_tree(root);
    }

private:

    static void _recursive_flatten_binary_tree(TreeNode* root) {
        // base case
        if (!root->left && !root->right) {
            return;
        }
        // if the root has left child
        if (root->left) {
            // traverse to the right most child on the left branch of the root
            TreeNode * currentNode{root->left};
            while (currentNode->right) {
                currentNode = currentNode->right;
            }
            currentNode->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        _recursive_flatten_binary_tree(root->right);
    }

};