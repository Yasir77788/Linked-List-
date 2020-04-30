#include "NumberList.h" // NumberList header file
#include <iostream>

int main()
{
	NumberList obj;

	obj.insertNode(4);
	obj.insertNode(22);
	obj.insertNode(20);
	obj.insertNode(5);
	obj.displayList();


	obj.appendNode(2);
	obj.appendNode(8);
	obj.displayList();

	obj.deleteNode(22);
	obj.displayList();
	

	std::cin.get();
	std::cin.get();
	return 0;
}