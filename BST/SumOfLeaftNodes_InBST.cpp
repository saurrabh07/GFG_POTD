#include <iostream>
using namespace std;

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Solution class
class Solution {
public:
    // Function to calculate the sum of leaf nodes in a binary tree
    int sumOfLeafNodes(Node* root) {
        // If the tree is empty, return 0
        if (root == nullptr) {
            return 0;
        }
        // If the node is a leaf node, return its data
        if (root->left == nullptr && root->right == nullptr) {
            return root->data;
        }
        // Recursively calculate the sum of leaf nodes in the left and right subtrees
        int leftSum = sumOfLeafNodes(root->left);
        int rightSum = sumOfLeafNodes(root->right);
        // Return the sum of leaf nodes in both subtrees
        return leftSum + rightSum;
    }
};

int main() {
    // Input the number of nodes in the binary tree
    int n;
    cout << "Enter the number of nodes in the binary tree: ";
    cin >> n;

    // Input the values of nodes in the binary tree
    cout << "Enter the values of nodes in the binary tree (enter -1 for NULL nodes):\n";
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val != -1) {
            if (root == nullptr) {
                root = new Node(val);
            } else {
                // Create the binary tree using level order traversal
                // (Not implemented here, assume input is in level order format)
            }
        }
    }

    // Instantiate the Solution class
    Solution solution;

    // Calculate the sum of leaf nodes in the binary tree
    int leafNodeSum = solution.sumOfLeafNodes(root);

    // Print the sum of leaf nodes
    cout << "Sum of leaf nodes in the binary tree: " << leafNodeSum << endl;

    return 0;
}
