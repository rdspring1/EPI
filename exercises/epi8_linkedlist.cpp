#include "linkedlist.h"

LN<int>* merge(LN<int>* first, LN<int>* second)
{
	// TODO
	return nullptr;
}

LN<int>* reverse(LN<int>* original)
{
	// TODO
	return nullptr;
}

LN<int>* cyclicity(LN<int>* head)
{
	// Find Cycle
	LN<int>* slow = head;
	LN<int>* fast = head;
	do
	{
		advance(slow);
		advance(fast);
		advance(fast);
	}
	while(slow != fast);

	if(!slow && !fast)
	{
		return nullptr;
	}	

	// Cycle Length
	int length = 1;
	advance(fast);
	while(slow != fast)
	{
		++length;
		advance(fast);
	}

	// Determine Start Node of Cycle
	slow = head;
	fast = head;
	for(int i = 0; i < length; ++i)
	{
		advance(fast);
	}

	while(slow != fast)
	{
		advance(slow);
		advance(fast);
	}
	return slow;
}

PLN<int>* copy_posting_list(PLN<int>* original)
{
	// TODO
	return nullptr;
}
