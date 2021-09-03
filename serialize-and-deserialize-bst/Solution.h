// LeetCode 449. Serialize and Deserialize BST
// Medium

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string result{""};
        preorder(root, result);

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        TreeNode * newRoot = nullptr;

        int i = 0;
        while (i < data.size()) {

            string strVal = "";

            while (data[i] != '#') {
                strVal += data[i];
                i++;
            }
            i++; // move to the next non "#" character

            int val = stoi(strVal);

            newRoot = insert(newRoot, val);
        }

        return newRoot;
    }

private:

    void preorder(TreeNode* root, string& result) {

        if (!root) {
            return;
        }
        result += to_string(root->val) + '#';
        preorder(root->left, result);
        preorder(root->right, result);
    }

    TreeNode* insert(TreeNode* root, int val) {

        if (!root) {
            // base case: create and return a new node
            return new TreeNode(val);
        }

        if (val < root->val) {
            root->left = insert(root->left, val);
        }
        else {
            root->right = insert(root->right, val);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
