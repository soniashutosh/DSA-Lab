// Queue with array 


#include<stdio.h>
#include<stdlib.h>

struct queue{
	int bottom,top;
	int capacity;
	int *array;
};

void enqueue(struct queue *);
int dequeue(struct queue *);
void show(struct queue *);

int main(){
	 int choice,b=0;
	 int capacity;
	 struct queue *term;
	 term=malloc(sizeof(struct queue));
	 printf("Enter the size of stack you want \n");
	 scanf("%d",&capacity);
	 term->capacity=capacity;
	 term->top=-1;
	 term->bottom=-1;
	 term->array=malloc(capacity*sizeof(int));
	 printf("MENU \n");
	 printf("1.Performing enqueue operation \n");
	 printf("2.Performing dequeue operation \n");
	 printf("3.Printing the element of the Queue \n");
	 printf("4.Exit \n");
	 while(b==0){
	 	printf("Choose the option from the Menu \n");
	 	scanf("%d",&choice);
	 	switch(choice){
	 		case 1:{
	 			enqueue(term);
	 		}break;
	 		case 2:{
	 			int value;
	 			value=dequeue(term);
	 			if(term)
	 				printf("Item taken out is %d   \n",value);
	 		}break;
	 		case 3:{
	 			show(term);
	 		}break;
	 		case 4:{
	 			b++;
	 			printf("Welcome Again");
	 		}break;
	 		default :{
	 			printf("You had chosen the wrong choice....Plzz try again ..\n");
	 		}
	 	}
	 }
	 return 0;
}

void enqueue(struct queue *term){
	if(term->top==term->capacity-1){
		printf("For Further operation you have to increase the size of array \n");
	}
	else{
		int insert;
		printf("Enter the value you want to insert in the queue \n");
		scanf("%d",&insert);
		term->array[++term->top]=insert;
	}
}

int dequeue(struct queue *term){
	if(term->bottom==term->top){
		printf("Queue is Empty \n");
		return 0;
	}
	else{
		int pop;
		pop=term->array[++term->bottom];
		return pop;
	}
}

void show(struct queue *term){
	int value1=term->top;
	int value2=term->bottom;
	while(value1>value2){
		printf("%d     ",term->array[value1]);
		value1--;
	}
	printf("\n");
}
