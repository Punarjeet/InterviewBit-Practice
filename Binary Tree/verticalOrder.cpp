#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void verticalOrder(Node *root, int hd, map<int, vector <int> > &m){
    if(root == NULL) return ;
    m[hd].push_back(root->data);
    verticalOrder(root->left,hd-1,m);
    verticalOrder(root->right,hd+1,m);
}

void printVerticalOrder(Node *root){
    map <int,vector <int> > m;
    int hd = 0 ;
    verticalOrder(root,hd,m);
    map <int,vector <int> > :: iterator it ;
    for(it = m.begin(); it != m.end(); it++){
        for(int j = 0 ; j < it->second.size(); j++){
            cout << it->second[j] <<" " ;
        }
        cout << endl;
    }
}


// using level order traversal 

void verticalOrderTrav(Node *root){
    if(!root) return ;
    map <int,vector<int> > m ;
    int hd = 0;
    queue <pair <Node*,int> >q;
    q.push(make_pair(root,hd));
    while(!q.empty())
    {
        pair<Node*, int>  tmp = q.front();
        q.pop();
        hd = tmp.second;
        Node *node = tmp.first;
        m[hd].push_back(node->data);
        if(node->left != NULL) 
          q.push(make_pair(node->left,hd-1));
        if(node->right)
          q.push(make_pair(node->right,hd+1));
    }
    map <int, vector <int> > :: iterator it = m.begin();
    for(;it != m.end(); it++){
        for(int i = 0 ; i < it->second.size(); i++){
            cout << it->second[i] <<" ";
        }
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->left->right = new Node(8);
    printVerticalOrder(root);
    cout << endl;
    verticalOrderTrav(root);
    return 0;
}