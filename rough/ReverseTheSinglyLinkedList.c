
#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int data;
	struct ListNode *tail;
};

void Travesing();
int counting();
void insert_in_beginning();
void reverse();
void swap(int *,int *);

struct ListNode *head=NULL,*end=NULL;

int main(){
	printf(" Menu \n");
	printf("1.Travesing in the List \n");
	printf("2.Count the  number of element in the Linked List \n");
	printf("3.Insertion of the element in the Beginning \n");
	printf("4.Reversing the Linked list \n");
	printf("5.Exit \n");

	int count=0,exit=0;
	do{
		printf("Choose Your choice \n");
		scanf("%d",&count);
		switch(count){
			case 1:{
				Travesing();
			}break;
			case 2:{
				int count;
				count=counting();
				printf("Linked List contained %d Elements",count);
			}break;
			case 3:{
				insert_in_beginning();
			}break;
			case 4:{
				reverse();
			}break;
			case 5:{
				exit++;
			}break;
			default:{
				printf("You have entered the wrong choice ....Try again \n");
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

int counting(){
	struct ListNode *start;
	start=head;
	int num=0;
	if(head==NULL){
		return 0;
	}
	else{
		while(start!=NULL){
			num++;
			start=start->tail;
		}
		return num;
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

void reverse(){
	struct ListNode *start;
	start=head;
	int pos,size;
	size=counting();
	while(size-1){
		pos=size;
		start=head;
		while(pos-1){
			swap(&(start->data),&(start->tail->data));
			start=start->tail;
			pos--;
		}
		size--;
	}
}

void swap(int *p,int *q){
	int c;
	c=*p;
	*p=*q;
	*q=c;
}