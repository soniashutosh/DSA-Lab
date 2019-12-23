#include<bits/stdc++.h>
using namespace std;
void Delete(int *A,int n){
  int index;
  cout<<"Enter the index you wanna delete"<<endl;
  cin>>index;
  int t=A[index-1];
  A[index-1]=A[n];
  A[n]=t;
  for(int i=index-1;i<n;){
	if(A[2*i+1]>A[2*i+2]){
	  if(2*i+1<n){
		int t=A[i];
		A[i]=A[2*i+1];
		A[2*i+1]=t;
		i=2*i+1;
	  }else{
		break;
	  }
	}
	else{
	  if(2*i+2<n){
		int t=A[i];
		A[i]=A[2*i+2];
		A[2*i+2]=t;		
			i=2*i+2;
	  }
	  else{
		break;
	  }	
	}
  }
}

int main(){
  int exit=1;
  int A[30]={35,32,42,10,13,20,26,45,30,39};
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
	  cout<<"1.Deleting the Element in the Existing heap"<<endl;
	  cout<<"2.Showing the heap in the level order traversal"<<endl;
      cout<<"3.Exit the program"<<endl;
      cout<<"Enter the choice"<<endl;
	  cin>>choice;
	  switch(choice){
		case 1:{
		  n--;
	 	  Delete(A,n);
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
		  cout<<"You had Entered the wrong choice"<<endl;
		}
	  }
	}
  return 0;
}

