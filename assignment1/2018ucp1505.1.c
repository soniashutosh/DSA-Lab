//Implementation of Quick sort

#include<stdio.h>
void quicksort(int *,int,int);
int main(){
    int N;
    printf("Enter the number of elements you want in the array:");
    scanf("%d",&N);
    int A[11];
    printf("Enter your array    :    ");
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    quicksort(A,0,N-1);
    printf("Array after sorting is: \n");
    for(int i=0;i<N;i++){
        printf("%d    ",A[i]);
    }
    return 0;
}

void quicksort(int A[],int s,int e){
    int fix=A[s];
    int start=s;
    int end2=e;
    if(s<e){
        while(s<e){
            while(fix<A[e]){
                e--;
            }
            if(fix>A[e]){
                int t=A[e];
                A[e]=A[s];
                A[s]=t;
                s++;
            }
            while(A[s]<fix){
                s++;
            }
            if(A[s]>fix){
                int t=A[s];
                A[s]=A[e];
                A[e]=t;
                    e--;
            }
        }
        int end1=s-1;
        quicksort(A,start,end1);
        quicksort(A,end1+2,end2);
    }
}








