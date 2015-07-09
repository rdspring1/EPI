#include "linkedlist.h"

LN<int>* merge(LN<int>* first, LN<int>* second)
{
	LN<int>* merged_list = nullptr;
	if(*first < *second)
	{
		merged_list = first;
		advance(first);
	}
	else
	{
		merged_list = second;
		advance(second);
	}

	LN<int>* curr = merged_list;
	while((first != nullptr) && (second != nullptr))
	{
		if(*first < *second)
		{
			curr->next = first;
			advance(first);
		}
		else
		{
			curr->next = second;
			advance(second);
		}
		advance(curr);
	}

	if(!first)
	{
		curr->next = second;
	}
	else
	{
		curr->next = first;
	}
	return merged_list;
}

LN<int>* reverse(LN<int>* original)
{
	LN<int>* prev = nullptr;
	LN<int>* future = original->next;
	while(future != nullptr)
	{
		original->next = prev;
		prev = original;
		original = future;
		future = original->next;
	}
	return original;
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
	PLN<int>* curr = original;

	// step 1 - duplicate elements of original list
	// point the original list to their duplicate counterparts
	while(curr != nullptr)
	{
		curr->next = new PLN<int>(*curr);
	        curr = curr->next->next;	
	}

	PLN<int>* duplicate = original->next;

	// step 2 - copy jump list
	curr = original;
	while(curr != nullptr)
	{	
		if(curr->jump != nullptr)
		{
			curr->next->jump = curr->jump->next;
		}
		curr = curr->next->next;
	}

	// step 3 - restore next field
	curr = original;
	while(curr->next->next != nullptr)
	{
		PLN<int>* old_next = curr->next->next;
		curr->next->next = curr->next->next->next;
		curr->next = old_next;
		advance(curr);
	}
	curr->next = nullptr;

	return duplicate;
}
