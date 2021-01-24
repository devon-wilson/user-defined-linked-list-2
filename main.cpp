#include <iostream>
#include <cstring>
const int MAX_STR = 250;
struct nodeType
{
	char first[MAX_STR];
	char last[MAX_STR];
	char email[MAX_STR];
        nodeType *link;
};
int addList(nodeType* &head, nodeType* &tail);//nodeType* &previous);
void printList(nodeType* head);
void deleteList(nodeType* &head);
void deleteAll(nodeType* &head);
using namespace std;
int main()
{
	nodeType* tail = NULL;
	nodeType* head = NULL;
	//nodeType* previous = NULL;
	char choice;
	bool gameOn = true;
	do
        {
		cout <<"????? What do you want to do ?????" << endl;
		cout <<"1 add entry" << endl;
		cout <<"2 print all entries" << endl;
		cout <<"3 delete entry" << endl;
		cout <<"4 quit" << endl;
		cin >> choice;
		cin.ignore();
		switch(choice)
		{
			case '1':
				addList(head, tail);
				break;
			case '2':
				printList(head);
				break;
			case '3':
				deleteList(head);
				break;
			case '4':
				gameOn = false;
				break;
		}
        }while(gameOn == true);
	deleteAll(head);
	return 0;
}

void printList(nodeType* first)
{
        nodeType* print = first;
        while(print)
        {
                cout << " " << endl;
                cout << print->first << endl;
		cout << " " << endl;
		cout << print->last << endl;
		cout << " " << endl;
		cout << print->email << endl;	
                print = print -> link;
        }
}

int addList(nodeType* &head, nodeType* &tail) //nodeType* &previous)
{
	nodeType*  newNode = new nodeType;
	char tempFirst[MAX_STR];
	char tempLast[MAX_STR];
	char tempEmail[MAX_STR];
	cout << "First name: " << endl;	
	cin.getline(tempFirst, MAX_STR);
        strcpy(newNode->first, tempFirst);
	cout << "Last name: " << endl;
	cin.getline(tempLast, MAX_STR);
	strcpy(newNode->last, tempLast);
	cout << "Email: " << endl;
	cin.getline(tempEmail, MAX_STR);
	strcpy(newNode->email, tempEmail);
        newNode -> link= NULL;
        if(head == NULL)
        {
      		head = newNode;
		tail = newNode;
        }
        else
	{
		nodeType* previous = NULL;
                nodeType* current = head;
		while(current)
		{
			if(strcmp(current->last, newNode->last) > 0)
			{
				if(head == current)
				{
					newNode->link = current;
					head = newNode;
					return 0;
				}
				else
				{
					newNode->link = current;
					previous->link = newNode;
					return 0;
				}
			}
			previous = current;
			current = current->link;
		}
       	  	tail->link = newNode;
                newNode = tail;
	}
}

void deleteList(nodeType* &head)
{
	int counter = 0;
	if(!head)  
	{
		cout << "list is empty!" << endl;
	}
	char tempLast[MAX_STR];
	cout << "Enter last name to delete " << endl;
	cin.getline(tempLast, MAX_STR);
	nodeType* current = head;
	nodeType* previous = NULL;
	while(current)
	{
		if(strcmp(current->last, tempLast) == 0)
		{
			previous->link = current->link;
			delete current;
			return;
		} 
		previous = current;
		current = current -> link;
	}	
	cout << "Name not found! " << endl;
}

void deleteAll(nodeType* &head)
{
	nodeType* current = NULL;
	while(head)
	{	
		current = head;
		head = current -> link;
		delete current;
	}
}
