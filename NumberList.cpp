#include "NumberList.h"
#include <iostream>

// append node
void NumberList::appendNode(double num)
{
	ListNode* newNode; // Pointer to ListNode for newNode
	ListNode* nodePtr; // Pointer to traverse the list

	// Allocate memory to the new node and store num in it
	newNode = new ListNode();
	newNode->value = num;
	newNode->next = nullptr;


	// Check to see if the list is empty 
	if (!head)
	{
		head = newNode;
		std::cout << "\nThe list was empty... Now, it has a new node " << num << " appended." << std::endl;
	}

	else // it is not empty. Find the last existing node and append
	{
		nodePtr = head; // use nodeptr to go thru the list

		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// link the new node to the lastNode
		nodePtr->next = newNode;
		std::cout << "\nThe list was not empty... New node appended: " << num << std::endl;

	}

}

// Insert Node
void NumberList::insertNode(double num)
{
	ListNode* newNode;
	ListNode* nodePtr;
	ListNode* previousNode = nullptr;

	// Allocate memory to the new node &  store num in it
	newNode = new ListNode;
	newNode->value = num;
	

	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head; // position nodePtr at the head;

		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}

	}
}

// Display list
void NumberList::displayList() const
{
	ListNode* nodePtr;
	
	if (!head)
		std::cout << "\nThe list is empty." << std::endl;
	else
	{
		nodePtr = head; // position nodePtr at the head of the list
		std::cout << "\nDisplaying the list elements:\n" << std::endl;
		while (nodePtr)
		{
			std::cout << nodePtr->value << std::endl;
			nodePtr = nodePtr->next;
		}
	}
}

// Delete node
void NumberList::deleteNode(double num)
{
	ListNode* nodePtr;
	ListNode* previousNode = nullptr;
	if (!head)
	{
		std::cout << "\nNothing to delete." << std::endl;
		return;
	}

	if (head->value == num)
	{
		nodePtr = head;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr) // if nodePtr not at the end of the list
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}

	}
}

// Destory list
NumberList::~NumberList()
{
	ListNode* nodePtr;
	ListNode* nextNode;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;

		std::cout << "Deleting node of value: " << nodePtr->value << std::endl;

		delete nodePtr;

		nodePtr = nextNode;
	}
}
