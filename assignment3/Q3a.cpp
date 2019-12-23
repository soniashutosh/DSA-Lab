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
	stack S1,S2,S3;
	int out=1;
	int choice;
	int cap;
	cout<<"Enter the capacity of the stack you wanna create"<<endl;
	cin>>cap;
	S1.createstack(cap);
	S2.createstack(cap);
	S3.createstack(cap);
	cout<<"MENU"<<endl;
	cout<<"1.Inserting an Element"<<endl;
	cout<<"2.Deleting an Element"<<endl;
	cout<<"3.Display an Element"<<endl;
	cout<<"4.Swap the Element "<<endl;
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
				int top;
				top=S1.givetop();
				cout<<"Total Element in the Stack is "<<top+1<<endl;
				int index1,index2;
				cout<<"Enter the indexes you want to swap"<<endl;
				cin>>index1>>index2;
				if(index1<index2){
					int t=index1;
					index1=index2;
					index2=t;
				}
				if(index1<top+1&&index1<top+1){
					if(index1>index2){
						while(top+1-index1){
							int data;
							data=S1.remove();
							S2.insert(data);
							index1++;
						}
						int num1,num2;
						int top2;
						num1=S1.remove();
						top2=S1.givetop();
						while(top2+1-index2){
							int data;
							data=S1.remove();
							S3.insert(data);
							index2++;
						}
						num2=S1.remove();
						S1.insert(num1);
						top2=S3.givetop();
						while(top2+1){
							int data;
							data=S3.remove();
							S1.insert(data);
							top2--;
						}
						S1.insert(num2);
						top=S2.givetop();
						while(top+1){
							int data;
							data=S2.remove();
							S1.insert(data);
							top--;
						}
						cout<<"Your new stack is :"<<endl;
						S1.display();
					}
				}
				else{
					cout<<"You had entered the wrong inputs"<<endl;
				}
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
