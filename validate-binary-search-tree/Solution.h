/*
95. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
A single node tree is a BST
Example
Example 1:

Input:  {-1}
Output：true
Explanation：
For the following binary tree（only one node）:
          -1
This is a binary search tree.
Example 2:

Input:  {2,1,4,#,#,3,5}
Output: true
For the following binary tree:
      2
     / \
    1   4
       / \
      3   5
This is a binary search tree.
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
    summary:
    At each node, we create the interval for all the points of the left subtree and right subtree
    - The interval of the left subtree is (-inf, currentNode->val)
    - The interval of the right subtree is (currentNode->val, +inf)
    The trick is how to define +/-inf? 
    - Solution1A: if the type of val is int, we can use LONG_MIN and LONG_MAX to represent -inf and +inf, respectively
    - Solution1B: it is possible that the type of val is long long, then we will use nullptr to represent inf
*/

class Solution1A {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        return _isValidBST(root, LONG_MIN, LONG_MAX); 
    }
private: 
    bool _isValidBST(TreeNode* currentNode, long lowerLimit, long upperLimit) {
        if (currentNode == NULL) {
            return true; 
        }
        bool leftTrace = _isValidBST(currentNode->left, lowerLimit, currentNode->val);
        bool rightTrace = _isValidBST(currentNode->right, currentNode->val, upperLimit);
        bool condition1 = currentNode->val > lowerLimit && currentNode->val < upperLimit;
        bool condition2 = leftTrace && rightTrace; 
        return condition1 && condition2; 
    }     
};

class Solution1B {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        return _isValidBST(root, NULL, NULL); 
    }
private: 
    bool _isValidBST(TreeNode* currentNode, int* lowerLimit, int* upperLimit) {
        if (currentNode == NULL) {
            return true; 
        }
        bool leftTrace = _isValidBST(currentNode->left, lowerLimit, &currentNode->val);
        bool rightTrace = _isValidBST(currentNode->right, currentNode->val, &upperLimit);
        /*
            if a limit is not NULL, the limit is set from the parent node. 
            we then compare the current node value with the limit            
        */ 
        bool condition1A = (lowerLimit != NULL && currentNode->val < *lowerLimit);
        bool condition1B = (upperLimit != NULL && currentNode->val > *upperLimit);
        if(condition1A || condition1B) {
            return false; 
        }                
        return leftTrace && rightTrace;  
    }     
};