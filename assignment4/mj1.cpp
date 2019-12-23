// Given a binary array,sort it in linear time and constant space.Output should print aal zeroes followed by all ones.

#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,count=0;
	cout<<"Enter the size of the array containing Binary numbers   :";
	cin>>N;
	int A[N];
	cout<<"Enter the Array :"<<endl;
	for(int i=0;i<N;i++){
		cin>>A[i];
		if(A[i]==1){
			count++;
		}
	}
	cout<<"Your array After placing zeroes at beginning and ones at last is :"<<endl;
	for(int i=0;i<N-count;i++){
		A[i]=0;
	}
	for(int i=N-count;i<N;i++){
		A[i]=1;
	}
	for(int i=0;i<N;i++){
		cout<<A[i]<<"  ";
	}
	return 0;
}