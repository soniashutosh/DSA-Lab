#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int data;
	struct ListNode *front,*back;
};

struct ListNode *head=NULL,*end=NULL;

void insert_node_in_beginning();
void insert_node_in_end();
void insert_node_in_position();
void delete_node_in_beginning();
void delete_node_in_end();
void delete_intermediate_node();
void delete_the_linked_list();
void excess();

int main(){
	int choice,exit=0;
	printf("MENU \n");
	printf("1.Inserting a node in the Linked List in the beginning \n");
	printf("2.Inserting a node in the Linked List in the Ending \n");
	printf("3.Inserting a node in the Linked List in the Given Postiion \n");
	printf("4.Deleting a node in the Linked List in the beginning \n");
	printf("5.Deleting last node of the Linked List \n");
	printf("6.Deleting the intermediate node in the Linked List \n");
	printf("7.Deleting the doubly Linked List \n");
	printf("8.Excessing Element in the Linked List \n");
	printf("9.Exit ");
	while(exit==0){
		printf("Select the option from the Menu \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				insert_node_in_beginning();
			}break;
			case 2:{
				insert_node_in_end();
			}break;
			case 3:{
				insert_node_in_position();
			}break;
			case 4:{
				delete_node_in_beginning();
			}break;
			case 5:{
				delete_node_in_end();
			}break;
			case 6:{
				delete_intermediate_node();
			}break;
			case 7:{
				delete_the_linked_list();
			}break;
			case 8:{
				excess();
			};break;
			case 9:{
				exit++;
				printf("You are on the way of Quiting the process \n");
			}break;
			default :{
				printf("You have Selected the wrong choice \n");
			}
		}
	}
}

void insert_node_in_beginning(){
	struct ListNode *start,*new;
	int value;
	start=head;
	new=malloc(sizeof(struct ListNode));
	new->front=NULL;
	new->back=NULL;
	printf("Enter the number you want to insert in the beginning \n");
	scanf("%d",&value);
	new->data=value;
	if(start==NULL){
		head=new;
		end=new;
		new->front=head;
	}
	else{
		new->back=head;
		head=new;
		new->front=head;
	}

}

void insert_node_in_end(){
	struct ListNode *start,*new;
	int value;
	start=head;
	new=malloc(sizeof(struct ListNode));
	new->front=NULL;
	new->back=NULL;
	printf("Enter the number you want to insert in the beginning \n");
	scanf("%d",&value);
	new->data=value;
	if(start==NULL){
		head=new;
		end=new;
		new->front=head;
	}
	else{
		while(start->back!=NULL){
			start=start->back;
		}
		end=new;
		new->front=start;
		start->back=new;

	}
}

// Please insert valid Position...otherwise it is going to give you fault

void insert_node_in_position(){
	struct ListNode *start,*new;
	int value,position;
	start=head;
	new=malloc(sizeof(struct ListNode));
	new->front=NULL;
	new->back=NULL;
	printf("Enter the valid position where you want to enter \n");
	scanf("%d",&position);
	printf("Enter the number you want to insert in the beginning \n");
	scanf("%d",&value);
	new->data=value;
	if(start==NULL){
		head=new;
		end=new;
		new->front=head;
	}
	else{
		while(position-2){
			start=start->back;
			position--;
		}
		new->back=start->back;
		start->back=new;
		new->front=start;
	}

}

void delete_node_in_beginning(){
	struct ListNode *start;
	start=head;
	if(start==NULL){
		printf("This Doubly Linked List is Empty \n");
	}
	else{
		head=start->back;
		free(start);
	}
}

void delete_node_in_end(){
	struct ListNode *start,*temp;
	int total=0;
	start=head;
	if(start==NULL){
		printf("This Doubly Linked List is Empty \n");
	}
	else{
		while(start!=NULL){
			start=start->back;
			total++;
		}
		start=head;
		while(total-2){
			start=start->back;
			total--;
		}
		start->back=NULL;
		end=start;
		free(start->back);
	}
}

// Enter valid Position ...if u are not going to give valid position you may have to go with sgmentation fault

void delete_intermediate_node(){
	struct ListNode *start,*temp,*temp2;
	int position,po2;
	start=head;
	temp=head;
	printf("Enter the position form where you want to delete the node \n");
	scanf("%d",&position);
	po2=position;
	if(start==NULL){
		printf("This Doubly Linked List is Empty \n");
	}
	else{
		while(position-2){
			start=start->back;
			position--;
		}
		while(po2-1){
			temp=temp->back;
			po2--;
		}
		start->back=temp->back;
		temp=temp->back;
		temp->front=start;
		free(temp);
	}
}

void delete_the_linked_list(){
	struct ListNode *start,*new;
	start=head;
	while(start){
		new=start->back;
		free(start);
		start=new;
	}
	head=NULL;
}

void excess(){
	struct ListNode *start;
	start=head;
	if(head==NULL){
		printf("Doubly Linked List is Empty \n");
	}
	else{
		while(start!=NULL){
			printf("%d     ",start->data);
			start=start->back;
		}
	}
}