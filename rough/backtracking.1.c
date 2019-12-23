//Finding all binary numbers in the given range 



#include<stdio.h>
#include<string.h>

char A[10];

void binary(int);

int main(){
	binary(9);
	return 0;
}

void binary(int n){
	if(n<1){
		printf("%s \n",A);
	}
	else{
		A[n-1]='0';
		binary(n-1);
		A[n-1]='1';
		binary(n-1);
	}
}