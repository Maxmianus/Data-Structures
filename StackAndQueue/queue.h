#include <iostream>
#ifndef QUEUE_H
#define QUEUE_h

template <typename Type>
class DynQueue
{
	private:
		Type *array;	//Type pointer that holds the array in the queue
		int iHead;	//Holds the position of the array that is the head
		int iTail;	//Hold the position of the array that is the tail
		int count; //counter
		int initialSize; //Inital size of the array
		int arraySize; //Current size of the array
		
	public:
		DynQueue(int n);	//Constructor that initializes the queue and array
		~DynQueue();	//destructor
		bool empty() const; //Checks if the queue is empty
		int capacity() const; //Returns the current size of the array
		int size() const; //Returns the number of elements in the array
		void enqueue(Type const &data);	//Adds an element to the end of queue, doubles the size if full
		void clear();	//Deletes all of the elements in queue and sets the array size to its initial size
		void display();	//Prints out all of the elements in the arrray
		Type dequeue();	//Deletes the current head and sets the next element as the head, if queue gets low array space is reallocated
		Type front() const;	//returns the element in the current head
		Type back() const;	//returns the last element in the queue
};

//Constructor
template <typename Type>
DynQueue<Type>::DynQueue(int n)
{
	if(n < 1)
	{
		array = new Type[1];
		initialSize = 1;
		arraySize = 1;
	}
	else
	{
		array = new Type[n];
		initialSize = n;
		arraySize = n;
	}
	
	iHead = iTail = count = 0;
}

//Destructor
template <typename Type>
DynQueue<Type>::~DynQueue()
{
	delete array;
}

//Checks if count is equal to zero to see if empty
template <typename Type>
bool DynQueue<Type>:: empty() const
{
	if(count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Deletes the current head and sets the next element as the head, if queue gets low array space is reallocated, returns the dequeued element
template <typename Type>
Type DynQueue<Type>:: dequeue()
{
	Type hold = array[iHead];
	iHead = (iHead+1)%arraySize;
	count--;
	
	if((arraySize/4 == count) && (arraySize > initialSize))
	{
		arraySize = (arraySize/2);
		Type *tmp = new Type[arraySize];
		iHead = (iHead+1)%arraySize;
		iTail = (iTail%arraySize);
		
		for(int p = 0; p<(count); p++)
		{
			tmp[p] = array[p];
		}
		
		array = tmp;
		
		delete tmp;
	}
	
	return hold;
}

//Adds an element to the end of queue, doubles the size if full
template <typename Type>
void DynQueue<Type>:: enqueue(Type const &data)
{
	if(count == arraySize)
	{
		arraySize = (arraySize*2);
		
		Type *temp = new Type[arraySize];
		
		for(int i = 0; i<(count); i++)
		{
			temp[i] = array[i];
		}
		
		array = temp;
		
		delete temp;
		array[iTail] = data;
		iTail = (iTail+1)%arraySize;
		count++;
	}
	else
	{
		array[iTail] = data;
		iTail = (iTail+1)%arraySize;
		count++;
	}
}

//Returns the current size of the array
template <typename Type>
int DynQueue<Type>::capacity() const
{
	return arraySize;
}

//Returns the number of elements in the array
template <typename Type>
int DynQueue<Type>::size() const
{
	return count;
}

//Deletes the array and initiales a new one that is the same size as the initial size
template <typename Type>
void DynQueue<Type>:: clear()
{
	delete array;
	array = new Type[initialSize];
	arraySize = initialSize;
	iHead = iTail = count = 0;
}

//Returns the element in position iHead of the array
template <typename Type>
Type DynQueue<Type>:: front() const
{
	return array[iHead];
}

//Returns the element of the last queued element
template <typename Type>
Type DynQueue<Type>:: back() const
{
	if(iTail == 0)
	{
		return array[arraySize-1];
	}
	else
	{
		return array[(iTail-1)%arraySize];
	}
}

//prints everything in the array
template <typename Type>
void DynQueue<Type>:: display()
{
	int temp;
	
	for(int x = 0; x<count; x++)
	{
		temp = iHead;
		std::cout << array[temp] << "\n";
		temp = (iHead+1)%arraySize;
	}
}
#endif