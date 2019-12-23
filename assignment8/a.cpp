#include<bits/stdc++.h>
using namespace std;
void Insert(int *A,int n){
  int data;
  cout<<"Enter the number you want to insert"<<endl;
  cin>>data;
  A[n]=data;
  for(int i=n;i>0;i=(i-1)/2){ 
    if(A[i]>A[(i-1)/2]){
    int t;
    t=A[i];
    A[i]=A[(i-1)/2];
    A[(i-1)/2]=t;
  	}
  } 
}
int main(){
  int exit=1,A[30]={35,32,42,10,13,20,26,45,30,39};
  int n=10;
  for(int i=9;i>0;i--){
	if(A[i]>A[(i-1)/2]){
	  swap(A[i],A[(i-1)/2]);
	}
  }
  cout<<"Existing heap is: "<<endl;
  for(int i=0;i<n;i++){
	cout<<A[i]<<" ";
  }
  cout<<endl;
  while(exit){
	int choice;
	cout<<"MENU"<<endl;
	cout<<"1.Inserting the element in the heap"<<endl;
	cout<<"2.Showing the heap in the Level order traversal"<<endl;
	cout<<"3.Exit"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>choice;
	switch(choice){
	  case 1:{
		Insert(A,n);
		n++;
	  }break;
	  case 2:{	
		for(int i=0;i<n;i++){
		  cout<<A[i]<<" ";
		}
		cout<<endl;
	  }break;
	  case 3:{
		exit=0;
	  }break;
	  default:{
		cout<<"You had entered the wrong choice"<<endl;
	  }
	}
  }
  return 0;
}