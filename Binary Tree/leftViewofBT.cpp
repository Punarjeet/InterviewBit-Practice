#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// using level order traversal 
void leftView(Node *root)
{
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 1; i <= n ; i++){
            Node *tmp = q.front();
            if(i == 1) cout << tmp->data <<" ";
            q.pop();
            if(tmp->left != NULL)
              q.push(tmp->left);
            if(tmp->right != NULL)
              q.push(tmp->right);
        }
    }
}


// using recursion
void leftViewUtil(Node *root,int level ,int *mx_level){
    if(root == NULL) return ;
    if(level > *mx_level)
    {
        cout << root->data <<" ";
        *mx_level = level;
    }
    leftViewUtil(root->left,level+1,mx_level);
    leftViewUtil(root->right,level+1,mx_level);
}
void leftView(Node *root)
{
    int mx_level = 0;
    leftViewUtil(root,1,&mx_level);
}


int main()
{
    Node *root = new Node(4);
    root->left = new Node(5);
    root->right = new Node(2);
    root->right->right = new Node(1);
    root->right->left = new Node(3);
    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);
    leftView(root);
    return 0;
}