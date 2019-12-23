#include<bits/stdc++.h>
using namespace std;
int main(){
  int vertex;
  cout<<"Enter the number of the vertex there are in the graph "<<endl;
  cin>>vertex;
  int A[vertex][vertex],B[vertex][vertex];
  for(int i=0;i<vertex;i++){
	for(int j=0;j<vertex;j++){
	  A[i][j]=0;
	  B[i][j]=0;
	}
  }
  int exit=1;
  while(exit){
	int choice;
	cout<<"MENU"<<endl;
	cout<<"1.Inserting an Edge in the graph"<<endl;
	cout<<"2.Show the graph"<<endl;
	cout<<"3.Show mimimum spanning tree"<<endl;
	cout<<"Enter the choice"<<endl;
	cin>>choice;
	switch(choice){
	  case 1:{
		int x,y;
		cout<<"Enter from which vertex to which vertex suppose ur first edge started from 1 and then onwards"<<endl;
		cin>>x>>y;
		int weight;
		cout<<"Enter the weight of the edge"<<endl;
		cin>>weight;
		A[x-1][y-1]=A[y-1][x-1]=weight;
	  }break;
	  case 2:{
	  	cout<<"Your graph is:"<<endl;
		for(int i=0;i<vertex;i++){
		  for(int j=0;j<vertex;j++){
			if(A[i][j])
			  cout<<"There is an edge between "<<i+1<<" and "<<j+1<<endl;
			}
		  }
		}break;
  	  case 3:{
		exit=0;
	  }break;
	  default:{
		cout<<"You had entered the wrong choice"<<endl;
	  }
	}
  } 
  int count=0,i=0,k=0;
  while(count<vertex-1){
    int min=99999;
	for(int j=0;j<vertex;j++){
	  if(A[k][j]){
		if(A[k][j]<min){
		  min=A[k][j];
		  i=j;
		}
	  }
	}
    for(int j=0;j<vertex;j++){
	  A[k][j]=0;
	}
	A[i][k]=0;
	B[k][i]=min;
	k=i;
	count++;
  }
  cout<<"Your Minimum spanning tree is:"<<endl;
  for(int i=0;i<vertex;i++){
    for(int j=0;j<vertex;j++){
  	  if(B[i][j]){
		cout<<"Vertex "<<i+1<<" and "<<j+1<<" are connected and weight is "<<B[i][j]<<endl;
	  }
	}
  }
  return 0;
}
