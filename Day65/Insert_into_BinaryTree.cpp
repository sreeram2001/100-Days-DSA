
#include <iostream>
#include<queue>
using namespace std;

//each nodes struct
struct Node
{
    int data;
    Node* left;
    Node* right;
};

//function to create node
Node* CreateNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

//function insert a new node 
void insertNode(Node* root, int data)
{
    if(root == NULL)
    {
        root = CreateNode(data);
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        
        //check for the left child - if its empty or not and add new node accordingly
        if(temp->left == NULL)
        {
            temp->left = CreateNode(data);
            break;
        }
        else
        {
            q.push(temp->left);
        }
        
        //check for the right child - if its empty or not and add new node accordingly
        if(temp->right == NULL)
        {
            temp->right = CreateNode(data);
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

//inorder traversal
void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    
    if(root->left)
    {
        inorder(root->left);
    }
    
    std::cout<<root->data<<" ";
    
    if(root->right)
    {
        inorder(root->right);
    }
}

int main()
{
    Node* root = CreateNode(1);
    root->left = CreateNode(2);
    root->left->left = CreateNode(3);
    root->right = CreateNode(4);
    root->right->left = CreateNode(5);
    root->right->right = CreateNode(6);
    inorder(root);
    
    std::cout<<endl;
    insertNode(root, 7);
    inorder(root);
    
    return 0;
}
