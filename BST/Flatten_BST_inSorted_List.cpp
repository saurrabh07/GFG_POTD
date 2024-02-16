#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void inorder(Node* root, Node* &prev) {
        if(root == NULL) {
            return;
        }
        inorder(root->left, prev);
        prev->right = root;
        prev->left = NULL;
        prev = root;
        inorder(root->right, prev);
    }

    Node* flattenBST(Node* root) {
        if(root == NULL) return NULL;
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        inorder(root, prev);
        prev->left = NULL;
        prev->right = NULL;
        return dummy->right;
    }
};

Node* buildBST() {
    int data;
    cout << "Enter root data: ";
    cin >> data;
    Node* root = new Node(data);

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();

        int leftData, rightData;
        cout << "Enter left child of " << curr->data << " (-1 if none): ";
        cin >> leftData;
        if (leftData != -1) {
            curr->left = new Node(leftData);
            s.push(curr->left);
        }

        cout << "Enter right child of " << curr->data << " (-1 if none): ";
        cin >> rightData;
        if (rightData != -1) {
            curr->right = new Node(rightData);
            s.push(curr->right);
        }
    }

    return root;
}

void printList(Node* root) {
    while (root != NULL) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    Node* root = buildBST();

    Solution solution;
    cout << "Original BST:" << endl;
    printList(root);
    
    Node* flattened = solution.flattenBST(root);
    cout << "Flattened BST:" << endl;
    printList(flattened);

    // Clean up the memory
    // You may want to implement a function to delete the tree nodes
    return 0;
}
