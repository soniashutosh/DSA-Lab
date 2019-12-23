#include<bits/stdc++.h>
using namespace std;

#define f(i,s,e) for(int i=s;i<e;++i)

int binary_search(int A[],int start,int end,int key){
	int half=(start+end)/2;
	int check=0;
	/*
	if(A[end-1]>key){
		return check;
	}*/
	if(A[half]==key){
		return half;
	}
	else if(A[half]>key){
		check=binary_search(A,start,half-1,key);
	}
	else{
		check=binary_search(A,half+1,end,key);
	}
	return check;
}

void print_pattern(int A[],int N,int key){
	int c=1;
	cout<<"Searching for such pattern as asked.... Index of them are... "<<endl;
	for(int k=0;k<N-1;k++){
		for(int l=k+1;l<N-1;l++){
			int value=key-(A[l]+A[k]);
			if(value<A[k]){
				break;
			}
			//cout<<A[k]<<" "<<A[l]<<" "<<value<<endl;
			int check=binary_search(A,0,N,value);
			//cout<<check<<"heyy"<<endl;
			if(check>l){
				cout<<k+1<<" "<<l+1<<" "<<check+1<<endl;
				c=0;
				break;
			}
		}
		if(c==0){
			break;
		}
	}
	if(c){
		cout<<"No such Pattern of the same found"<<endl;
	}
}

int main(){
	int N;
	cout<<"Enter the number of Element you wanna Enter"<<endl;
	cin>>N;
	int A[N];
	cout<<"Enter the Elements in the sorted order: "<<endl;
	f(i,0,N){
		cin>>A[i];
	}
	sort(A,A+N-1);
	int key;
	cout<<"Enter the Key such that A[i]+A[j]+A[k]=key condition must be follow : ";
	cin>>key;
	print_pattern(A,N,key);
	return 0;
}