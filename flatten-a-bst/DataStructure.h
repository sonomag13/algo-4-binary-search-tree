#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};
    explicit TreeNode(int val): val(val), left(nullptr), right(nullptr) {

    }
};

class BinarySearchTree {

public:

    BinarySearchTree() = default;
    ~BinarySearchTree() = default;

    void insertNode(int val) {
        _root = _insertNode(_root, val);
    }

    TreeNode* getRootNode() {
        return _root;
    }

private:
    TreeNode* _root{nullptr};

    TreeNode* _insertNode(TreeNode* currentNode, int val) {
        if (!currentNode) {
            return new TreeNode(val);;
        }
        if (val > currentNode->val) {
            currentNode->right = _insertNode(currentNode->right, val);
        }
        else {
            currentNode->left = _insertNode(currentNode->left, val);
        }
        return currentNode;
    }

};
