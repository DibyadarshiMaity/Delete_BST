#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	struct n*left,*right;
	int data;
}node;

//delete node code down there
node* del(node*root,int k)
 {
 	//base case
 	if(root==NULL)
 	return root;
 	if(k<root->data)
 	{
 		root->left=del(root->left,k);
 		return root;
	 }
	 else if(k>root->data)
	 {
	 	root->right=del(root->right,k);
	 	return root;
	 }
	 else//if the value of root ==k
	 {
	 	//checking if it has only one child node only;
	 	if(root->left==NULL)
	 	{
	 		node*temp=root->right;
	 		free(root);
	 		return temp;
		 }
		 else if(root->right==NULL)
		 {
		 	node*temp=root->left;
		 	free(root);
		 	return temp;
		 }
		 else
		 {
		 	node*psuccesor=root;
		 	node*succesor=root->right;
		 	while(succesor->left!=NULL)
		 	{
		 		psuccesor=succesor;
		 		succesor=succesor->left;
			 }
			 if(psuccesor==root)
			 {
			 	psuccesor->right=succesor->right;
			 }
			 else
			 {
			 	psuccesor->left=succesor->right;
			 }
			 root->data=succesor->data;
			 free(succesor);
			 return root;
		 }
	 	
	 }
 }