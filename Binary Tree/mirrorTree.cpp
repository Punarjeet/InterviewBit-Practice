#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int data;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// print mirror recursively
void mirrorTree(Node *root)
{
    if(root == NULL) return;
    else{
        mirrorTree(root->left);
        mirrorTree(root->right);
        Node *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
}

// printing mirror of tree using level order traversal iterative method
void levelOrderTraversal(Node *root)
{
    queue <Node *>q;
    q.push(root);
    while(!q.empty())
    {
        Node *tmp = q.front();
        // cout << tmp->data <<" " ;
        q.pop();
        swap(tmp->left,tmp->right);
        if(tmp->left != NULL)
          q.push(tmp->left);
        if(tmp->right != NULL)
          q.push(tmp->right);
    }
}
void inorderTraversal(Node *root)
{
    if(root == NULL) return ;
    inorderTraversal(root->left);
    cout << root->data <<" " ;
    inorderTraversal(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    // inorderTraversal(root);
    // mirrorTree(root);
    // inorderTraversal(root);
    levelOrderTraversal(root); 
    return 0;
}