#include <cstddef>
#include <stdexcept>
#include <iostream>
#ifndef CyclicLinkedList_H
#define CyclicLinkedList_H
#include "SingleNode.h"

template <typename Type>
class CyclicLinkedList
{
	private:
		SingleNode<Type> *head; //pointer that points to the first node of the linked list
		SingleNode<Type> *tail;	//pointer that points to the last node of the linked list, tail points to NULL
		int sizeL;	//integer that counts the number of nodes that hold an element
		
	public:
		CyclicLinkedList(); //class constructor
		~CyclicLinkedList(); //Class destructor, deletes all of the nodes starting from the front when the list goes out of scope
		bool empty() const; //Checks to see if the linked list is empty and returns true if so
		void push_front(Type const &dInput); //Creates a new node that points to the old head and becomes the new head
		void push_back(Type const &dInput);	//Creates a new node that points to the old tail and becomes the new tail
		Type pop_back(); //Deletes the old tail and assigns the one before as the new tail, returns the data in the old tail
		Type pop_front(); //Deletes the old head and assigns the old head's next pointer as the new head, returns the data in the old head
		int size() const; //Function that returns the number of items in the list
		Type front() const; //retrives and returns the data stored in the head node pointer
		Type back() const; //retrives and returns the data stored in the tail node pointer
		SingleNode<Type> *head_f() const; //returns the head pointer
		SingleNode<Type> *tail_f() const; //returns the tail pointer
		int count(Type const &cInput) const; //function that counts the amount of times the argument shows up in all of the nodes
		int erase(Type const &eInput); //Deletes all of the nodes with data members equal to the arugment, starts from the front and returns the number of items deleted
		void printList() const; //print function, outputs all of the data in each node
		
};

//Class constructor that initalizes the head and tail pointers to null and sizeL to zero
template <typename Type>
CyclicLinkedList<Type>::CyclicLinkedList()
{
	head = tail = NULL;
	sizeL = 0;
}

//Class destructor, deletes all of the nodes starting from the front when the list goes out of scope
template <typename Type>
CyclicLinkedList<Type>::~CyclicLinkedList()
{
	while(head != NULL)
	{
		pop_front();
	}
}

//retrives and returns the data stored in the head node pointer
template <typename Type>
Type CyclicLinkedList<Type>::front() const
{
		return head->getData();
}

//retrives and returns the data stored in the tail node pointer
template <typename Type>
Type CyclicLinkedList<Type>::back() const
{
		return tail->getData();
}

//Function that returns the number of items in the list
template <typename Type>
int CyclicLinkedList<Type>::size() const
{
	return sizeL;
}

//Checks to see if the linked list is empty and returns true if so
template <typename Type>
bool CyclicLinkedList<Type>::empty() const
{
	return (head == NULL);
}

//Creates a new node that points to the old head and becomes the new head
template <typename Type>
void CyclicLinkedList<Type>::push_front(Type const &dInput)
{
	SingleNode<Type> *t = new SingleNode<Type>(dInput, head);
	
	if((head == NULL) && (tail == NULL))
	{
		head = tail = t;
	}
	else
	{
		head = t;
	}
	
	sizeL++;
}

//Creates a new node that the old tail points and becomes the new tail
template <typename Type>
void CyclicLinkedList<Type>::push_back(Type const &dInput)
{
	SingleNode<Type> *t = new SingleNode<Type>(dInput, NULL);
	
	if((head == NULL) && (tail == NULL))
	{
		head = tail = t;
	}
	else
	{
		tail->next = t;
		tail = t;
		tail->next = NULL;
	}
	
	sizeL++;
}

//Deletes the old head and assigns the old head's next pointer as the new head, returns the data in the old head
template <typename Type>
Type CyclicLinkedList<Type>::pop_front()
{
		Type temp_ele = head->getData();
		SingleNode<Type> *temp_head = head;
		head = temp_head->getNext();
		sizeL--;
		
		delete temp_head;
		
		if(sizeL == 0)
		{
			head = NULL;
		}
		
		return temp_ele;
}

//Deletes the old tail and assigns the one before as the new tail, returns the data in the old tail
template <typename Type>
Type CyclicLinkedList<Type>::pop_back()
{
		Type temp_e = tail->getData();
		SingleNode<Type> *temp_h = head;
		SingleNode<Type> *prev = temp_h;
		
		while((temp_h->getNext()) != NULL)
		{
			prev = temp_h;
			temp_h = temp_h->getNext();
		}
		
		tail = prev;
		tail->next = NULL;
		sizeL--;
		
		delete temp_h;
		
		if(sizeL == 0)
		{
			head = NULL;
		}
		
		return temp_e;
}

//returns the head pointer
template <typename Type>
SingleNode<Type> *CyclicLinkedList<Type>::head_f() const
{
	return head;
}

//returns the tail pointer
template <typename Type>
SingleNode<Type> *CyclicLinkedList<Type>::tail_f() const
{
	return tail;
}

//function that counts the amount of times the argument shows up in all of the nodes
template <typename Type>
int CyclicLinkedList<Type>::count(Type const &cInput) const
{
	int count_temp = 0;
	SingleNode<Type> *temp_d = head;
	
	while(temp_d!=NULL)
	{
		if(cInput == (temp_d->getData()))
		{
			count_temp++;
		}
		temp_d = temp_d->getNext();
	}
	
	return count_temp;
}

//Erases all of the nodes that hold the data taken as an argument 
template <typename Type>
int CyclicLinkedList<Type>::erase(Type const &eInput)
{
	int counter = 0;
	SingleNode<Type> *temp_t = head;
	SingleNode<Type> *hold;
	SingleNode<Type> *pre = NULL;
	
	while(temp_t!=NULL)
	{
		if((temp_t->getData() == eInput) && (pre!=NULL) && (temp_t->getNext() != NULL))
		{
			pre->next = temp_t->getNext();
			delete temp_t;						//Reassigns nodes that arent the head or tail
			temp_t = pre->getNext();
			counter++;
			sizeL--;
		}
		else if((temp_t->getData() == eInput) && (pre == NULL) && (temp_t->getNext() != NULL))
		{
			hold = head;
			temp_t = head->getNext();
			delete hold;					//Reassigns nodes that are the head
			head = temp_t;
			counter++;
			sizeL--;
		}
		else if((temp_t->getData() == eInput) && (temp_t->getNext() == NULL) && (pre != NULL))
		{
			pre->next = NULL;			//Reassigns nodes that are the tail
			delete temp_t;
			tail = pre;
			counter++;
			sizeL--;
			break;
		}
		else
		{
			pre = temp_t;			//if the node's data doesnt equal the argument, move on to the next
			temp_t = temp_t->getNext();
		}
	}
	
	return counter;
}

//print function, outputs all of the data in each node
template <typename Type>
void CyclicLinkedList<Type>::printList() const
{
	SingleNode<Type> *temp_pl = head;
	std::cout << "Outputed list:\n";
	
	while(temp_pl!=NULL)
	{
		std::cout<< temp_pl->getData() << "\n";
		temp_pl= temp_pl->getNext();
	}
}
#endif