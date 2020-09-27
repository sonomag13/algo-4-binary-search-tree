/*
    1561. BST Node Distance
    Given a list of numbers, construct a BST from it(you need to insert nodes one-by-one with the given order to get the BST) and find the distance between two given nodes.

    Example
    Example 1

    Input:
    numbers = {2,1,3}
    node1 = 1
    node2 = 3
    Output:
    2
    Explanation:
    The tree is look like this.
      2
     / \
    1  3
    Example 2

    Input:
    numbers = {2,1}
    node1 = 1
    node2 = 3
    Output: -1
    Notice
    If two nodes do not appear in the BST, return -1
    We guarantee that there are no duplicate nodes in BST
    The node distance means the number of edges between two nodes
 */

#include <ctime>
#include <iostream>
#include <vector>

#include "DataStructure.h"
#include "Solution.h"

using namespace std;

int main() {

    vector<int> numbers{6, 5, 7, 3, 4, 8, 9};

    Solution solution;
    int dist = solution.bstDistance(numbers, 6, 6);

    cout << dist << endl;

    return EXIT_SUCCESS;
}
