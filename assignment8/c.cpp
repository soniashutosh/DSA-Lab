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
void Change(int *A,int n){
  int data,index;
  cout<<"Enter the index where you wanna insert less than "<<n<<endl;
  cin>>index;
  if(index>n){
	cout<<"Choosen the wrong index "<<endl;
	return;
  }
  cout<<"Enter the new number you want to insert"<<endl;
  cin>>data;
  A[index-1]=data;
  for(int i=index-1;i<n;){
	if(2*i+1<n and 2*i+2<n){
	  if(A[2*i+1]>A[2*i+2] and A[2*i+1]>A[i]){
		swap(A[i],A[2*i+1]);
		i=2*i+1;
	  }
	  else if(A[2*i+2]>A[2*i+1] and A[2*i+2]>A[i]){
		swap(A[i],A[2*i+2]);
		i=2*i+2;
	  }
	  else{
		break;
	  }
	}
	else if(2*i+1){
	  if(A[2*i+1]>A[i]){
		swap(A[i],A[2*i+1]);
		i=2*i+1;
	  }
	  else{
		break;
	  }
	}
	else{
	  break;
	}
  }
}
int main(){
  int exit=1;
  int A[100]={35,32,42,10,13,20,26,45,30,39};
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
	cout<<"MENU";
	cout<<"1.Inserting the element in the heap"<<endl;
	cout<<"2.Showing the heap in the Level order traversal"<<endl;
	cout<<"3.Changing any key in the heap"<<endl;// Indexing is as according level order traversal
	cout<<"4.Exit"<<endl;
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
		Change(A,n);
	  }break;
	  case 4:{
		exit=0;
	  }break;
	  default:{
		cout<<"You had entered the wrong choice"<<endl;
	  }
    }
  }
  return 0;
}