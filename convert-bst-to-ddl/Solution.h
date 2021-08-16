/*
    426. Convert Binary Search Tree to Sorted Doubly Linked List
    Medium

    Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

    You can think of the left and right pointers as synonymous to the predecessor 
    and successor pointers in a doubly-linked list. For a circular doubly linked list, 
    the predecessor of the first element is the last element, and the successor of the 
    last element is the first element.

    We want to do the transformation in place. After the transformation, the left pointer 
    of the tree node should point to its predecessor, and the right pointer should point 
    to its successor. You should return the pointer to the smallest element of the linked list.

    Example 1:

    Input: root = [4,2,5,1,3]

    Output: [1,2,3,4,5]
 */

#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        
        if (!root) {
            return nullptr; 
        }
        
        inorder(root);
        
        head->left = tail;
        tail->right = head;
        
        return head;         
        
    }
    
private: 
    
    Node* head;  // only set once for the entire runtime
    Node* tail;  // keep changing that points to the 
                 // last node of the list that we have already established
    
    void inorder(Node* currNode) {
        
        if (!currNode) {
            return;
        }
        
        // if there is left child, make the tail point to the largest node
        // of the nodes on the left side
        inorder(currNode->left);
        
        // two cases:
        // - at the head
        // - at a mid node
        if (!head) {
            /**
             * DFS: at the left most node, we will check if head is null for 
             * the FIRST time. 
             * Natually, this node turns to be the head of the list
             **/ 
            head = currNode;             
        }
        else {
            tail->right = currNode;
            currNode->left = tail;
        }
        
        // the tail points to the current node
        tail = currNode;

        // for the next recursion, the nodes on the right side will succeed 
        // to the tail   
        inorder(currNode->right);
        
    }
        
};