/*
Description
Given a binary tree, return all root-to-leaf paths.

Have you met this question in a real interview?  
Example
Example 1:

Input：{1,2,3,#,5}
Output：["1->2->5","1->3"]
Explanation：
   1
 /   \
2     3
 \
  5
Example 2:

Input：{1,2}
Output：["1->2"]
Explanation：
   1
 /   
2         
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
    Summary of the solution
    - DFS is used, where a node in the tree, the string of a certain path across the node, and vector 
      of strings are passed in the search
    - Base case: 
        - the node is a leaf
        - push the path string into the vector
    - Non-base case:
        - append the currentPath value to the path string
        - pass the path string to the next iteration of DFS
    Notice that, the string path is passed by variable, NOT by reference. That said, for every layer of 
    the recursion, there is a new copy of string path, and each copy is eventually collected at the
    bottome case
*/

class Solution {
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        // write your code here
        vector<vector<int>> vecResult; 
        vector<int> currentPath;         
        dfs(root, currentPath, vecResult);         
        return convertVec2Str(vecResult); 
    }
        
private:
    void dfs(TreeNode* currentRoot, vector<int> currentPath, vector<vector<int>>& vecResult) {        
        if (currentRoot != NULL) {
            currentPath.push_back(currentRoot->val); 
            if (!currentRoot->left && !currentRoot->right) {
                vecResult.push_back(currentPath); 
                return; 
            }
            dfs(currentRoot->left, currentPath, vecResult); 
            dfs(currentRoot->right, currentPath, vecResult);
        }
    }
    
    vector<string> convertVec2Str(vector<vector<int>> vecResult) {
        vector<string> result;
        for (auto ele : vecResult) {
            string currentPath; 
            int n = ele.size(); 
            for (int i = 0; i < n - 1; ++i) {
                currentPath += to_string(ele[i]);
                currentPath += "->";
            }
            currentPath += to_string(ele[n - 1]);
            result.push_back(currentPath);
        }
        return result; 
    }
};