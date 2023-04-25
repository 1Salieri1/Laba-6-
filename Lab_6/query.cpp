#ifndef _QUERY_CPP
#define _QUERY_CPP

#include<iostream>
#include<windows.h>
using namespace std;

namespace MyQuery {

	bool isEmpty(Work *head) {
		if(head) return false;
		else return true;
	}

	Work *Add(Work *head) { 
		Work tmp;
		do {
			cout<<"\n=========ADD ELEMENT======\n";
			cout<<"Enter a worker name: ";
			cin>>tmp.name;
			cout<<"Enter a pos: ";
			cin>>tmp.pos;
			cout<<"Enter a year: ";
			cin>>tmp.year;
			cout<<"Enter a month: ";
			cin>>tmp.month;
			tmp.next = NULL;
			cout<<"==========================\n";
			if( (tmp.year > 2023) || (tmp.year < 1940) || (tmp.month > 12) || (tmp.month < 1) ) {
				cout<<"\n---Fail! Enter correct data!\n";
			} else break;
		} while(true);

		if(isEmpty(head)) { 
			head = new Work;
			*head = tmp;
			return head;
		}

		
		Work *point;
		point = head;
		for(; point->next; point=point->next) {} 
		point->next = new Work;
		*(point->next) = tmp;
		return head;
	}

	Work *Pop(Work *head) { 
		if(isEmpty(head)) { 
			cout<<"\n---Query is empty!";
			return head;
		}
		Work *point;
		point = head;
		head = head->next;
		free(point);
		cout<<"\n---Done";
		return head;
	}

	void Show(Work *head) {
		if(isEmpty(head)) {
			cout << "\n\n---Query is empty!";
			return;
		}
		cout<<"\n\n===========QUERY===========";
		Work *point;
		point = head;
		for(int pos = 0; point; point = point->next, pos++) {
			cout<<"\n\n#"<<pos<<"\n";
			cout<<"Name: "<<point->name<<"\n";
			cout<<"Pos:  "<<point->pos<<"\n";
			cout<<"M.Y.: "<<point->month<<"."<<point->year;
		}
		cout<<"\n==========================\n";
	}

	void Show(Work *head, int pos) {
		if(isEmpty(head)) {
			cout << "\n\n---Query is empty!";
			return;
		}
		cout<<"\n\n==========ELEMENT===========";
		Work *point;
		point = head;

		for(int i = 0; point; i++) {
			if(i==pos) break;
			point = point->next;
		}

		if(point) {
			cout<<"\n\n#"<<pos<<"\n";
			cout<<"Name: "<<point->name<<"\n";
			cout<<"Pos:  "<<point->pos<<"\n";
			cout<<"M.Y.: "<<point->month<<"."<<point->year;
		} else {
			cout<<"\n\n---No such pos!";
		}
		cout<<"\n==========================\n";
	}

	Work *Del(Work *head, int pos) {
		if(isEmpty(head)) {
			cout << "\n\n---Query is empty!";
			return head;
		}
		if(pos < 0) {
			cout << "\n\n---Wrong pos!";
			return head;
		}

		Work *point=NULL, *point_before=NULL, *point_after=NULL;
		if(pos==0) {
			point = head;
			head = head->next;
			free(point);
			return head;
		}

		point = head;

		for(int i = 0; point; i++) {
			if(i==pos) break;
			if(i==pos-1) point_before = point;
			point = point->next;
		}
		if(!point) {
			cout<<"\n---Wrong pos!";
			return head;
		}

		
		point_after = point->next;
		free(point);
		point_before->next = point_after;
		cout<<"\n---Deleted!";
		return head;
	}

}

#endif