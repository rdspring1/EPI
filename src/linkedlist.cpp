#include "linkedlist.h"

#include <iostream>
#include <stdlib.h>
#include <utility>

std::pair<LN<int>*, LN<int>*> generate_list()
{
	LN<int>* head = new LN<int>(0);
	LN<int>* curr = head;
	const int size = rand() % SIZE;
	for(int i = 0; i < size; ++i)
	{
		curr->next = new LN<int>(i+1);
		curr = curr->next;
	}
	return std::make_pair(head, curr);
}

std::pair<LN<int>*, int> generate_cycle()
{
	std::pair<LN<int>*, LN<int>*> rand_list = generate_list();
	LN<int>* tail = rand_list.first;
	const int& size = tail->value; 

	const int cycle = (rand() % SIZE) % 2;
	int cycle_pos = NONE;
	if(cycle && (size > 0))
	{
		cycle_pos = rand() % size;
		LN<int>* cycle_start = rand_list.first;
		for(int i = 0; i != cycle_pos; ++i)
		{
			cycle_start = cycle_start->next;
		}
		tail->next = cycle_start;
	}
	return std::make_pair(rand_list.first, cycle_pos); 
}

void print(LN<int>* list)
{
	int visit = 0;
	LN<int>* prev = list;
	list = advance(list);
	while((list != NULL) && (prev->value < list->value))
	{
		std::cout << prev->value << " ";	
		prev = prev->next;
		list = list->next;
	}
	if(list != NULL)
	{
		std::cout << prev->value << " " << list->value << std::endl;
	}
	else
	{
		std::cout << "NULL" << std::endl;
	}
}

LN<int>* advance(LN<int>* node)
{
	if(!node)
	{
		return NULL;
	}
	return node->next;
}

