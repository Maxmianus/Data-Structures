#ifndef SINGLENODE_H
#define SINGLENODE_H

template <typename Type> class CyclicLinkedList; //forward declaration so the templated class can be called as a friend

template <typename Type>
class SingleNode
{
	private:
		Type data; //Type variable that contains the data information of the node
		SingleNode<Type> *next;	//pointer that poinds to the next SingleNode object in the list
		Type getData() const; //returns the element in the node
		SingleNode(Type const &cp, SingleNode *tp);	//Class constructor
		SingleNode<Type> *getNext() const; //function that returns the next node or NULL if empty

		friend class CyclicLinkedList<Type>;
};

//Initializes a SingleNode object that assigns the arguments to member variables data and next
template <typename Type>
SingleNode<Type>::SingleNode(Type const &cp, SingleNode *tp)
{
	data = cp;
	next = tp;
}

// returns the element in the node
template <typename Type>
Type SingleNode<Type>::getData() const
{
	return data;
}

//function that returns the next node or NULL if empty
template <typename Type>
SingleNode<Type> *SingleNode<Type>::getNext() const
{
	return next;
}
#endif