// Search a given ley value in the binary search tree
// Inserting a Element in binary search tree
// In-Order Traversal for the given Binary search tree

#include<bits/stdc++.h>
using namespace std;

struct BST{
	int data;
	struct BST *left,*right;
};

// Inserting an Element in Binary Search Tree

struct BST * Insert(struct BST *root,int num){
	struct BST *temp;
	temp=new (struct BST);
	temp->left=NULL;
	temp->right=NULL;
	temp->data=num;
	if(root==NULL){
		root=temp;
		return root;
	}
	if(num<root->data){
		root->left=Insert(root->left,num);
	}
	else{
		root->right=Insert(root->right,num);
	}
	return root;
}

//Traversing Inorder in Binary Search tree

void Inorder(struct BST *root){
	if(root!=NULL){
		Inorder(root->left);
		cout<<(root->data)<<"  ";
		Inorder(root->right);
	}
}

// Serach In the Binary Search Tree

void BSTsearch(struct BST *root,int num){
	if(root==NULL){
		cout<<"Element not found"<<endl;
	}
	else{
		if(num==root->data){
			cout<<"Element found"<<endl;
		}
		else{
			if(num<root->data){
				BSTsearch(root->left,num);
			}
			else{
				BSTsearch(root->right,num);
			}
		}
	}
}

int main(){
	int choice,exit=1;
	struct BST *root=NULL;
	cout<<"MENU"<<endl;
	cout<<"1. Insert a Element in the Binary search tree"<<endl;
	cout<<"2. Traversing in the tree"<<endl;
	cout<<"3. Search a given key in the Binary Search tree"<<endl;
	cout<<"4. Exit"<<endl;
	while(exit){
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1:{
				int num;
				cout<<"Enter the number you want to insert"<<endl;
				cin>>num;
				root=Insert(root,num);
			}break;
			case 2:{
				Inorder(root);
			}break;
			case 3:{
				int num;
				cout<<"Enter the number you wanna search"<<endl;
				cin>>num;
				BSTsearch(root,num);
			}break;
			case 4:{
				cout<<"Your Exiting Process is on the Way"<<endl;
				exit=0;
			}break;
			default :{
				cout<<"You have Entered the Wrong choice"<<endl;
			}
		}
	}
	return 0;
}
