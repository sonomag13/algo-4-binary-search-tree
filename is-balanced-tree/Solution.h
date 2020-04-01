
/*
LintCode 93. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example
Example  1:
    Input: tree = {1,2,3}
    Output: true
    
    Explanation:
    This is a balanced binary tree.
          1  
         / \                
        2  3

    
Example  2:
    Input: tree = {3,9,20,#,#,15,7}
    Output: true
    
    Explanation:
    This is a balanced binary tree.
          3  
         / \                
        9  20                
          /  \                
         15   7 

    
Example  3:
    Input: tree = {1,#,2,3,4}
    Output: false
    
    Explanation:
    This is not a balanced tree. 
    The height of node 1's right sub-tree is 2 but left sub-tree is 0.
          1  
           \                
           2                
          /  \                
         3   4

*/
/*
    Features of the balanced binary tree:
        - maximum difference of the height of the left subtree and heigh of the right subtree is 1
        - every subtree is a balanced tree
        - however, it is not required that all the nodes to be fulled filled
    
    That said, to qualify a balanced tree, all the 3 conditions must be satisfied:
        - abs(height(left subtree) - height(right subtree)) <= 1
        - left subtree is balanced
        - right subtree is balanced
*/

/* 
    the complexity of this solution is nlog(n). 
    The reason is that the comparison occurs at the root level. 
    we calculate the height, isBalanced for right and isBalanced for left for every single node
*/
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        if(root == NULL) {
            return 1; 
        }
        int left_height = height(root->left);
        int right_height = height(root->right);
        return (abs(left_height - right_height)<=1 && isBalanced(root->left) && isBalanced(root->right)); 
    }
    
private:
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }        
        return max(height(root->left), height(root->right)) + 1; 
    }
    
};


/*
    the time complexity of this solution is log(n) since it does not repeatdly calcualte left heigh and right heigh
    if there is any sub tree that is not balanced, the code will return
    Notice that the key difference is that bool flagBalanced is passed to each layer of the recursion
*/
class Solution {
    
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        if(root == NULL) {
            return 1; 
        }
        bool flagBalance = true; 
        height(root, &flagBalance);
        return flagBalance; 
    }
    
private:
    int height(TreeNode* root, bool* ptrFlagBalance) {
        if(root == NULL) {
            return 0; 
        }
        int left_height = height(root->left, ptrFlagBalance);
        int right_height = height(root->right, ptrFlagBalance); 
        if(abs(left_height - right_height) > 1) {
            *ptrFlagBalance = false;
            return -1; 
        }
        return max(left_height, right_height) + 1; 
    }
    
};