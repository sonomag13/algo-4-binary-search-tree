/*
236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {                                
        
        vector<vector<int>> tracks;                 
        
        return _searchTracks(root, p, q); 
        
    }    

private: 
    
    TreeNode* _searchTracks(TreeNode* currentNode, TreeNode* p, TreeNode* q) {
        
        /**
         * base cases
         * - the current node is null
         * - the current node is p or q
         **/ 
        if (currentNode == NULL || currentNode->val == p->val || currentNode->val == q->val) {
            return currentNode; 
        }
        
        TreeNode* leftNode{_searchTracks(currentNode->left, p, q)}; 
        TreeNode* rightNode{_searchTracks(currentNode->right, p, q)}; 
        
        // the lowest common ancester is found
        if (leftNode && rightNode) {
            return currentNode; 
        }
        
        // neither the left search nor the right search can find p or q
        if (!leftNode && !rightNode) {
            return NULL; 
        }
        
        // one of the left and right search is find        
        return leftNode == NULL ? rightNode : leftNode; 
    }
    
};