#include <iostream>
#include "SingleNode.h"
#include "CyclicLinkedList.h"
#include "DoublyLinkedList.h"
int main()
{
	char list_type;
	int user_choice;
	double input_five;
	double input_six;
	double input_seven;
	double input_ten;
	int e;
	
	CyclicLinkedList<double> list; //Initialized CyclicLinkedList object with type double
	DoublyLinkedList<double> listd;
	//User decides whether they want a singly list (s) or doubly (d)
	std::cout<< "Please enter s or d: \n";
	std::cin >> list_type;
	
	//Switch statement that allows the user decide what they want to do with their linked list depending on the type
	if(list_type == 's')
	{
		std::cout <<"1. Create list\n2. Count number of items \n3. Retrieve first item \n4. Retrieve last item \n5. Count instances of an item \n6. Push front \n7. Push back \n8. Pop front \n9. Pop back \n10. Delete instance(s) of an item \n11. Print list \n12. Exit\n";
		while(true)
		{
			std::cin >> user_choice;
			switch(user_choice)
			{
				case 1:
					
					break;
				case 2:
					std::cout << "Number of items: " << list.size() << "\n";
					break;
				case 3:
					if(list.empty())
					{
						std::cout<<"empty list\n";
						break;
					}
					else
					{
						std::cout << "First item: " << listd.front() << "\n";
						break;
					}
				case 4:
					if(list.empty())
					{
						std::cout<<"empty list\n";
						break;
					}
					else
					{
						std::cout << "Last item: " << list.back() << "\n";
						break;
					}
				case 5:
					std::cin >> input_five;
					std::cout << input_five << " shows up " << list.count(input_five) << " time(s)\n";
					break;
				case 6:
					std::cin >> input_six;
					list.push_front(input_six);
					break;
				case 7:
					std::cin >> input_seven;
					list.push_back(input_seven);
					break;
				case 8:
					if(list.empty())
					{
						std::cout << "empty list\n";
						break;
					}
					else
					{
						listd.pop_front();
						break;
					}
				case 9:
					if(list.empty())
					{
						std::cout << "empty list\n";
						break;
					}
					else
					{
						list.pop_back();
						break;
					}
				case 10:
					std::cin >> input_ten;
					e = list.erase(input_ten);
					std::cout << "Number of items deleted: " << e << "\n";
					break;
				case 11:
					if(listd.empty())
					{
						std::cout<<"empty list\n";
					}
					else
					{
						list.printList();
					}
					break;
				case 12:
					return 0;
				default:
					std::cout <<"1. Create list\n2. Count number of items \n3. Retrieve first item \n4. Retrieve last item \n5. Count instances of an item \n6. Push front \n7. Push back \n8. Pop front \n9. Pop back \n10. Delete instance(s) of an item \n11. Print list \n12. Exit\n";
					break;
			}
		}
	}
	else if(list_type == 'd')
	{
		while(true)
		{
			std::cout << "1. Create list\n2. Count number of items \n3. Retrieve first item \n4. Retrieve last item \n5. Count instances of an item \n6. Push front \n7. Push back \n8. Pop front \n9. Pop back \n10. Delete instance(s) of an item \n11. Print list \n12. Exit\n";
			std::cin >> user_choice;
			switch(user_choice)
			{
                                case 1:
					//DoublyLinkedList<Type> listd;
                                        break;
                                case 2:
                                        std::cout << "Number of items: " << listd.size() << "\n";
                                        break;
                                case 3:
                                        if(listd.empty())
                                        {
                                                std::cout<<"empty list\n";
                                                break;
                                        }
                                        else
                                        {
                                                std::cout << "First item: " << listd.front() << "\n";
                                                break;
                                        }
                                case 4:
                                        if(listd.empty())
                                        {
                                                std::cout<<"empty list\n";
                                                break;
                                        }
                                        else
                                        {
                                                std::cout << "Last item: " << listd.back() << "\n";
                                                break;
                                        }
                                case 5:
                                        std::cout << "Enter data instances you wish to count\n";
					std::cin >> input_five;
                                        std::cout << input_five << " shows up " << listd.count(input_five) << " time(s)\n";
                                        break;
                                case 6:
                                        std::cout << "Enter data to be stored\n";
					std::cin >> input_six;
                                        listd.push_front(input_six);
                                        break;
				case 7:
                                        std::cout << "Enter data to be stored\n";
					std::cin >> input_seven;
                                        listd.push_back(input_seven);
                                        break;
                                case 8:
                                        if(listd.empty())
                                        {
                                                std::cout << "empty list\n";
                                                break;
                                        }
                                        else
                                        {
                                                listd.pop_front();
                                                break;
                                        }
                                case 9:
                                        if(listd.empty())
                                        {
                                                std::cout << "empty list\n";
                                                break;
                                        }
                                        else
                                        {
                                                listd.pop_back();
                                                break;
                                        }
                                case 10:
					std::cout << "Enter data you wish to delete\n";
                                        std::cin >> input_ten;
                                        e = listd.erase(input_ten);
                                        std::cout << "Number of items deleted: " << e << "\n";
                                        break;
                                case 11:
                                        if(listd.empty())
                                        {
                                                std::cout<<"empty list\n";
                                        }
                                        else
                                        {
                                                listd.printList();
                                        }
                                        break;
				case 12:
					return 0;
			}
		}
	}
	else
	{
		std::cout << "ERROR, INVALID INPUT";
	}
	return 0;
}
