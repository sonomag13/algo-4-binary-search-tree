
/*
LintCode 596. Minimum Subtree
Description
English
Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.

LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with minimum sum and the given binary tree is not an empty tree.

Have you met this question in a real interview?  
Example
Example 1:

Input:
{1,-5,2,1,2,-4,-5}
Output:1
Explanation:
The tree is look like this:
     1
   /   \
 -5     2
 / \   /  \
1   2 -4  -5 
The sum of whole tree is minimum, so return the root.
Example 2:

Input:
{1}
Output:1

Explanation:
The tree is look like this:
   1
There is one and only one subtree in the tree. So we return 1.
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

/*
    Summary of the solution:
    - Set the min of the sum a large value, e.g. INT_MAX
    - Use recursion
        - for each node, the left and right is the root of a recursion
        - each recursion returns the sum of root value, sum of the tree where the right is the root and the sum of the tree where the left is the root
*/


class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        calcSubtreeSum(root); 
        return minNode;
    }
    
private: 
    int minSum = INT_MAX; 
    TreeNode* minNode = NULL; 
    int calcSubtreeSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int rightTreeSum = calcSubtreeSum(root->right);
        int leftTreeSum = calcSubtreeSum(root->left); 
        int currentSum = root->val + rightTreeSum + leftTreeSum; 
        if(currentSum < minSum) {
            minSum = currentSum; 
            minNode = root; 
        }
        return currentSum; 
    }
    
};