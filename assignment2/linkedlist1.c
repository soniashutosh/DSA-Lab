// Traversing in the singly Linked List

#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int data;
	struct ListNode *tail;
};

void Travesing();
void counting();
void insert_in_beginning();
void insert_in_ending();
void insert_at_given_position();
void deleting_the_first_node();
void deleting_the_last_node();
void deleting_the_linked_list();

struct ListNode *head=NULL,*end=NULL;

int main(){
	printf(" Menu \n");
	printf("1.Travesing in the List \n");
	printf("2.Count the  number of element in the Linked List \n");
	printf("3.Insertion of the element in the Beginning \n");
	printf("4.Inertion of the element in the Ending \n");
	printf("5.Inserting a Node in a singly Linked list in the at the given Position \n");
	printf("6.Deleting the First Node in the Linked List \n");
	printf("7.Deleting the last Node in the Linked List \n");
	printf("8.Deleting the linked List \n");
	printf("9.Exit \n");
	int count=0,exit=0;
	do{
		printf("Choose Your choice \n");
		scanf("%d",&count);
		switch(count){
			case 1:{
				Travesing();
			}break;
			case 2:{
				counting();
			}break;
			case 3:{
				insert_in_beginning();
			}break;
			case 4:{
				insert_in_ending();
			}break;
			case 5:{
				insert_at_given_position();
			}break;
			case 6:{
				deleting_the_first_node();
			}break;
			case 7:{
				deleting_the_last_node();
			}break;
			case 8:{
				deleting_the_linked_list();
			}break;
			case 9:{
				exit++;
				printf(" Exit process is on the way....Welcome Again       ");
			}break;
			default :{
				printf("Invalid Input .....Plz choose again \n");
			}
		}
	}while(exit==0);
	return 0;
}

void Travesing(){
	struct ListNode *start;
	start=head;
	if(head==NULL){
		printf("List is Empty \n");
	}
	else{
		for(;start!=NULL;start=start->tail){
			printf("%d    ",start->data);
		}
	}
}

void counting(){
	struct ListNode *start;
	start=head;
	int num=0;
	if(head==NULL){
		printf("List is Empty \n");
	}
	else{
		while(start!=NULL){
			num++;
			start=start->tail;
		}
		printf("List contained %d Elements \n",num);
	}
}

void insert_in_beginning(){
	struct ListNode *start,*new;
	int value;
	start=head;
	new=malloc(sizeof(struct ListNode));
	printf("Enter the data you want to enter \n");
	scanf("%d",&value);
	new->data=value;
	new->tail=NULL;
	if(start==NULL){
		head=new;
		end=new;
	}
	else{
		new->tail=head;
		head=new;
	}
}

void insert_in_ending(){
	struct ListNode *start,*new;
	int value;
	start=head;
	new=malloc(sizeof(struct ListNode));
	printf("ENter the data you want to enter \n");
	scanf("%d",&value);
	new->tail=NULL;
	new->data=value;
	if(start==NULL){
		head=new;
		end=new;
	}
	else{
		end->tail=new;
		end=new;
	}
}

void insert_at_given_position(){
	struct ListNode *start,*new;
	int value,position;
	start=head;
	new=malloc(sizeof(struct ListNode));
	new->tail=NULL;
	printf("Enter the position where you want to insert the element \n");
	scanf("%d",&position);
	printf("Enter the value you want to insert \n");
	scanf("%d",&value);
	new->data=value;
	if(head==NULL){
		head=new;
		end=new;
	}
	else{
		while(position-2){
			start=start->tail;
			position--;
		}
		new->tail=start->tail;
		start->tail=new;
	}
}

void deleting_the_first_node(){
	struct ListNode *start;
	if(head==NULL){
		printf("List is Empty \n");
	}
	else{
		start=head;
		head=start->tail;
	}

}

void deleting_the_last_node(){
	struct ListNode *start,*temp=NULL;
	start=head;
	if(start==NULL){
		printf("List is Empty \n");
	}
	else{
		int num=0;
		while(start!=NULL){
			num++;
			start=start->tail;
		}
		start=head;
		while(num-2){
			start=start->tail;
			num--;
		}
		start->tail=temp;
		end=start;
	}
}

void deleting_the_linked_list(){
	struct ListNode *start,*temp;
	start=head;
	while(start){
		temp=start->tail;
		free(start);
		start=temp;
	}
	head=NULL;
}