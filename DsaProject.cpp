#include <iostream>
using namespace std;


class Node {
public:
    int data;  
    Node* left;  
    Node* right; 

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};


class BinarySearchTree {
public:
    Node* root;

   
    BinarySearchTree() {
        root = NULL;
    }

    
    void insert(int value) {
        root = insertRec(root, value);
    }

   
    Node* insertRec(Node* node, int value) {
        
        if (node == NULL) {
            return new Node(value);
        }

        
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        }
        
        else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    
    bool search(int value) {
        return searchRec(root, value);
    }

  
    bool searchRec(Node* node, int value) {
       
        if (node == NULL) {
            return false;
        }

        
        if (node->data == value) {
            return true;
        }

        
        if (value < node->data) {
            return searchRec(node->left, value);
        }
        
        else {
            return searchRec(node->right, value);
        }
    }

    
    void deleteNode(int value) {
        root = deleteRec(root, value);
    }

   
    Node* deleteRec(Node* node, int value) {
        
        if (node == NULL) {
            return node;
        }

       
        if (value < node->data) {
            node->left = deleteRec(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteRec(node->right, value);
        }
  
        else {
            
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            
            Node* temp = minValueNode(node->right);

           
            node->data = temp->data;

            
            node->right = deleteRec(node->right, temp->data);
        }

        return node;
    }

    
    Node* minValueNode(Node* node) {
        Node* current = node;

        
        while (current && current->left != NULL) {
            current = current->left;
        }

        return current;
    }

   
    void inOrder() {
        inOrderRec(root);
        cout << endl;
    }

    
    void inOrderRec(Node* node) {
        if (node == NULL)
            return;

        inOrderRec(node->left);    
        cout << node->data << " "; 
        inOrderRec(node->right);   
    }
};


int main() {
    BinarySearchTree b;

    b.insert(50);
    b.insert(30);
    b.insert(20);
    b.insert(40);
    b.insert(70);
    b.insert(60);
    b.insert(80);

    cout << "InOrder traversal of the BST: ";
    b.inOrder(); 

    
    if(b.search(30)){
    	cout<<" The element is Found"<<endl;
	}else{
		cout<<" The element is Not found"<<endl;
	}
	if(b.search(40)){
        cout<<" The element is Found"<<endl;
	}else{
		cout<<" The element is Not found"<<endl;
	}
    
   if(b.search(25)){
    	cout<<" The element is Found"<<endl;
	}else{
		cout<<" The element is Not found"<<endl;
	}

    cout << "Deleting node 20"<<endl;
    b.deleteNode(20);
    cout << "InOrder traversal after deletion: ";
    b.inOrder(); 

    cout << "Deleting node 30"<<endl;
    b.deleteNode(30);
    cout << "InOrder traversal after deletion: ";
    b.inOrder(); 

    cout << "Deleting node 50"<<endl;
    b.deleteNode(50);
    cout << "InOrder traversal after deletion: ";
    b.inOrder(); 

    return 0;
}
