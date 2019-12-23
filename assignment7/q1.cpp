// Making of max heap in the tree format


#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
};

void Traverse(struct Node *root){
	if(root!=NULL){
		Traverse(root->left);
		cout<<root->data<<" ";
		Traverse(root->right);
	}
}

void heapify(struct Node *root){
	if(root){
		if(!root->right){
			if(root->data<root->left->data){
				int val;
				val=root->data;
				root->data=root->left->data;
				root->left->data=val;
			}
		}
		else{
			if(root->data<root->left->data or root->data<root->right->data){
				int max=root->left->data;
				if(max<root->right->data){
					max=root->right->data;
					int val;
					val=root->data;
					root->data=root->right->data;
					root->right->data=val;
				}
				else{
					int val=root->data;
					root->data=root->left->data;
					root->left->data=val;
				}
			}
		}
	}
}

struct Node* Insertion(struct Node *root,int data){
	struct Node *temp=new (struct Node);
	temp->data=data;
	temp->left=temp->right=NULL;
	if(root==NULL){
		root=temp;
		cout<<root->data;
		return root;
	}
	else if(!root->left){
		root->left=temp;
		heapify(root);
		return root;
	}
	else if(!root->right){
		root->right=temp;
		heapify(root);
		return root;
	}
	else{
		if(root->left->left and root->left->right){
			root->right=Insertion(root->right,data);
			heapify(root);
		}
		else{
			root->left=Insertion(root->left,data);
			heapify(root);
		}
	}
	return root;
	/*if(root->data<root->left->data or root->data<root->right->data){
		int value=max(root->left->data,root->right->data);
		swap(root->data,value);
		return root;
	}*/
}

int main(){
	int exit=1;
	struct Node *root=NULL;
	while(exit){
		int choice;
		cout<<"MENU"<<endl;
		cout<<"1.Insertion of Element in the Heap"<<endl;
		cout<<"2.Travering the heap in In-order traversal"<<endl;
		cout<<"3.Exit"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1:{
				int data;
				cout<<"Enter the Element you want to insert"<<endl;
				cin>>data;
				root=Insertion(root,data);
			}break;
			case 2:{
				Traverse(root);
			}break;
			case 3:{
				exit=0;
			}break;
			default:{
				cout<<"You had Entered the wrong choice"<<endl;
			}
		}
	}
	return 0;
}