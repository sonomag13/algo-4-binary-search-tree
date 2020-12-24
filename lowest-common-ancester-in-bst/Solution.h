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


// Definition of TreeNode:
class TreeNode {
    public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
        }
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* currentNode{root}; 
        
        while (currentNode) {            
            /*
             * three cases: 
             * - p and q are on the right side of the root
             * - p and q are on the left side of the root
             * - otherwise, the common ancester if found
             */             
            bool case1 = currentNode->val < p->val && currentNode->val < q->val;
            bool case2 = currentNode->val > p->val && currentNode->val > q->val;
            
            if (case1) {
                currentNode = currentNode->right; 
            }
            else if (case2) {
                currentNode = currentNode->left; 
            }
            else {
                return currentNode; 
            }            
        }                        
                        
        return nullptr; 
        
    }
};