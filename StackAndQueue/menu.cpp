#include <iostream>
#include "stack.h"
#include "queue.h"

int main()
{
	char list_type;
	int user_choice;
	string user_input;
	
	DynQueue<string> que(15);
	DynStack<string> stack1(15);
	
	std::cout << "Please enter s or q:\n";
	std::cin >> list_type;
	
	if(list_type == 'q')
	{
		std::cout << "1. Return Capacity\n2. Return size of the data structure\n3. View first item\n4. Insert item\n5. Delete item\n6. Display\n7. Clear\n8. Exit\n";
		
		while(true)
		{
			std::cin >> user_choice;
			switch(user_choice)
			{
				case 1:
					std::cout << que.size() << "\n";
					break;
				
				case 2:
					std::cout << que.capacity() << "\n";
					break;
					
				case 3:
					if(que.empty())
					{
						std::cout << "The queue is empty\n";
						break;
					}
					else
					{
						std::cout << que.front() << "\n";
						break;
					}
					
				case 4:
						std::cout << "Enter a string\n";
						std::cin >> user_input;
						que.enqueue(user_input);
						break;
					
				case 5:
					if(que.empty())
					{
						std::cout << "The queue is empty\n";
						break;
					}
					else
					{
						que.dequeue();
						break;
					}
				
				case 6:
					que.display();
					break;
				
				case 7:
					que.clear();
					std::cout << "Queue cleared\n";
					break;
				
				case 8:
					return 0;
				
				default:
					std::cout << "1. Return Capacity\n2. Return size of the data structure\n3. View first item\n4. Insert item\n5. Delete item\n6. Display\n7. Clear\n8. Exit\n";
					break;
			}
		}
	}
	else if(list_type == 's')
	{
		std::cout << "1. Return Capacity\n2. Return size of the data structure\n3. View first item\n4. Insert item\n5. Delete item\n6. Display\n7. Clear\n8. Exit\n";
		
		while(true)
		{
			std::cin >> user_choice;
			
			switch(user_choice)
			{
				case 1:
					std::cout << stack1.size() << "\n";
					break;
				
				case 2:
					std::cout << stack1.capacity() << "\n";
					break;
					
				case 3:
					if(stack1.empty())
					{
						std::cout << "Stack is empty\n";
						break;
					}
					else
					{
						std::cout << stack1.top() << "\n";
						break;
					}
				
				case 4:
					std::cout << "Enter a string\n";
					std::cin >> user_input;
					stack1.push(user_input);
					break;
				
				case 5:
					if(stack1.empty())
					{
						std::cout << "Stack is empty\n";
						break;
					}
					else
					{
						stack1.pop();
						break;
					}
				case 6:
					stack1.display();
					break;
					
				case 7:
					stack1.clear();
					std::cout << "Stack cleared\n";
					break;
					
				case 8:
					return 0;
					
				default:
					std::cout << "1. Return Capacity\n2. Return size of the data structure\n3. View first item\n4. Insert item\n5. Delete item\n6. Display\n7. Clear\n8. Exit\n";
					break;
			}
		}
	}
	else
	{
		std::cout << "Invalid input\n";
	}
	
	return 0;
}