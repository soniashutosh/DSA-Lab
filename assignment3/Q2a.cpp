#include<iostream>
using namespace std;
#include<stdlib.h>

struct listnode{
	int data;
	struct listnode *tail;
};

struct listnode *head=NULL,*last=NULL;

class stack
{
	private:
		int top;
	public:
		void insert(int data){
			struct listnode *temp,*start;
			temp=new listnode;
			temp->tail=NULL;
			temp->data=data;
			start=head;
			if(head==NULL){
				head=temp;
			}
			else{
				while(start->tail!=NULL){
					start=start->tail;
				}
				start->tail=temp;
			}
		}

		int remove(){
			int data=0;
			struct listnode *temp,*start;
			start=head;
			if(start==NULL){
				cout<<"Stack is Empty"<<endl;
				return 0;
			}
			else{
				int num=0;
				while(start->tail!=NULL){
					start=start->tail;
					num++;
				}
				data=start->data;
				start=head;
				while(num-1){
					if(num==0){
						break;
					}
					start=start->tail;
					num--;
				}
				start->tail=NULL;
			}
			return data;
		}

		void display(){
			struct listnode *temp,*start;
			start=head;
			if(start!=NULL)
				cout<<"Element in the Stack is "<<endl;
			else
				cout<<"Stack is Empty"<<endl;
			while(start!=NULL){
				cout<<start->data<<"  ";
				start=start->tail;
			}
			cout<<endl;
		}	
};

int main(){
	stack S1;
	int end=1,choice;
	cout<<"MENU"<<endl;
	cout<<"1.Inserting an Element"<<endl;
	cout<<"2.Deleting an Element"<<endl;
	cout<<"3.Display an Element"<<endl;
	cout<<"4.Exit"<<endl;
	while(end){
		cout<<"Enter the choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1:{
				int data;
				cout<<"Enter the data you wanna Enter "<<endl;
				cin>>data;
				S1.insert(data);
			}break;
			case 2:{
				int data;
				data=S1.remove();
				if(data)
					cout<<"Deleted Element from the Stack is "<<data<<endl;
			}break;
			case 3:{
				S1.display();
			}break;
			case 4:{
				end=0;
			}break;
			default :{
				cout<<"You had Entered wrong input.....Plz try again later"<<endl;
			}
		}
	}
	return 0;
}