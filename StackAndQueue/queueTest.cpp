#include <iostream>
#include "queue.h"
#include "stack.h"

int main()
{

   /* //Test all Functions
    DynStack<string> stack1(15);
    
    //add 2 strings
    std::cout << stack1.empty() << "\n";
    stack1.push("Chicken");
    stack1.push("Fries");
    std::cout << "top: " << stack1.top() << "\n";
    std::cout << "empty?" << stack1.empty() << "\n";
    std::cout << "size: " << stack1.size() << "\n";
    std::cout << "capacity: " << stack1.capacity() << "\n";
    std::cout << "display: ";
    stack1.display();
    std::cout << "popped: " << stack1.pop() << "\n";
    std::cout << "display: "; 
    stack1.display();
    std::cout << "pushing coke..";
    stack1.push("coke");
    std::cout << "\nMARK0\n";
    stack1.display();
    std::cout << "\nMARK1";
    stack1.clear();
    std::cout << "\nMARK2";
    stack1.display();
    std::cout << "\nMark3";*/

	DynQueue<std::string> que(15);
	
	que.enqueue("peep");
	
	for(int i = 0; i<50; i++)
	{
		que.enqueue("hey");
	}
	
	for(int i=0; i<40; i++)
	{
		que.dequeue();
	}
	
	que.enqueue("yo");
	que.display();
	//que.clear();
	
	if(que.empty())
	{
		std::cout << "empty list\n";
	}
	else
	{
		que.dequeue();
	}
	
	std::cout << que.front() << "\n";
	std::cout << que.back() << "\n";

	std::cout << que.capacity() << "\n";
	std::cout << que.size() << "\n";
	
	return 0;
}