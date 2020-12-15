#include <iostream>
#include <vector>

#include "Solution.h"

using namespace std;

int main() {

    vector<int> nums{5, 4, 6, 3, 7};

    BinarySearchTree binarySearchTree;

    for (auto& val : nums) {
        binarySearchTree.insertNode(val);
    }

    TreeNode* rootNode{rootNode = binarySearchTree.getRootNode()};

    // Solution::flatten(rootNode);
    Solution::recursiveFlatten(rootNode);

    return EXIT_SUCCESS;
}