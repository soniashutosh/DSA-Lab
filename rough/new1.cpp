#include<iostream>
using namespace std;

int main(){
	long int N;
	cin>>N;
	long int A[N];
	for(long int i=0;i<N;i++){
		cin>>A[i];
	}
	long int G=0,B=0;
	for(long int i=0;i<N;i=i+2){
		G=G+A[i];
	}
	for(long int i=1;i<N;i=i+2){
		B=B+A[i];
	}
	long int dif;
	dif=G-B;
	cout<<dif<<endl;
	return 0;
}