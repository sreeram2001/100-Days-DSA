#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
class node 
{ 
	public:
	int data; 
	node* left; 
	node* right; 
}; 

/* utility that allocates a new node with the 
given data and NULL left and right pointers. */
node* newnode(int data) 
{ 
	node* Node = new node();
	Node->data = data; 
	Node->left = NULL; 
	Node->right = NULL; 
	
	return(Node); 
} 

void getPath(node* root, vector<int> arr, vector<vector<int>>& op)
{
    if(root == NULL)
    {
        return; 
    }
    
    arr.push_back(root->data); 
    
    if(root->left == NULL && root->right == NULL)
    {
        op.push_back(arr); 
    }
    
    getPath(root->left, arr, op); 
    getPath(root->right, arr, op); 
    
    arr.pop_back(); 
}

/* Driver code*/
int main() 
{ 
	
	/* Constructed binary tree is 
				10 
			/ \ 
			8 2 
		/ \ / 
		3 5 2 
	*/
	node *root = newnode(10); 
	root->left = newnode(8); 
	root->right = newnode(2); 
	root->left->left = newnode(3); 
	root->left->right = newnode(5); 
	root->right->left = newnode(2); 
	
	vector<vector<int>> op; 
	vector<int> ans; 
	getPath(root, ans, op); 
	
	for(int i=0; i<op.size(); i++)
	{
	    for(int j=0; j<op[i].size(); j++)
	    {
	        std::cout<<op[i][j]<<" ";
	    }
	    
	    std::cout<<"\n";
	}
	
	return 0; 
} 

