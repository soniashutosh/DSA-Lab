// Stack with array


#include<stdio.h>
#include<stdlib.h>

struct stack{
	int cap;
	int top;
	int *array;
};


void push(struct stack *);
int pop(struct stack *);
void show(struct stack *);

int main(){
	int choice,b=0;
	int capacity;
	struct stack *term;
	term=malloc(sizeof(struct stack));
	printf("Enter the size of the stack");
	scanf("%d",&capacity);
	term->cap=capacity;
	term->top=-1;
	term->array=malloc(capacity*sizeof(int));
	printf("MENU \n");
	printf("1.Performing Push operation \n");
	printf("2.Performing Pop operation \n");
	printf("3.Show the Element in the stack \n");
	printf("4.Exit \n");
	
	while(b==0){
		printf("Choose your operation \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				push(term);
			}break;
			case 2:{
				int poppeditem;
				poppeditem=pop(term);
				if(poppeditem)
					printf("Popped item is %d  \n",poppeditem);
			}break;
			case 3:{
				show(term);
			}break;
			case 4:{
				b++;
				printf("Welcome Again \n");
			}break;
			default:{
				printf("You had choosen the wrong choice.....plzz try again \n");
			}
		}
	}
	return 0;
}

void push(struct stack *term){
	if(term->top==term->cap-1){
		printf("Stack is Full...so No push operation will be performed \n");
	}
	else{
		int num;
		printf("Enter the term you want to push \n");
		scanf("%d",&num);
		term->array[++term->top]=num;
	}
}

int pop(struct stack *term){
	if(term->top==-1){
		printf("Your stack is Empty \n");
		return 0;
	}
	else{
		int item;
		item=term->array[term->top];
		term->top--;
		return item;	
	}
}

void show(struct stack *term){
	int total;
	total=term->top;
	printf("Your stack is \n");
	while(term->top+1){
		printf("%d      ",term->array[term->top]);
		term->top--;
	}
	printf("\n");
	term->top=total;
}
