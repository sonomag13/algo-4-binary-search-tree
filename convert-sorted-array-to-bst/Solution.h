// LeetCode 108. Convert Sorted Array to Binary Search Tree
// Easy

#include <vector>

using namespace std; 

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
                
        return _preorder(nums, 0, nums.size() - 1);
        
    }

private: 
    
    TreeNode * _preorder(const vector<int> & nums, int left, int right) {
        
        if (left > right) {
            // base case
            return nullptr; 
        }
        
        int mid = (left + right) / 2;
        
        auto root = new TreeNode(nums[mid]);
        
        root->left = _preorder(nums, left, mid - 1);
        root->right = _preorder(nums, mid + 1, right);        
        
        return root; 

    }
    
};