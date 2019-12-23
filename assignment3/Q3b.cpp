#include<iostream>
using namespace std;
#include<stdlib.h>

class stack
{
	private:
		int top;
		int cap;
		int *array;

	public:
		void createstack(int cap){
			array=new int[cap];
			top=-1;
		}
		void insert(int data){
		 	array[++top]=data;
		}
		int remove(){
			int data;
			data=array[top];
			top--;
			if(top==-2){
				return 0;
			}
			return data;
		}
		void display(){
			int temp=top;
			while(temp!=-1){
				cout<<array[temp]<<"    ";
				temp--;
			}
			cout<<endl;
		}
		int givetop(){
			int high;
			high=top;
			return high;
		}
		void set(){
			top=-1;
		}
};

int main(){
	stack S1,S2;
	int out=1;
	int choice;
	int cap;
	cout<<"Enter the capacity of the stack you wanna create"<<endl;
	cin>>cap;
	S1.createstack(cap);
	S2.createstack(cap);
	cout<<"MENU"<<endl;
	cout<<"1.Inserting an Element"<<endl;
	cout<<"2.Deleting an Element"<<endl;
	cout<<"3.Display an Element"<<endl;
	cout<<"4.Reverse the stack"<<endl;
	cout<<"5.Exit"<<endl;
	while(out){
		cout<<"Choose the option from the MENU"<<endl;
		cin>>choice;
		switch(choice){
			case 1:{
				int data;
				cout<<"Enter the Element you wanna insert"<<endl;
				cin>>data;
				S1.insert(data);
			}break;
			case 2:{
				int data;
				data=S1.remove();
				if(data)
					cout<<"Deleted Element is "<<data<<endl;
				else
					cout<<"Stack is Empty"<<endl;
			}break;
			case 3:{
				S1.display();
			}break;
			case 4:{
				int count=S1.givetop();
				while(count+1){
					int data;
					data=S1.remove();					
					S2.insert(data);
					count--;
				}
				S1=S2;
				S1.display();
			}break;
			case 5:{
				out=0;
				cout<<"You process of Exit is on the way.."<<endl;
			}break;
			default :{
				cout<<"You had Entered the wrong choice...Plz try again later"<<endl;
			}
		}
	}
	return 0;
}
