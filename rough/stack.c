#include<stdio.h>
#include<stdlib.h>

struct stack{
	int top;
	int capacity;
	int *array;
};

struct stack *term;

void createstack();
void pop();

int main(){
	printf("MENU \n");
	printf("1.Create stack \n");
	printf("5.Popped an item i=ont he stack \n");
	printf("8.Exit \n ");


	int choose,b=0;
	while(b==0){
		printf("Choose the option from the menu \n");
		scanf("%d",&choose);
		switch(choose){
			case 1:{
				createstack();
			}break;
			case 5:{
				pop();
			}break;
			case 8:{
				b++;
				printf("Your Process of exit is on the way....Welcome And visit it Again \n");
			}break;
			default:{
				printf("You have choosen the wrong choice ....try Again \n");
			}
		}
	}
	return 0;
}

void createstack(){
	term=malloc(sizeof(struct stack));
	int capacity;
	term->top=-1;
	printf("Enter the capacity of the stack \n");
	scanf("%d",&capacity);
	term->capacity=capacity;
	term->array=malloc(capacity*sizeof(int));
}