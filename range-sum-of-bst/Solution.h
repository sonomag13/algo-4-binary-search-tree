// LeetCode 938. Range Sum of BST

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        return dfs(root, low, high);
        
    }
    
private:
    
    int dfs(TreeNode* root, int low, int high) {
        
        if (!root) {
            // base case
            return 0; 
        }
        
        // if the root is less than high, no need to check the left side 
        // since all the nodes in the left side is less than the node
        int leftSum{0};        
        if (root->val > low) {
            leftSum = dfs(root->left, low, high);
        }
        
        // if the root is greater than high, no need to check the right side
        // since all the nodes in the right side is greater than the node
        int rightSum{0};         
        if (root->val < high) {
            rightSum = dfs(root->right, low, high);
        }
        
        // it is possible that the root itself is out of [low, high], but
        // its children is inside [low high]
        if (root->val <= high && root->val >= low) {
            return root->val + rightSum + leftSum; 
        }
        else {
            return rightSum + leftSum; 
        }
        
    }
    
};