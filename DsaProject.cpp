#include <iostream>

// Define the BST node structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to search for a value in the BST
bool search(TreeNode* root, int val) {
    if (!root) {
        return false;
    }
    if (root->data == val) {
        return true;
    } else if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

// Function to find the minimum value node in a BST
TreeNode* findMin(TreeNode* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

// Function to delete a value from the BST
TreeNode* deleteNode(TreeNode* root, int val) {
    if (!root) {
        return nullptr;
    }
    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* minRight = findMin(root->right);
        root->data = minRight->data;
        root->right = deleteNode(root->right, minRight->data);
    }
    return root;
}

// In-order traversal (left-root-right)
void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;

    // Insert values into the BST
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);

    // Search for a value
    std::cout << "Search for 7: " << (search(root, 7) ? "Found" : "Not found") << std::endl;

    // Delete a value
    root = deleteNode(root, 5);

    // In-order traversal
    std::cout << "In-order traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    // Clean up memory (optional)
    // You can add a function to delete the entire tree recursively

    return 0;
}

