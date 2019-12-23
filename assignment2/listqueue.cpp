#include<iostream>
using namespace std;
#include<stdlib.h>

struct listnode{
	int data;
	struct listnode *tail;
};

struct listnode *head=NULL,*last=NULL;

class Queue
{
	private:
		int top,bottom;

	public:
		void insert(int data){
			struct listnode *temp,*start;
			temp=new listnode;
			temp->tail=NULL;
			temp->data=data;
			start=head;
			if(head==NULL){
				head=temp;
				last=temp;
			}
			else{
				last->tail=temp;
				last=temp;
			}
		}
		int remove(){
			int data;
			struct listnode *temp,*start;
			if(head==NULL){
				cout<<"Queue is Empty"<<endl;
				return 0;
			}
			start=head;
			data=start->data;
			head=start->tail;
			return data;
		}
		void display(){
			struct listnode *temp,*start;
			start=head;
			if(start!=NULL)
				cout<<"Element in the Queue is "<<endl;
			else
				cout<<"Queue is Empty"<<endl;
			while(start!=NULL){
				cout<<start->data<<"  ";
				start=start->tail;
			}
			cout<<endl;
		}
};

int main(){
	Queue Q1;
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
				Q1.insert(data);
			}break;
			case 2:{
				int data;
				data=Q1.remove();
				if(data)
					cout<<"Deleted Element from the Queue is "<<data<<endl;
			}break;
			case 3:{
				Q1.display();
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