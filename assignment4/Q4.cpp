//Implementing Bucket Sort 

#include<bits/stdc++.h>
#include<stdlib.h>
#include<vector>
using namespace std;

void print(int A[],int N){
	for(int i=0;i<N;i++){
		cout<<A[i]<<" ";
	}
}

int getmin(int A[],int N){
	int min=A[0];
	for(int i=1;i<N;i++){
		if(A[i]<min){
			min=A[i];
		}
	}
	return min;
}

int getmax(int A[],int N){
	int max=A[0];
	for(int i=1;i<N;i++){
		if(A[i]>max){
			max=A[i];
		}
	}
	return max;
}

int significantdigit(int num){
	int count=0;
	for(int i=1;num/i>0;i=i*10){
		count++;
	}
	return count;
}

void sortvec(vector <int> B,int size,int A[]){
	static int count=0;
	int C[size];
	for(int i=0;i<size;i++){
		C[i]=B[i];
	}
	sort(C,C+size);
	for(int i=0;i<size;i++){
		A[count]=C[i];
		count++;
	}
}

void Bucketsort(int A[],int N){
	int min=getmin(A,N);
	int max=getmax(A,N);
	vector <int> B0,B1,B2,B3,B4,B5,B6,B7,B8,B9;
	int digmin=significantdigit(min);
	int digmax=significantdigit(max);
	if((digmin+1)<digmax){
		cout<<"Range is high enough .....So this sortin algorithm cannot be applied"<<endl;
		exit(-1);
	}
	int num=pow(10,digmax-1);
	for(int i=0;i<N;i++){
		int choose=A[i]/num;
		switch(choose){
			case 0:B0.push_back(A[i]);break;
			case 1:B1.push_back(A[i]);break;
			case 2:B2.push_back(A[i]);break;
			case 3:B3.push_back(A[i]);break;
			case 4:B4.push_back(A[i]);break;
			case 5:B5.push_back(A[i]);break;
			case 6:B6.push_back(A[i]);break;
			case 7:B7.push_back(A[i]);break;
			case 8:B8.push_back(A[i]);break;
			case 9:B9.push_back(A[i]);break;
		}
	}
	sortvec(B0,B0.size(),A);
	sortvec(B1,B1.size(),A);
	sortvec(B2,B2.size(),A);
	sortvec(B3,B3.size(),A);
	sortvec(B4,B4.size(),A);
	sortvec(B5,B5.size(),A);
	sortvec(B6,B6.size(),A);
	sortvec(B7,B7.size(),A);
	sortvec(B8,B8.size(),A);
	sortvec(B9,B9.size(),A);
}

int main(){
	int N;
	cout<<"Enter the number of numbers you wanna store in the array : ";
	cin>>N;
	int A[N];
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	Bucketsort(A,N);
	print(A,N);
	return 0;
}