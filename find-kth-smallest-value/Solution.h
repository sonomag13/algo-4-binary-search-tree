/*
902. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Example
Example 1:

Input：{1,#,2},2
Output：2
Explanation：
    1
     \
      2
The second smallest element is 2.
Example 2:

Input：{2,1,3},1
Output：1
Explanation：
  2
 / \
1   3
The first smallest element is 1.
Challenge
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Notice
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
    
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
    - use in-order search of the BST and push the values in ascendent order in a vector
    - return whe there are k elements 
    - the last element, or k-1 the element in the vector is the kth smallest element
*/


class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        // write your code here
        vector<int> valVector; 
        searchKthSmallestValue(root, k, valVector); 
        return valVector[k-1]; 
    }
    
private:
    void searchKthSmallestValue(TreeNode* currentNode, int k, vector<int>& valVector) {
        if(currentNode == NULL || k == 0) {
            return;
        }
        else {
            searchKthSmallestValue(currentNode->left, k, valVector);
            valVector.push_back(currentNode->val);
            k--; 
            searchKthSmallestValue(currentNode->right, k, valVector); 
        }
    }
};

// this solution does not record the numbers, save some space

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        // write your code here
        this->k = k; 
        // vector<int> result; 
        inOrder(root); 
        return result; 
    }
    
private: 
    
    int k; 
    int result; 
    void inOrder(TreeNode* currentNode) {
        if (currentNode == NULL) {
            return; 
        }
        
        inOrder(currentNode->left); 
        if (k == 1) {
            result = currentNode->val; 
        }
        k--; 
        inOrder(currentNode->right);
    }
    
};