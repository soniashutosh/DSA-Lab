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
	cout<<"4.Swap the Element in the Queue "<<endl;
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
				int total,total1,total2,left1;
				total=Q1.givetop();
				cout<<"Total number of Element in the Queue "<<total<<endl;
				int index1,index2;
				cout<<"Enter the index you wanna swap "<<endl;
				cin>>index1>>index2;
				if(index1<index2){
					int t=index1;
					index1=index2;
					index2=t;
				}
				int small,big;
				small=index2;
				big=index1;
				if(index1>index2&&index1<=total+1){
					int num1,num2;
					while(small-1){
						int data;
						data=Q1.remove();
						Q2.insert(data);
						small--;
					}
					num1=Q1.remove();
					cout<<"Get num1"<<endl;
					while(big-index2-1){
						int data;
						data=Q1.remove();
						Q3.insert(data);
						big--;
					}
					num2=Q1.remove();
					Q2.insert(num2);
					total1=Q3.givetop();
					cout<<"Total1"<<total1<<endl;
					while(total1){
						int data;
						data=Q3.remove();
						Q2.insert(data);
						total1--;
					}
					Q2.insert(num1);
					total2=Q1.givetop();
					left1=Q1.givebottom();
					while(total2-left1){
						int data;
						data=Q1.remove();
						Q2.insert(data);
						total2--;
					}
					Q1=Q2;
					cout<<"Resultant is :"<<endl;
					Q1.display();
				}
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
