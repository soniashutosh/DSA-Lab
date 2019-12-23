// Linked List with advanced something

#include<stdio.h>
#include<stdlib.h>

struct list{
	int key;
	struct list *head,*tail;
};

struct list *start=NULL,*end=NULL,*start1=NULL,*end1=NULL;

void addition();
void show();
void duplicate();

int main(){
	int choose,b=0;
	printf("Elective menu is : \n");
	printf("1.Addition of the element to the linked list \n");
	printf("2.Show the element in the linked list \n");
	printf("3.Return the duplicte linked list with particular key value \n");
	printf("4.Exit  \n");
	while(b==0){
		printf("Choose the option from the menu \n");
		scanf("%d",&choose);
		switch(choose){
			case 1:{
				addition();
			}break;
			case 2:{
				show();
			}break;
			case 3:{
				duplicate();
			}break;
			case 4:{
				b++;
			}break;
			default :{
				printf("You have choosen wrong input ....plz select the valid input \n");
			}
		}
	}
	return 0;
}

void addition(){
	struct list *new,*exist;
	exist=start;
	int val;
	new=malloc(sizeof(struct list));
	printf("Enter the value you want to enter in the list : \n");
	scanf("%d",&val);
	new->key=val;
	new->head=NULL;
	new->tail=NULL;
	if(exist==NULL){
		start=new;
		new->head=start;
		end=new;
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
		printf("%d    ",new->key);
		new=new->tail;
	}
	printf("\n");
}

void duplicate(){
	struct list *new,*create;
	new=start;
	int mirror,flag=0;
	printf("Enter the key value for which you want to create the duplicte linked list \n");
	scanf("%d",&mirror);
	while(new!=NULL){
		if(new->key==mirror){
			flag++;
		}
		new=new->tail;
	}
	while(flag){
		create=start1;
		struct list *new2;
		new2=malloc(sizeof(struct list));
		new2->key=mirror;
		new2->head=NULL;
		new2->tail=NULL;
		if(create==NULL){
			start1=new2;
			end1=new2;
			new2->head=start1;
		}
		else{
			end1->tail=new2;
			new2->head=end1;
			end1=new2;
		}
		flag--;
	}
	struct list *new3;
	new3=start1;
	while(new3!=NULL){
		printf("%d   ",new3->key);
		new3=new3->tail;
	}
}