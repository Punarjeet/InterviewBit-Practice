
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    if(root == NULL) return ;
    queue <Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *tmp = q.front();
        cout << tmp->data <<" ";
        q.pop();
        if(tmp->left != NULL)
          q.push(tmp->left);
        if(tmp->right != NULL)
          q.push(tmp->right);
    }
}
void reverseLevelOrderTraversal(Node *root){
    if(root == NULL) return ;
    queue <Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *tmp = q.front();
        cout << tmp->data <<" ";
        q.pop();
        if(tmp->right != NULL)
          q.push(tmp->right);
        if(tmp->left != NULL)
          q.push(tmp->left);
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Level order traversal of binary tree: ";
    levelOrderTraversal(root);
    cout <<"Reverse level order traversal of binary tree :" << endl;
    reverseLevelOrderTraversal(root);
    return 0;
}