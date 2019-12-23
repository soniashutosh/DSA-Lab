// Counting sort algorithm 



#include<bits/stdc++.h>
using namespace std;
template<class I>
int mini(I A[],int N){
	I min=10000;
	for(int i=0;i<N;i++){
		if(min>A[i])
			min=A[i];
	}
	return min;
};
template<class I>
int maxi(I A[],int N){
	I max=0;
	for(int i=0;i<N;i++){
		if(max<A[i])
			max=A[i];
	}
	return max;
};
int main(){
	int N;
	cout<<"Enter the number of Element on which you want to perform counting sort "<<endl;
	cin>>N;
	int A[N],C[N];
	cout<<"Enter the Elements"<<endl;
	for(int i=0;i<N;i++)
		cin>>A[i];
	int min=mini<int>(A,N),max=maxi<int>(A,N);
	int range=max-min+1;
	int B[range]={0};
	for(int i=0;i<N;i++)
		B[A[i]-min]=B[A[i]-min]+1;
	for(int i=1;i<range;i++){
		B[i]=B[i]+B[i-1];
	}
	for(int i=N-1;i>=0;i--){
		C[B[A[i]-min]-1]=A[i];
		B[A[i]-min]-=1;
	}
	cout<<"Array After Sorting is....."<<endl;
	for(int i=0;i<N;i++){
		cout<<C[i]<<"  ";
	}
	return 0;
}
