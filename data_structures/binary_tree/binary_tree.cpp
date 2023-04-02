#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void preOrder(Node *node){
    if(node == NULL)
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node *node){
    if(node == NULL)
        return;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void postOrder(Node *node){
    if(node == NULL)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "PreOrder Traversal\n";
    preOrder(root);
    cout << endl;
    cout << "InOrder Traversal\n";
    inOrder(root);
    cout << endl;
    cout << "PostOrder Traversal\n";
    postOrder(root);

    cout << endl;

    return 0;
}