// LeetCode 230. Kth Smallest Element in a BST

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
    int kthSmallest(TreeNode* root, int k) {
        
        int result; 
        bool hasFound{false};
        
        inorder(root, hasFound, result, k); 
        
        return result;
        
    }
    
    void inorder(TreeNode* root, bool& hasFound, int& result, int& k) {
        
        if (!root || hasFound) {            
            return;            
        }
        
        inorder(root->left, hasFound, result, k);
        
        k--; 
        if (k == 0) {
            hasFound = true;
            result = root->val;             
            return;
        }
        
        inorder(root->right, hasFound, result, k);        
        
    }
};