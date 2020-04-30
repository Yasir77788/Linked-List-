// NumberList.h
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
	struct ListNode // struct for the ListNode
	{
		double value;
		struct ListNode* next; // Pointer to next node
	};
	ListNode* head;

public:
	NumberList()
	{
		head = nullptr;
	}

	~NumberList();
	// List Operations
	void appendNode(double);
	void insertNode(double);
	void deleteNode(double);
	void displayList() const;

};
#endif
