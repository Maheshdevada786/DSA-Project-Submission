#include <iostream>
using namespace std;


class Node {
public:
    int data;  // Data part of the node
    Node* left;  // Pointer to the left child
    Node* right; // Pointer to the right child

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

  
    BinarySearchTree() {
        root = nullptr;
    }

    // Function to insert a node in the tree
    void insert(int value) {
        root = insertRec(root, value);
    }

  
    Node* insertRec(Node* node, int value) {
     
        if (node == nullptr) {
            return new Node(value);
        }

     
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        }
        // If value is greater, go to the right subtree
        else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
    }


    bool search(int value) {
        return searchRec(root, value);
    }

    // Recursive function to search for a value
    bool searchRec(Node* node, int value) {
        // If tree is empty or we reach a leaf node
        if (node == nullptr) {
            return false;
        }

        // If the value is found
        if (node->data == value) {
            return true;
        }

        // Recur on left subtree if the value is less than the current node
        if (value < node->data) {
            return searchRec(node->left, value);
        }
        // Recur on right subtree if the value is greater than the current node
        else {
            return searchRec(node->right, value);
        }
    }

    // Function to delete a node from the tree
    void deleteNode(int value) {
        root = deleteRec(root, value);
    }

    // Recursive function to delete a node
    Node* deleteRec(Node* node, int value) {
        // If tree is empty
        if (node == nullptr) {
            return node;
        }

        // Recur down the tree to find the node to delete
        if (value < node->data) {
            node->left = deleteRec(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteRec(node->right, value);
        }
        // If the value is the same as node's data, this is the node to be deleted
        else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(node->right);

            // Copy the inorder successor's data to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = deleteRec(node->right, temp->data);
        }

        return node;
    }

    // Function to find the minimum value node in a given tree
    Node* minValueNode(Node* node) {
        Node* current = node;

        // Loop to find the leftmost leaf
        while (current && current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    // Function to print the tree in InOrder Traversal
    void inOrder() {
        inOrderRec(root);
        cout << endl;
    }

    // Recursive function for InOrder Traversal
    void inOrderRec(Node* node) {
        if (node == nullptr)
            return;

        inOrderRec(node->left);    // Traverse the left subtree
        cout << node->data << " "; // Print the node
        inOrderRec(node->right);   // Traverse the right subtree
    }
};

// Main function to demonstrate the Binary Search Tree operations
int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "InOrder traversal of the BST: ";
    bst.inOrder(); // Output: 20 30 40 50 60 70 80

    cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << endl; // Output: Found
    cout << "Search 25: " << (bst.search(25) ? "Found" : "Not Found") << endl; // Output: Not Found

    cout << "Deleting node 20\n";
    bst.deleteNode(20);
    cout << "InOrder traversal after deletion: ";
    bst.inOrder(); // Output: 30 40 50 60 70 80

    cout << "Deleting node 30\n";
    bst.deleteNode(30);
    cout << "InOrder traversal after deletion: ";
    bst.inOrder(); // Output: 40 50 60 70 80

    cout << "Deleting node 50\n";
    bst.deleteNode(50);
    cout << "InOrder traversal after deletion: ";
    bst.inOrder(); // Output: 40 60 70 80

    return 0;
}
