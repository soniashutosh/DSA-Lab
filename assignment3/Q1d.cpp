// Queue Implementation using Stack


#include<iostream>
using namespace std;

class stack
{
	private:
		int cap;
		int top;
		int *array;
	public:
		void createstack(int cap){
			array=new int[cap];
			top=-1;
		}
		int givetop(){
			int high;
			high=top;
			return high;
		}
		void insert(int data){
		 	array[++top]=data;
		}
		int remove(){
			int data;
			data=array[top];
			top--;
			return data;
		}
		void display(){
			int temp=top;
			while(temp!=-1){
				cout<<array[temp]<<"    ";
				temp--;
			}
		}
		void showelement(int val){
			cout<<array[val]<< "   ";
		}
};

int main(){
	stack S1,S2;
	int out=1;
	int choice;
	cout<<"MENU"<<endl;
	cout<<"1.Create Queue"<<endl;
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
				cout<<"Enter the capacity of the Queue"<<endl;
				cin>>cap;
				S1.createstack(cap);
				S2.createstack(cap);
				cout<<"Your Queue is formed"<<endl;
			}break;
			case 2:{
				int data;
				cout<<"Enter the element you wanna insert"<<endl;
		 		cin>>data;
				S1.insert(data);
			}break;
			case 3:{
				int high;
				high=S2.givetop();
				if(high==-1){
					int high2;
					int data;
					high2=S1.givetop();
					while(high2+1){
						data=S1.remove();
						S2.insert(data);
						high2--;
					}
				}
				int show;
				show=S2.remove();
				if(show)
					cout<<"Deleted Element from the Queue is :"<<show<<endl;
				else
					cout<<"Your Queue is Empty "<<endl;
			}break;
			case 4:{
				int high;
				int count=0;
				high=S2.givetop();
				if(high==-1){
					int high2;
					int data;
					high2=S1.givetop();
					while(high2+1){
						data=S1.remove();
						S2.insert(data);
						count++;
						high2--;
					}
				}
				
				cout<<"Elements of the Queue are:"<<endl;
				
				S2.display();	
				int high3=S1.givetop();
				if(high3!=-1){
					int i=0;
					while(i<=high3){
						S1.showelement(i);
						i++;
					}
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
