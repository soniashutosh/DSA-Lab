#include<bits/stdc++.h>
using namespace std;

#define prime 100003
#define total 100000
#define hashing(num) (num%prime)%total

struct phonebook{
	int number;
	char name[15];
};

struct phonebook BOOK[total];

void start(){
	for(int i=0;i<total;i++){
		BOOK[i].number=0;
		//char stri[15]="notfound";
		//BOOK[i].name=stri;
	}
}

int hashit(int number){
	  int hashed=hashing(number);
	  cout<<hashed;
	  return hashed;
}

void adduser(struct phonebook add){
	int num;
	num=hashit(add.number);
	if(BOOK[num].number==add.number){
		cout<<"USER ALREADY EXIST"<<endl;
	}
	BOOK[num]=add;
}

void erase(int number){
	int num=hashit(number);
	if(BOOK[num].number==0){
		cout<<"No User found"<<endl;
	}
	else{
		//BOOK[num].name={'n','o','t','f','o','u','n','d'};
		BOOK[num].number=0;
	}
}

void find(int number){
	int num=hashit(number);
	cout<<BOOK[num].number<<endl;
	if(BOOK[num].number){
		cout<<BOOK[num].name<<endl;
	}
	else{
		cout<<"User doesnot Exist"<<endl;
	}
}

int main(){
	int choose,no_of_queries;
	cout<<"Enter the number of queries you have"<<endl;
	cin>>no_of_queries;
	start();
	while(no_of_queries){
		choose=0;
		cout<<"Choose the following operation which you wanna perform"<<endl;
		cout<<"1.ADD USER "<<endl;
		cout<<"2.DELETE USER "<<endl;
		cout<<"3.FIND USER "<<endl;
		cout<<"4.FORCE COME OUT "<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choose;
		switch(choose){
			case 1:{
				struct phonebook add;
				cout<<"Enter the mobile number of the uset"<<endl;
				cin>>add.number;
				if(add.number>10000000){
					cout<<"Incorrect Mobile Number"<<endl;
					break;
				}
				cout<<"Enter the name of the user without space"<<endl;
				cin>>add.name;
				adduser(add);
			}break;
			case 2:{
				int number;
				cout<<"Enter the number of User you want to delete"<<endl;
				cin>>number;
				erase(number);
			}break;
			case 3:{
				int number;
				cout<<"Enter the number of User you want to search"<<endl;
				cin>>number;
				find(number);
			}break;
			case 4:{
				no_of_queries=0;
			}break;
			default:{
				cout<<"Choosen wrong choice.... Plzz try again later"<<endl;
			}
		}
		no_of_queries--;
	}
	if(!no_of_queries){
		cout<<"Your Queries had been completed or you want to exit.. I think soo  "<<endl;
	}
	cout<<"WELCOME AGAIN"<<endl;
	return 0;
}
