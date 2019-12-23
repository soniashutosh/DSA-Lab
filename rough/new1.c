#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T){
        int N;
        scanf("%d",&N);
        int A[N];
        for(int i=0;i<N;i++){
            scanf("%d",&A[i]);
        }
        int count=1;
        /*for(int i=0;i<N-1;i++){
            if(A[i+1]<=(2*A[i])){
                count++;
            }
            else{
                break;
            }
        }*/
        for(int i=0;i<N-2;i++){
            if(A[i+1]<=(2*A[i])){
                for(int j=i+1;j<N-1;j++){
                    for(int k=j+1;k<N;k++){
                        if(A[k]<=(2*A[j])){
                            count++;
                            printf("%d %d %d",A[i],A[j],A[k]);
                        }
                    }
                }
            }
        }
        printf("%d \n",count);
        T--;
    }
    
}