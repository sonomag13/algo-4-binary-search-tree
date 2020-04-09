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
        - append the current value to the path string
        - pass the path string to the next iteration of DFS
    Notice that, the string path is passed by variable, NOT by reference. That sadi, for every layer of 
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
        vector<string> pathVector; 
        string pathString; 
        pathString = ""; 
        dfsPath(root, pathString, pathVector); 
        return pathVector; 
    }

private:
    void dfsPath(TreeNode* currentNode, string pathString, vector<string>& pathVector) {
        if(currentNode != NULL) {
            pathString += to_string(currentNode->val); 
            if(currentNode->left == NULL && currentNode->right == NULL) {
                cout << pathString << endl; 
                pathVector.push_back(pathString);
            }
            pathString += "->"; 
            dfsPath(currentNode->left, pathString, pathVector);
            dfsPath(currentNode->right, pathString, pathVector);
        }
    } 
};