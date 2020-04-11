
/*
578. Lowest Common Ancestor III
中文English
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
Return null if LCA does not exist.

Example
Example1

Input: 
{4, 3, 7, #, #, 5, 6}
3 5
5 6
6 7 
5 8
Output: 
4
7
7
null
Explanation:
  4
 / \
3   7
   / \
  5   6

LCA(3, 5) = 4
LCA(5, 6) = 7
LCA(6, 7) = 7
LCA(5, 8) = null

Example2

Input:
{1}
1 1
Output: 
1
Explanation:
The tree is just a node, whose value is 1.
Notice
node A or node B may not exist in tree.
Each node has a different value
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
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* A, TreeNode* B) {
        // write your code here
        if(root == NULL) {
            return NULL;
        }
        TreeNode* ancesterNodeA {NULL};
        TreeNode* ancesterNodeB {NULL};
        int idxA = 0, idxB = 0; 
        // search for the ancester of node A
        if(A->val == root->val) 
            ancesterNodeA = root; 
        else
            ancesterNodeA = searchAncesterNode(root, A->val, idxA); 
        // search for the ancester of node B
        if(B->val == root->val)
            ancesterNodeB = root;
        else
            ancesterNodeB = searchAncesterNode(root, B->val, idxB); 
        // if both A and B have ancester
        if(ancesterNodeA == NULL || ancesterNodeB == NULL)
            return NULL;
        // compare the depth of each node
        if(idxA < idxB)
            return ancesterNodeA;
        else
            return ancesterNodeB; 
    }
    
private: 
    TreeNode* searchAncesterNode(TreeNode* currentNode, int val, int& idx) {
        if(currentNode->left == NULL && currentNode->right == NULL) {
            return NULL; 
        }
        TreeNode* nextNode; 
        if(currentNode->left != NULL) {
            if(currentNode->left->val == val)
                return currentNode;
            else {
                idx++;
                nextNode = searchAncesterNode(currentNode->left, val, idx);
            }
        }
        if(currentNode->right != NULL) {
            if(currentNode->right->val == val) 
                return currentNode;
            else {
                idx++; 
                nextNode = searchAncesterNode(currentNode->right, val, idx);
            }
                
        }
        return nextNode; 
    }
    
    
};