#include<bits/stdc++.h>
using namespace std;

void convert_to_min_heap(int *A,int N){
	for(int i=N-1;i>0;i--){
		if(A[i]<A[(i-1)/2]){
			swap(A[i],A[(i-1)/2]);
		}
		if((2*i+1)<N){
			for(int j=i;2*j+1<N;){
				if((2*j+2)<N){
					if(A[j]>A[2*j+1]||A[j]>A[2*j+2]){
						if(A[2*j+1]>A[2*j+2]){
							swap(A[j],A[2*j+2]);
							j=2*j+2;
						}
						else{
							swap(A[j],A[2*j+1]);
							j=2*j+1;
						}
					}
					else{
						break;
					}
				}
				else{
					if(A[j]>A[2*j+1]){
						swap(A[j],A[2*j+1]);
						j=2*j+1;
					}
					else{
						break;
					}
				}
			}
		}
	}
}

int main(){
	int A[10]={35,32,42,10,13,20,26,45,30,39};
	for(int i=9;i>0;i--){
		if(A[i]>A[(i-1)/2]){
			swap(A[i],A[(i-1)/2]);
		}
	}
	cout<<"Max Heap for given input is: "<<endl;
	for(int i=0;i<10;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	cout<<"After converting Max heap to min heap :"<<endl;
	convert_to_min_heap(A,10);
	for(int i=0;i<10;i++){
		cout<<A[i]<<" ";
	}
	return 0;
}
