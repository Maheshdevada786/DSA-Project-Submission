#include <iostream>

using namespace std;

struct TreeNode {
    int key;
    TreeNode *left, *right;
    
    TreeNode(int key) {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

class BST {
public:
    TreeNode* root;
    
    BST() {
        root = nullptr;
    }
    
    // Insert a node
    TreeNode* insert(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }
        
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        
        return node;
    }
    
    void insert(int key) {
        root = insert(root, key);
    }
    
    // Search for a node
    TreeNode* search(TreeNode* node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }
        
        if (key < node->key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }
    
    TreeNode* search(int key) {
        return search(root, key);
    }
    
    // Delete a node
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        
        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            
            TreeNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        
        return root;
    }
    
    void deleteNode(int key) {
        root = deleteNode(root, key);
    }
    
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        
        while (current && current->left != nullptr) {
            current = current->left;
        }
        
        return current;
    }
    
    // InOrder Traversal
    void inorder(TreeNode* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }
    
    void inorder() {
        inorder(root);
        cout << endl;
    }
    
    // PreOrder Traversal
    void preorder(TreeNode* root) {
        if (root != nullptr) {
            cout << root->key << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    
    void preorder() {
        preorder(root);
        cout << endl;
    }
    
    // PostOrder Traversal
    void postorder(TreeNode* root) {
        if (root != nullptr) {
            postorder(root->left);
            postorder(root->right);
            cout << root->key << " ";
        }
    }
    
    void postorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    
    cout << "InOrder traversal: ";
    tree.inorder();
    
    cout << "PreOrder traversal: ";
    tree.preorder();
    
    cout << "PostOrder traversal: ";
    tree.postorder();
    
    cout << "\nSearch for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search for 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;
    
    cout << "\nDelete 20\n";
    tree.deleteNode(20);
    cout << "InOrder traversal: ";
    tree.inorder();
    
    cout << "\nDelete 30\n";
    tree.deleteNode(30);
    cout << "InOrder traversal: ";
    tree.inorder();
    
    cout << "\nDelete 50\n";
    tree.deleteNode(50);
    cout << "InOrder traversal: ";
    tree.inorder();
    
    return 0;
}
