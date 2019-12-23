#include<bits/stdc++.h>
using namespace std;

int count_inversions(int A[],int N){
	int result=0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(A[i]>A[j]){
				result+=1;
			}
		}
	}
	return result;
}

int main(){
	int N;
	cout<<"Enter the size of the array"<<endl;
	cin>>N;
	int A[N];
	cout<<"Enter the array"<<endl;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	int result=count_inversions(A,N);
	cout<<"The cases where i<j and A[i]>A[j] are "<<result<<endl;
	return 0;
}