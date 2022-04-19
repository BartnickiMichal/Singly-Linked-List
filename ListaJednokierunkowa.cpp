// ListaJednokierunkowa.cpp : This file contains the 'main' function. Program execution heads and ends there.
//

#include <iostream>
using namespace std;
struct List
{
	int value;
	struct List* next;

};

List* addList(List* head, int value)
{
	List* current = new List;
	current = head;

	if (head == NULL)
	{
		head = new List;
		head->value = value;
		head->next = NULL;
		return head;
	}
	else 
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new List;
		current->next->value = value;
		current->next->next = NULL;
		return head;
	}
	

}


List* deleteList(List* head)
{
	List* current = new List;
	current = head;

	if (head->next == NULL)
	{	
		head = new List;
		head = NULL;
		return head;
	}
	else
	{
		
		while (current->next->next != NULL)
		{
			current = current->next;
		}
		delete(current->next);
		current->next = NULL;
		return head;
	}



}
void printList(List* head)
{
	List* current = head;
	while (current != 0)
	{
		cout << current->value << endl;
		current = current->next;
	}

}

int main()
{

	List* head;
	head = NULL;
	string what;
	int value;
	while (1)
	{
		cout << "Add or Delete?" << endl;
		cin >> what;

		if (what == "Add")
		{
			cout << "Write a value(must be integer)" << endl;
			cin >> value;
			head = addList(head, value);
			printList(head);
		}
		if (what == "Delete")
		{
			deleteList(head);
			printList(head);
			what = "";
		}
	}

	


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
