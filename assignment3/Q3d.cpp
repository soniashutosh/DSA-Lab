#include<iostream>
using namespace std;
#include<stdlib.h>

class queue
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
			cout<<endl;
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
	queue Q1,Q2,Q3;
	int out=1;
	int choice;
	int cap;
	cout<<"Enter the capacity of the Queue ...You wanna form"<<endl;
	cin>>cap;
	Q1.createqueue(cap);
	Q2.createqueue(cap);
	Q3.createqueue(cap);
	cout<<"MENU"<<endl;
	cout<<"1.Inserting an Element"<<endl;
	cout<<"2.Deleting an Element"<<endl;
	cout<<"3.Display an Element"<<endl;
	cout<<"4.Reverse the Queue"<<endl;
	cout<<"5.Exit"<<endl;
	while(out){
		cout<<"Choose the option from the MENU"<<endl;
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
				if(data){
					cout<<"Element Deleted from the Queue is "<<data<<endl;
				}
				else{
					cout<<"Your Queue is Empty"<<endl;
				}
			}break;
			case 3:{
				Q1.display();
			}break;
			case 4:{
				int high,top;
				high=Q1.givetop();
				while(high+1){
					int data;
					top=Q1.givetop();
					while(top){
						data=Q1.remove();
						Q2.insert(data);
						top--;
					}
					data=Q1.remove();
					Q3.insert(data);
					Q1=Q2;
					high--;
				}
				Q1=Q3;
				Q1.display();	
				while(high+1){
					Q2.remove();
					Q3.remove();
					high--;
				}
				Q2.set();
				Q3.set();
			}break;
			case 5:{
				out=0;
				cout<<"Your process is on the way"<<endl;
			}break;
			default :{
				cout<<"You had chosen the wrong choice ....plz try again"<<endl;
			}
		}
	}


}
