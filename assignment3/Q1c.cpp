// Stack Implementation using Queue..

#include<iostream>
using namespace std;

class Queue
{
	private:
		int cap;
		int top,bottom;
		int *array;
	public:
		void createqueue(int cap){
			array=new int[cap];
			top=-1;
			bottom=-1;
		}
		void insert(int data){
			array[++top]=data;
		}
		int remove(){
			int data;
			data=array[++bottom];
			return data;
		}
		void display(){
			int temp=bottom;
			while((temp+1)<=top){
				cout<<array[temp+1]<<"   ";
				temp++;
			}
		}
		int givetop(){
			int temp=top;
			return temp;
		}
		int givebottom(){
			int temp=bottom;
			return bottom;
		}
		void showelement(int var){
			cout<<array[var]<<"   ";
		}
		void set(){
			bottom=-1;
			top=-1;
		}
};

int main(){
	Queue Q1,Q2;
	int out=1;
	int choice;
	cout<<"1.Create Stack"<<endl;
	cout<<"2.Inserting an Element"<<endl;
	cout<<"3.Deleting an Element"<<endl;
	cout<<"4.Display an Element"<<endl;
	cout<<"5.Exit"<<endl;
	while(out){
		cout<<"Choose the option from the MENU"<<endl;
		cin>>choice;
		switch(choice){
			case 1:{
				int cap;
				cout<<"Enter the Capacity of the Stack you wanna formed"<<endl;
				cin>>cap;
				Q1.createqueue(cap);
				Q2.createqueue(cap);
				cout<<"Your Stack has been created"<<endl;
			}break;
			case 2:{
				int temp;
				cout<<"Enter the element you wanna insert"<<endl;
				cin>>temp;
				Q1.insert(temp);
			}break;
			case 3:{
				int temp,high1,high2;
				high1=Q1.givetop();
				high2=Q2.givetop();
				if(high1+1){
					while(high1){
						temp=Q1.remove();
						Q2.insert(temp);
						high1--;
					}
					temp=Q1.remove();
					cout<<"Deleted Element from the Stack is "<<temp<<endl;
					Q1.set();
				}
				else if(high2+1){
					while(high2){
						temp=Q2.remove();
						Q1.insert(temp);
						high2--;
					}
					temp=Q2.remove();
					cout<<"Deleted Element from the Stack is "<<temp<<endl;
					Q2.set();
				}
				else{
					cout<<"Stack is Empty"<<endl;
				}
			}break;
			case 4:{
				Q2.display();
				Q1.display();
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
