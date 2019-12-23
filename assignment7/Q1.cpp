#include<bits/stdc++.h>
using namespace std;

int main(){
	int A[10]={35,32,42,10,13,20,26,45,30,39};
	for(int i=9;i>0;i--){
		if(A[i]>A[(i-1)/2]){
			swap(A[i],A[(i-1)/2]);
		}
	}
	for(int i=0;i<10;i++){
		cout<<A[i]<<" ";
	}
	return 0;
}

//Heap Creation in O(n) time.