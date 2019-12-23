// Linked lIst implementation

#include<stdio.h>
#include<stdlib.h>

struct list{
    int key;
    struct list *tail;
}*start = NULL, *end = NULL;

void Addition();
void show();
void Search(int );
void delete();

int main(){
    int choose, b=0;
    printf("MENU \n");
    printf("1.Adding element in the tail \n");
    printf("2.Searching for an element \n");
    printf("3.Deleting the element with particular key \n");
    printf("4.Show the element in the list \n");
    printf("5.Exit \n");
    while(b==0){
        printf("Select option from the menu :");
        scanf("%d",&choose);
        switch(choose){
            case 1:{
                Addition();
            }break;
            case 2:{
                int num;
                printf("Enter the number you want to search \n");
                scanf("%d",&num);
                Search(num);
            }break;
            case 3:{
                delete();
            }
            case 4:{
                show();
            }break;
            case 5:{
                b++;
            }break;
            default :{
                printf("Not in the list...Try again \n");
            }
        }
    }
    return 0;
}

void Addition(){
    struct list *p,*new;
    new=start;
    int val;
    p=malloc(sizeof(struct list));
    printf("Enter the value you want to insert \n");
    scanf("%d",&val);
    p->key=val;
    p->tail=NULL;
    if(new==NULL){
        start=p;
        end=p;
    }
    else{
        end -> tail = p;
        end = p;
    }
}

void Search(int find){
    struct list *new;
    new=start;
    int option=0;
    while(new != NULL){
        if(new->key==find){
            option++;
            break;
        }
        new = new -> tail;
    }
    if(option!=0){
        printf("Element present \n");
    }
    else{
        printf("Element absent \n ");
    }
}

void delete(){
    struct list *new, *p;
    new=start;
    int option=0,erase;
    printf("Enter the element you want to delete \n");
    scanf("%d",&erase);
    while(new!=NULL){
        if(new->key==erase){
            option++;
            p = new;
            break;
        }
        new = new -> tail;
    }
    option-=1;
    new = start;
    while(new != p){
        if(new -> tail == p){
            new->tail=p->tail;
            break;
        }
        new = new -> tail;
    }
    
}

void show(){
    struct list *new;
    new=start;
    while(new!=NULL){
        printf("%d   ",new->key);
        new=new->tail;
    }
}
