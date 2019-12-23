// Printing all the permutations of the string

#include<stdio.h>
#include<string.h>

void permutation(char *,int ,int);
void swap(char *,char *);

int main(){
	char A[100];
	printf("Enter your string whose permutation you want \n");
	scanf("%s",A);
	int len=strlen(A);
	permutation(A,0,len-1);
	return 0;
}

void permutation(char *s,int i,int n){
	static int count;
	int j;
	if(i==n){
		count++;
		printf("(%d) %s \n",count,s);
	}
	else{
		for(int j=i;j<=n;j++){
			swap((s+i),(s+j));
			permutation(s,i+1,n);
			swap((s+j),(s+i));    // Backtracking
		}
	}
}

void swap(char *x,char *y){
	char ch;
	ch=*x;
	*x=*y;
	*y=ch;
}