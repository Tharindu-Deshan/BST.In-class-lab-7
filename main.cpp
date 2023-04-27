#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};
struct node *temp;

struct node *findMin(struct node*root){
    if(root==NULL){
        return NULL;
    }
    if(root->left){
        return findMin(root->left);
    }
    else{
        return root;
    }
}

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root==NULL){
        return;
    }
    traverseInOrder(root->left);
    cout<<root->key<<" ";
    traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node==NULL){
        node = new struct node;
        node->key=key;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    else if(key>(node->key)){
        node->right= insertNode(node->right,key);
    }
    else if(key<(node->key)){
        node->left= insertNode(node->left,key);
    }
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if(root==NULL){
        cout<<" Empty BST."<<endl;
    }
    else if(key<root->key){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->key){
        root->right=deleteNode(root->right,key);
    }
    else{
        if((root->right!=NULL) && (root->left!=NULL)){
            temp=findMin(root->right);
            root->key=temp->key;
            root->right=deleteNode(root->right,temp->key);
        }
        if(root->left==NULL){
            root=root->right;
        }
        else if(root->right==NULL){
            root=root->left;
        }
        free(temp);
    }
    return root;
}

// Driver code
int main() {
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                cin >> operation;
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
    }

    traverseInOrder(root);
}