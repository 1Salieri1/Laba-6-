#ifndef _DECK_CPP
#define _DECK_CPP

#include<iostream>
#include<windows.h>
using namespace std;

namespace MyDeck {

	bool isEmpty(Work* head) {
		if (head) return false;
		else return true;
	}

	void Push_Back(Work*& head, Work*& last) {
		Work tmp;
		do {
			cout << "\n=========ADD ELEMENT======\n";
			cout << "Enter a worker name: ";
			cin >> tmp.name;
			cout << "Enter a pos: ";
			cin >> tmp.pos;
			cout << "Enter a year: ";
			cin >> tmp.year;
			cout << "Enter a month: ";
			cin >> tmp.month;
			tmp.next = NULL;
			tmp.prev = NULL;
			cout << "==========================\n";
			if ((tmp.year > 2023) || (tmp.year < 1940) || (tmp.month > 12) || (tmp.month < 1)) {
				cout << "\n---Fail! Enter correct data!\n";
			}
			else break;
		} while (true);

		if (isEmpty(head)) {
			head = new Work;
			*head = tmp;
			last = head;
			return;
		}

		
		last->prev = new Work;
		tmp.next = last;
		*(last->prev) = tmp;
		last = last->prev;
	}

	void Push_Front(Work*& head, Work*& last) {
		Work tmp;
		do {
			cout << "\n=========ADD ELEMENT======\n";
			cout << "Enter a worker name: ";
			cin >> tmp.name;
			cout << "Enter a pos: ";
			cin >> tmp.pos;
			cout << "Enter a year: ";
			cin >> tmp.year;
			cout << "Enter a month: ";
			cin >> tmp.month;
			tmp.next = NULL;
			tmp.prev = NULL;
			cout << "==========================\n";
			if ((tmp.year > 2023) || (tmp.year < 1940) || (tmp.month > 12) || (tmp.month < 1)) {
				cout << "\n---Fail! Enter correct data!\n";
			}
			else break;
		} while (true);

		if (isEmpty(head)) {
			head = new Work;
			*head = tmp;
			last = head;
			return;
		}

		head->next = new Work;
		tmp.prev = head;
		*(head->next) = tmp;
		head = head->next;
	}

	void Show_From_Head(Work* head) {
		if (isEmpty(head)) {
			cout << "\n\n---Deque is empty!";
			return;
		}
		cout << "\n\n===========DEQUE===========";
		Work* point;
		point = head;
		for (int pos = 0; point; point = point->prev, pos++) {
			cout << "\n\n#" << pos << "\n";
			cout << "Name: " << point->name << "\n";
			cout << "Pos:  " << point->pos << "\n";
			cout << "M.Y.: " << point->month << "." << point->year;
		}
		cout << "\n==========================\n";
	}

	void Show_From_Last(Work* head) {
		if (isEmpty(head)) {
			cout << "\n\n---Deque is empty!";
			return;
		}
		cout << "\n\n===========DEQUE===========";
		Work* point;
		point = head;
		for (int pos = 0; point; point = point->next, pos++) {
			cout << "\n\n#" << pos << "\n";
			cout << "Name: " << point->name << "\n";
			cout << "Pos:  " << point->pos << "\n";
			cout << "M.Y.: " << point->month << "." << point->year;
		}
		cout << "\n==========================\n";
	}

	void Show_Pos(Work* head, int pos) {
		if (isEmpty(head)) {
			cout << "\n\n---Deque is empty!";
			return;
		}
		cout << "\n\n==========ELEMENT===========";
		Work* point;
		point = head;

		for (int i = 0; point; i++) {
			if (i == pos) break;
			point = point->prev;
		}

		if (point) {
			cout << "\n\n#" << pos << "\n";
			cout << "Name: " << point->name << "\n";
			cout << "Pos:  " << point->pos << "\n";
			cout << "M.Y.: " << point->month << "." << point->year;
		}
		else {
			cout << "\n\n---No such pos!";
		}
		cout << "\n==========================\n";
	}

	void PopBack(Work*& head, Work*& last) {
		if (isEmpty(last)) {
			cout << "\n\n---Deque is empty!";
			return;
		}
		if (head == last) {
			free(head);
			head = NULL;
			last = NULL;
			cout << "\n---Poped";
			return;
		}

		Work* point;
		point = last;
		last = last->next;
		last->prev = NULL;
		free(point);
		cout << "\n---Poped";
		if (!last || !head) {
			last = NULL;
			head = NULL;
		}
	}

	void PopFront(Work*& head, Work*& last) {
		if (isEmpty(head)) {
			cout << "\n\n---Deque is empty!";
			return;
		}
		if (head == last) {
			free(head);
			head = NULL;
			last = NULL;
			cout << "\n---Poped";
			return;
		}

		Work* point;
		point = head;
		head = head->prev;
		head->next = NULL;
		free(point);
		cout << "\n---Poped";
		if (!last || !head) {
			last = NULL;
			head = NULL;
		}
	}

	void Del(Work*& head, Work*& last, int pos) { 
		if (isEmpty(head)) {
			cout << "\n\n---Deque is empty!";
			return;
		}
		if (pos < 0) {
			cout << "\n\n---Wrong pos!";
			return;
		}

		Work* point = NULL, * point_before = NULL, * point_after = NULL;
		if (pos == 0) { 
			PopFront(head, last);
			return;
		}

		
		int size = -1;
		for (point = head; point; point = point->prev) size++;

		if (pos == size) {
			PopBack(head, last);
			return;
		}

		
		point = head;

		for (int i = 0; point; i++) { 
			if (i == pos) break;
			if (i == pos - 1) point_after = point;
			point = point->prev;
		}
		if (!point) { 
			cout << "\n---Wrong pos!";
			return;
		}

		
		point_before = point->prev;
		free(point);

		
		if (point_after) point_before->next = point_after;
		else point_before->next = NULL;

		if (point_before) point_after->prev = point_before;
		else point_after->prev = NULL;

		cout << "\n---Deleted!";
	}

}

#endif