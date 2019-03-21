#ifndef DOUBLENODE_H
#define DOUBLENODE_H

template <typename Type> class DoublyLinkedList;

template <typename Type> 
class DoubleNode
{
	
	private:
		Type Data;
		DoubleNode<Type> *next;
		DoubleNode<Type> *prev;
		DoubleNode(Type const &input, DoubleNode *in_prev=nullptr, DoubleNode *in_next=nullptr);
		Type getData() const;
		DoubleNode *getNext() const;
		DoubleNode *getPrevious() const;

		friend class DoublyLinkedList<Type>;
};

template <typename Type>
DoubleNode<Type>::DoubleNode(Type const &input, DoubleNode *in_prev, DoubleNode *in_next)
{
	Data = input;
	prev = in_prev;
	next = in_next;
}

template <typename Type>
Type DoubleNode<Type>::getData() const
{
	return Data;
}

template <typename Type>
DoubleNode<Type> *DoubleNode<Type>::getNext() const
{
	return next;
}

template <typename Type>
DoubleNode<Type> *DoubleNode<Type>::getPrevious() const
{
	return prev;
}
#endif

