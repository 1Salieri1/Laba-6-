#include<iostream>
#include<windows.h>
using namespace std;

typedef struct WORK {
	string name;
	string pos;
	int year;
	int month;
	struct WORK *next;
	struct WORK *prev;
} Work;

#include"stack.cpp"
#include"query.cpp"
#include"deck.cpp"

Work *stack_menu(Work *head) {
	int choose;
	while(1) {
		system("cls");
		cout<<"Stack menu:\n1 - Add\n2 - Pop\n3 - Show all\n4 - Show element from pos\n5 - Delete element from pos\n0 - Back\n\n>> ";
		cin>>choose;
		cin.get();
		
		switch(choose) {
			case 1:
				head = MyStack::push(head);
				break;
			case 2:
				head = MyStack::pop(head);
				cin.get();
				break;
			case 3:
				MyStack::Show(head);
				cin.get();
				break;
			case 4:
				cout<<"\nPos >> "; cin>>choose;
				MyStack::Show(head, choose);
				cin.get(); cin.get();
				break;
			case 5:
				cout<<"\nPos >> "; cin>>choose;
				head = MyStack::Del(head, choose);
				cin.get(); cin.get();
				break;
			case 0:
				return head;
				break;
			default:
				cout<<"\n---Wrong input!";
				cin.get();
				break;
		}
	}
	return head;
}

Work *query_menu(Work *head){
	int choose;
	while(1) {
		system("cls");
		cout<<"Query menu:\n1 - Add\n2 - Pop\n3 - Show all\n4 - Show element from pos\n5 - Delete element from pos\n0 - Back\n\n>> ";
		cin>>choose;
		cin.get();
		
		switch(choose) {
			case 1:
				head = MyQuery::Add(head);
				break;
			case 2:
				head = MyQuery::Pop(head);
				cin.get();
				break;
			case 3:
				MyQuery::Show(head);
				cin.get();
				break;
			case 4:
				cout<<"\nPos >> "; cin>>choose;
				MyQuery::Show(head, choose);
				cin.get(); cin.get();
				break;
			case 5:
				cout<<"\nPos >> "; cin>>choose;
				head = MyQuery::Del(head, choose);
				cin.get(); cin.get();
				break;
			case 0:
				return head;
				break;
			default:
				cout<<"\n---Wrong input!";
				cin.get();
				break;
		}
	}
	return head;
}

void deque_menu(Work *&head, Work *&last){
	int choose;
	while(1) {
		system("cls");
		cout<<"Deque menu:\n1 - Push Back\n2 - Push Front\n3 - Show all from head to last\n4 - Show all from last to head\n5 - Show element from pos(head = 0)\n6 - Delete element from pos(head = 0)\n7 - Pop Back\n8 - Pop Front\n0 - Back\n\n>> ";
		cin>>choose;
		cin.get();
		
		switch(choose) {
			case 1:
				MyDeck::Push_Back(head, last);
				break;
			case 2:
				MyDeck::Push_Front(head, last);
				cin.get();
				break;
			case 3:
				MyDeck::Show_From_Head(head);
				cin.get();
				break;
			case 4:
				MyDeck::Show_From_Last(last);
				cin.get();
				break;
			case 5:
				cout<<"\nPos >> "; cin>>choose;
				MyDeck::Show_Pos(head, choose);
				cin.get(); cin.get();
				break;
			case 6:
				cout<<"\nPos >> "; cin>>choose;
				MyDeck::Del(head, last, choose);
				cin.get(); cin.get();
				break;
			case 7:
				MyDeck::PopBack(head,last);
				cin.get();
				break;
			case 8:
				MyDeck::PopFront(head,last);
				cin.get();
				break;
			case 0:
				return;
				break;
			default:
				cout<<"\n---Wrong input!";
				cin.get();
				break;
		}
	}
}

int main() {
	Work *shead = NULL;
	Work *qhead = NULL;
	Work *dhead = NULL, *dlast = NULL;
	int choose;
	bool mainmenu = true;

	while(mainmenu) {
		bool smenu = true;
		bool qmenu = true;
		bool dmenu = true;

		cout<<"Choose mode:\n1 - Stack\n2 - Query\n3 - Deque\n0 - Exit\n\n>> ";
		cin>>choose;
		cin.get();
		switch(choose) {
			case 1:
				shead = stack_menu(shead);
				break;
			case 2:
				qhead = query_menu(qhead);
				break;
			case 3:
				deque_menu(dhead, dlast);
				break;
			case 0:
				cout<<"\n---Exiting...";
				cin.get();
				mainmenu = false;
				break;
			default:
				cout<<"\n---Wrong input!";
				cin.get();
				break;
		}
		system("cls");
	}
	return 0;
}
