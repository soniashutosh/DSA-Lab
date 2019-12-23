// Implementation of radix sort using counting sort;

#include<bits/stdc++.h>
using namespace std;

int getmax(int A[],int N){
	int max=0;
	for(int i=0;i<N;i++){
		if(A[i]>max){
			max=A[i];
		}
	}
	return max;
}

void print(int A[],int N){
	for(int i=0;i<N;i++){
		cout<<A[i]<<" ";
	}
}


void setdigit(int A[],int N,int digit){
	int C[N];
	int count[10]={0};
	for(int i=0;i<N;i++)
		count[(A[i]/digit)%10]++;
	for(int i=1;i<10;i++)
		count[i]+=count[i-1];
	for (int i=N-1;i>=0;i--){ 
        C[count[(A[i]/digit)%10]-1]=A[i]; 
        count[(A[i]/digit)%10]--; 
    } 
    for(int i=0;i<N;i++)
    	A[i]=C[i];
}

void radixsort(int A[],int N){
	int max=getmax(A,N);
	for(int i=1;max/i>0;i=i*10){
		setdigit(A,N,i);
	}
}

int main(){
	int N,d=0;
	cout<<"Enter the size of array you want : ";
	cin>>N;
	int A[N];
	cout<<"Enter the array:"<<endl;
	for(int i=0;i<N;i++){
		cin>>A[i];      
	}
	radixsort(A,N);
	cout<<"After Radixsort the array resultant is : "<<endl;
	print(A,N);
	return 0;
}