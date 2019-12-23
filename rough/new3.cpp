#include<iostream>
using namespace std;

void quicksort(long int *,long int,long int );

int main(){
    int t;
    cin>>t;
    while(t){
        long int N;
        cin>>N;
        long int A[N];
        for(long int i=0;i<N;i++){
            cin>>A[i];
        }
        quicksort(A,0,N-1);
        int sum=0;
        for(long int i=1;i<N-1;i++){
            sum=sum+A[i];
        }
        cout<<sum;
    }
    return 0;
}

void quicksort(long int A[],long int s,long int e){
    long int fix=A[s];
    long int start=s;
    long int end2=e;
    if(s<e){
        while(s<e){
            while(fix<A[e]){
                e--;
            }
            if(fix>A[e]){
                long int t=A[e];
                A[e]=A[s];
                A[s]=t;
                s++;
            }
            while(A[s]<fix){
                s++;
            }
            if(A[s]>fix){
                long int t=A[s];
                A[s]=A[e];
                A[e]=t;
                e--;
            }
        }
        long int end1=s-1;
        quicksort(A,start,end1);
        quicksort(A,end1,end2);
    }
}

