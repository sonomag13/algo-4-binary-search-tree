/*
    1311. Lowest Common Ancestor of a Binary Search Tree    
    Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

    Given binary search tree: root = {6,2,8,0,4,7,9,#,#,3,5}

    Example
    Example 1:

    Input: 
    {6,2,8,0,4,7,9,#,#,3,5}
    2
    8
    Output: 6
    Explanation: The LCA of nodes 2 and 8 is 6.
    Example 2:

    Input: 
    {6,2,8,0,4,7,9,#,#,3,5}
    2
    4
    Output: 2
    Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
    Notice
    All of the nodes' values will be unique.
    p and q are different and both values will exist in the BST.
 */


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: root of the tree
     * @param p: the node p
     * @param q: the node q
     * @return: find the LCA of p and q
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q) {
        // write your code here
        int val1 = p->val; 
        int val2 = q->val; 
        
        TreeNode* currentNode = root; 
        
        while(true) {
            
            bool cond1 = (val1 > currentNode->val) && (val2 > currentNode->val);
            bool cond2 = (val1 < currentNode->val) && (val2 < currentNode->val);
            
            if (cond1) {
                // both p and q are on the right side
                currentNode = currentNode->right; 
            }
            else if (cond2) {
                // both p and q are on the left side
                currentNode = currentNode->left; 
            }
            else {
                // p and q are on two sides of the current node
                break; 
            }
            
        }
        return currentNode; 
    }
};