// LeetCode 285. Inorder Successor in BST

#include <vector>

using namespace std; 

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        inorder(root);
        
        int k = 0; 
        while (p != vecNode[k]) {            
            // find the node in the stack
            k++;
        }
        
        if (k == vecNode.size() - 1) {
            return nullptr;
        }
        else {
            return vecNode[k + 1];   
        }
        
    }
    
private:    
    vector<TreeNode *> vecNode; 
    
    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }        
        inorder(root->left);
        vecNode.push_back(root);
        inorder(root->right);        
    }
    
};