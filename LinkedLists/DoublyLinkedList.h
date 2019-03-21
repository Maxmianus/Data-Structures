#include <iostream>
#include <cstddef>
#include <stdexcept>
#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H
#include "DoubleNode.h"
template <typename Type>

class DoublyLinkedList
{
	private:
		DoubleNode<Type> *head;
		DoubleNode<Type> *tail;
		int sizel;
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		int size() const;
		bool empty() const;
		Type front() const;
		Type back() const;
		DoubleNode<Type> *headn() const;
		DoubleNode<Type> *tailn() const;
		int count(Type const &input) const;
		void push_front(Type const &input);
		void push_back(Type const &input);
		Type pop_front();
		Type pop_back();
		int erase(Type const &node_data);
		void printList() const;
};

template <typename Type>
DoublyLinkedList<Type>::DoublyLinkedList()
{
	head = tail = nullptr;
	sizel = 0;
}

template <typename Type>
DoublyLinkedList<Type>::~DoublyLinkedList()
{
	while (head != nullptr)
	{
		pop_front();
	}
}

template <typename Type>
int DoublyLinkedList<Type>::size() const
{
	return sizel;
}

template <typename Type>
bool DoublyLinkedList<Type>::empty() const
{
	return (head == nullptr);
}

template <typename Type>
Type DoublyLinkedList<Type>::front() const
{
	if (sizel < 1)
		throw std::underflow_error("No list");
	return head->getData();
}

template <typename Type>
Type DoublyLinkedList<Type>::back() const
{
	if (sizel < 1)
		throw std::underflow_error("No list");
	return tail->getData();
}

template <typename Type>
DoubleNode<Type> *DoublyLinkedList<Type>::headn() const
{
	return head;
}

template <typename Type>
DoubleNode<Type> *DoublyLinkedList<Type>::tailn() const
{
	return tail;
}

template <typename Type>
int DoublyLinkedList<Type>::count(Type const &input) const
{
	DoubleNode<Type> *current = head;
	int num_nodes = 0;
        std::cout << "\n Finding instances...:\n";
        while(current != nullptr)
        {
                if(current->getData() == input)
			num_nodes++;
                current = current->next;
        }
	return num_nodes;
}

template <typename Type>
void DoublyLinkedList<Type>::push_front(Type const &input)
{
	DoubleNode<Type> *node = new DoubleNode<Type>(input, nullptr, head);
	if (sizel < 1)
		tail = node;
	//std::cout << "PushMark1\n";
	if(head != nullptr)
		head->prev = node;
	//std::cout << "PushMark2\n";
	head = node;
	//std::cout << "PushMark3\n";
	sizel++;
}

template <typename Type>
void DoublyLinkedList<Type>::push_back(Type const &input)
{
	DoubleNode<Type> *node = new DoubleNode<Type>(input, tail, nullptr);
	if (sizel < 1)
		head = node;
	if (tail != nullptr)
		tail->next = node;
	tail = node;
	sizel++;
}

template <typename Type>
Type DoublyLinkedList<Type>::pop_front()
{
	if (sizel < 1)
		throw std::underflow_error("No nodes");
	DoubleNode<Type> *temp = head;
	head = head->next;
	head->prev = nullptr;
	Type pop_data = temp->Data;
	delete temp;
	sizel--;
	return pop_data;
}

template <typename Type>
Type DoublyLinkedList<Type>::pop_back()
{
	if (sizel < 1)
		throw std::underflow_error("No nodes");
	DoubleNode<Type> *temp = tail;
	tail = (*tail).getPrevious();
	tail->next = nullptr;
	Type pop_data = (*temp).getData(); //TESTING
	delete temp;
	sizel--;
	return pop_data;
}

template <typename Type>
int DoublyLinkedList<Type>::erase(Type const &node_data)
{
	int del_nodes;
	DoubleNode<Type> *current = head;
	DoubleNode<Type> *temp = nullptr;
	while (current != nullptr)
	{
		if (current->getData() == node_data)
		{
			if (current->prev == nullptr)
				head = current->next;
			if (current->next == nullptr)
				tail = current->prev;
			(current->prev)->next = current->next;
			(current->next)->prev = current->prev;
			temp = current;
			current = current->next;
			delete temp;
			sizel--;
			del_nodes++;
		}
		else
		{
			current = current->next;
		}
	}
	return del_nodes;
}

template <typename Type>
void DoublyLinkedList<Type>::printList() const
{
	DoubleNode<Type> *current = head;
	std::cout << "\n LIST:\n";
	while(current != nullptr)
	{
		std::cout << current->getData() << "\n";
		current = current->next;
	}
}
#endif
