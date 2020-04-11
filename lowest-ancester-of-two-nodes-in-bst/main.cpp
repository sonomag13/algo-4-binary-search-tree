#include "BST.h"
#include "CommonAncestor.h"
#include <iostream>

using namespace std;

int main() {

    int arr[] = {4, 3, 7, 5, 6};
    BST BST0;
    for (auto i : arr) {
        BST0.insertNode(i);
    }

    TreeNode nodeA(5);
    TreeNode nodeB(6);
    TreeNode* rootBST0 = BST0.getRoot();
    TreeNode* lowestCommonAncestor = CommonAncestor::lowestCommonAncestor(rootBST0, &nodeA, &nodeB);

    cout << "val of the common ancester is " << lowestCommonAncestor->val << endl;

    return 0;
}
