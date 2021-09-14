// LeetCode 99. Recover Binary Search Tree
// Medium

#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

void recoverTree(TreeNode* root) {
    inorder(root);
    swap(first->val, second->val); 
}
    
private:
TreeNode* first = nullptr;
TreeNode* second = nullptr;     
TreeNode* pre = nullptr; 
    
void inorder(TreeNode* root) {    
    // inorder traverse
    
    if (!root) {
        return; 
    }
        
    inorder(root->left);
        
    if (pre && root->val < pre->val) {            
        if (!first) {                
            // get the first abnormal node
            first = pre;
        }
        // if two neighboring nodes are swapped, the second will
        // only be updated once; otherwise, twice: one at the first
        // swapped node and two at the second swapped node
        second = root; 
    }
    
    pre = root;         
    
    inorder(root->right);        
}

};