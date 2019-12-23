#include<bits/stdc++.h>
using namespace std;

void makeheap(int *A,int count){
	for(int i=count;i>0;i--){
		if(A[i]>A[(i-1)/2]){
			swap(A[i],A[(i-1)/2]);
		}
	}
}

int main(){
	int A[10]={35,32,42,10,13,20,26,45,30,39};
	for(int i=9;i>=0;i--){
		int count=i;
		if(count<9){
			swap(A[0],A[count+1]);
		}
		makeheap(A,i);
	}
	cout<<"After applying heapsort the output be like"<<endl;
	for(int i=0;i<10;i++){
		cout<<A[i]<<" ";
	}
	return 0;
}