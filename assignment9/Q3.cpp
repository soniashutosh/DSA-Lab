#include<bits/stdc++.h>
using namespace std;

#define f(i,s,e) for(int i=s;i<e;++i)
#define fe(i,s,e) for(int i=s;i<=e;++i)
#define fie(i,s,e,d) for(int i=s;i<=e;i+=d)

typedef long long ll;
typedef unsigned long long ull;

int main(){
	int N;
	cout<<"Enter the number of Elements you wanna enter :  ";
	cin>>N;
	int A[N],sum=0,result;
	cout<<"Enter the Element in between 1 and "<<N+1<<" without repetition"<<endl;
	f(i,0,N){
		cin>>A[i];
		sum+=A[i];
	}
	result=(N+2)*(N+1)/2;
	result=result-sum;
	cout<<"The number missing is "<<result<<endl;
	return 0;
}