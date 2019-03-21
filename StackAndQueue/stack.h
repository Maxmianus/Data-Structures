#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <array>
#ifndef DynStack_H
#define DynStack_H

using namespace std;

template <typename Type>
class DynStack
{
	private:
		Type *array;
		int count = 0;
		int initialSize = 0;
		int arraySize = 0;
	public:
		DynStack(int n = 15);
		~DynStack();
		Type top() const;
		int size() const;
		bool empty() const;
		int capacity() const;
		void display();
		void push(Type const &data);
		Type pop();
		void clear();
};

template <typename Type>
DynStack<Type>::DynStack(int n){
	if (n < 1)
		n = 1;
	count = 0;
	initialSize = n;
	arraySize = n;
	array = new Type[n];
}

template <typename Type>
DynStack<Type>::~DynStack(){
	delete array;
}

template <typename Type>
Type DynStack<Type>::top() const{
	return *((array+count)-1);
}

template <typename Type>
int DynStack<Type>::size() const{
	return count;
}

template <typename Type>
bool DynStack<Type>::empty() const{
	return (count == 0);
}

template <typename Type>
int DynStack<Type>::capacity() const{
	return arraySize;
}

template <typename Type>
void DynStack<Type>::display(){
	int i;
	if (count == 0){
	    cout << "EMPTY\n";
    }
    else{
	    for(i = 0; i < count; i++){
		    cout << *(array+i) << "\n";
		}
	}
}

template <typename Type>
void DynStack<Type>::push(Type const &data){
	if (count == arraySize){
		arraySize *= 2;
		Type *temp = array;
		array = new Type[arraySize];
		int i; // Loop Will copy over values
		for(i = 0; i < count; i++){
			*(array+i) = *(temp+i);
		}
		delete temp;
		*(array+count) = data;
	}
	else{
		*(array+count) = data;
	}
	count++;
}

template <typename Type>
Type DynStack<Type>::pop(){
	Type temp = *((array+count)-1);//element being popped
	if ((arraySize > initialSize) && ((double)arraySize * 0.25 == (double)count))
	{
		arraySize /= 2;
                Type *tempArr = array;
                array = new Type[arraySize];
                int i; // Loop Will copy over values
                for(i = 0; i < count; i++){
                        *(array+i) = *(tempArr+i);
                }
                delete tempArr;
	}
	count--;
	return temp;
}

template <typename Type>
void DynStack<Type>::clear(){
    delete array;
    array = new Type[initialSize];
    arraySize = initialSize;
    count = 0;
}
#endif		
