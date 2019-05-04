#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node* right;
    Node (int data)
    {
        this->data= data;
        left = right = NULL;
    }
};


void inorderTraversal(Node *root)
{
  if(root == NULL) return ;
  inorderTraversal(root->left);
  cout << root->data << " " ;
  inorderTraversal(root->right);
}
void preorderTraversal(Node *root)
{
    if(!root) return;
    cout << root->data <<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node *root)
{
    if(!root) return ;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data <<" " ;
}
int height(Node *root)
{
    // if (root == NULL) return 0;
    // return height(root->left) > height(root->right) ? height(root->left+1) : height(root->right+1); 
    if(root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r) ? l+1:r+1;
}
int countLeaf(Node *root)
{
    if(!root) return 0;
    if(root->left == NULL && root->right ==NULL) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}
bool isleaf(Node *root)
{
    if(root == NULL) return true;
    if(root->left ==NULL && root->right == NULL) return true;
    return false;
}
int levelorderTraversal(Node *root)
{
    queue <Node *> q;
    q.push(root);
    int cnt = 0 ;
    int s = -1;
    while(!q.empty())
    {
        s++;
        Node *tmp = q.front();
       cout << tmp->data <<" " ;
        if(isleaf(tmp))
        {
            cnt++;
        }
        q.pop();
        if(tmp->left != NULL)
          q.push(tmp->left);
        if(tmp->right != NULL)
          q.push(tmp->right);
    }
    cout << "size : " << s << endl;
    return cnt;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preorderTraversal(root);
    cout << endl;
    inorderTraversal(root);
    cout << endl;
    postorderTraversal(root);
    cout << endl;
    cout << "Height of tree : " << height(root) << endl;
    cout << "total leaf nodes in tree is :" << countLeaf(root) << endl;
    cout << "level order traversal : ";
    cout << "leaf" << levelorderTraversal(root);

    return 0;
}