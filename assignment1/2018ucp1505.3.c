// Doubly Linked List implementation


#include<stdio.h>
#include<stdlib.h>

struct list {
	int key;
	struct list *head,*tail;
};

struct list *start=NULL,*end=NULL;

void addition();
void show();
void reversing();

int main(){
	int choose,b=0;
	printf("Elective menu \n");
	printf("1.addition of element \n");
	printf("2.Show the list \n");
	printf("3.Reversing the linked list \n");
	printf("4.Exit \n");
	while(b==0){
		printf("Select the option \n");
		scanf("%d",&choose);
		switch(choose){
			case 1:{
				addition();
			}break;
			case 2:{
				show();
			}break;
			case 3:{
				reversing();
			}break;
			case 4:{
				b++;
			}break;
			default:{
				printf("You choose invalid option....please try again \n");
			}
		}
	}
	return 0;
}

void addition(){
	struct list *new,*exist;
	int val;
	printf("Eneter the number you want to add \n");
	scanf("%d",&val);
	new=malloc(sizeof(struct list));
	new->head=NULL;
	new->tail=NULL;
	new->key=val;
	exist=start;
	if(exist==NULL){
		start=new;
		end=new;
		new->head=start;
	}
	else{
		end->tail=new;
		new->head=end;
		end=new;
	}
}

void show(){
	struct list *new;
	new=start;
	while(new!=NULL){
		printf("%d      ",new->key);
		new=new->tail;
	}
	printf("\n");
}

void reversing(){
	struct  list *new;
	new=end;
	while(new!=start){
		printf("%d     ",new->key);
		new=new->head;
	}
	printf("%d  \n",new->key);
}