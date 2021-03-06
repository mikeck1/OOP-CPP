// ConsoleApplication4.cpp : Defines the entry point for the console application.

#include "stdafx.h"


#include <iostream>
using namespace std;

struct nodee
{
	int data;				// datatype of node
	nodee *next;
};

class list
{
private:
	nodee * head, *tail;
public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	void createnode(int value)
	{
		nodee *temp = new nodee;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	void insert_start(int value)
	{
		nodee *temp = new nodee;
		temp->data = value;
		temp->next = head;
		head = temp;
	}
	void insert_position(int pos, int value)							// If position to large
	{																	// return error and continue
		nodee *pre = new nodee;
		nodee *cur = new nodee;
		nodee *temp = new nodee;
		cur = head;
		for (int i = 1; i<pos; i++)
		{
			pre = cur;
			if (cur == nullptr) {
				cout << "Error! location outside of list/n";
				return;
			}
			cur = cur->next;
		}
		temp->data = value;
		pre->next = temp;
		temp->next = cur;
	}
	void display()
	{
		nodee *temp = new nodee;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
};

int main()
{
	list mylist;
	for (int i = 1; i <= 100; i++)
	{
		mylist.createnode(i);
	}

	mylist.display();
	int myvar;
	int myloc;
	char UserChoice = 'y';
	while (UserChoice != 'n' || UserChoice != 'N')
	{
		
		switch (UserChoice) 
		{
		case 's':													// start displays prompt
			UserChoice = 'y';
			cout << "Enter a value to append to start\n";
			cin >> myvar;
			mylist.insert_start(myvar);
			cout << endl;
			mylist.display();
			cout << endl;
			break;

		case 'e':													// end displays prompt
			UserChoice = 'y';
			cout << "Enter a value to append to the end\n";
			cin >> myvar;
			mylist.createnode(myvar);
			cout << endl;
			mylist.display();
			cout << endl;
			break;

		case 'm':													// location search displays prompt
			UserChoice = 'y';
			cout << "Enter a location to append\n";
			cin >> myloc;
			cout << "Enter a value to append\n";
			cin >> myvar;
			mylist.insert_position(myloc, myvar);
			cout << endl;
			mylist.display();
			break;

		case 'n':
			return 0;
			break;

		default:													// default displays prompt
			cout << endl;
			cout << "enter a value\n";
			cout << "'s' appends to start and 'm' appends a value to a location and case 'e' goes to end\n";
			cout << "case 'n' ends the program\n";
			cin >> UserChoice;
			break;

		}
	}
	return 0;
}
