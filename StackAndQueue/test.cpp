#include <iostream>
#include "stack.h"

int main()
{
    //Test all Functions
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
    std::cout << "\nMark3";
    return 0;
}
