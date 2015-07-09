#include "linkedlist.h"

#include <list>
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <assert.h>

bool compare(LN<int>* first, LN<int>* second)
{
	while((first != nullptr) && (second != nullptr))
	{
		if(*first != *second)
		{
			return false;
		}
		advance(first);
		advance(second);
	}
	return true;
}

bool compare(PLN<int>* first, PLN<int>* second)
{
	bool check = compare((LN<int>*) first, (LN<int>*) second);
	if(!check)
	{
		return false;
	}

	while((first != nullptr) && (second != nullptr))
	{
		if(*first != *second)
		{
			return false;
		}
		jump(first);
		jump(second);
	}
	return true;
}

std::pair<LN<int>*, LN<int>*> generate_list()
{
	LN<int>* head = new LN<int>(0);
	LN<int>* curr = head;
	const int size = rand() % SIZE;
	for(int i = 0; i < size; ++i)
	{
		curr->next = new LN<int>(i+1);
		advance(curr);
	}
	return std::make_pair(head, curr);
}

std::vector<LN<int>*> generate_merge()
{
	std::vector<LN<int>*> test;
	test.push_back(new LN<int>(0));
	test.push_back(new LN<int>(0));
	test.push_back(new LN<int>(1));

	LN<int>* result = test[0];
	result->next = new LN<int>(1);
	advance(result);

	LN<int>* lhs = test[1];
	LN<int>* rhs = test[2];

	const int size = rand() % SIZE;
	for(int i = 0; i < size; ++i)
	{
		const int offset = rand() % SIZE;
		result->next = new LN<int>(result->value + offset);
		assert(*result <= *(result->next));

		const int side = (rand() % SIZE) % 2;
		if(side)
		{
			lhs->next = new LN<int>(result->value + offset);
			assert(*lhs <= *(lhs->next));
			advance(lhs);
		}
		else
		{
			rhs->next = new LN<int>(result->value + offset);
			assert(*rhs <= *(rhs->next));
			advance(rhs);
		}
		advance(result);
	}
	return test;
}

std::pair<LN<int>*, LN<int>*> generate_reverse()
{
	std::list<int> rand_list;
	const int size = rand() % SIZE + 1;
	for(int i = 0; i < size+1; ++i)
	{
		rand_list.push_back(rand() % SIZE);
	}

	LN<int>* forward = nullptr;
	LN<int>* fcurr = nullptr;
	for(auto& v : rand_list)
	{
		if(!forward)
		{
			forward = new LN<int>(v);
			fcurr = forward;
		}
		else
		{
			fcurr->next = new LN<int>(v);
			advance(fcurr);
		}
	}

	LN<int>* backward = nullptr;
	LN<int>* bcurr = nullptr;
	for(auto iter = rand_list.rbegin(); iter != rand_list.rend(); ++iter)
	{
		if(!backward)
		{
			backward = new LN<int>(*iter);
			bcurr = backward;
		}
		else
		{
			bcurr->next = new LN<int>(*iter);
			advance(bcurr);
		}
	}
	return std::make_pair(forward, backward);
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

PLN<int>* generate_posting_list()
{
	PLN<int>* head = new PLN<int>(0);
	PLN<int>* curr = head;

	std::vector<PLN<int>*> jump_set;
	jump_set.push_back(head);

	const int size = rand() % SIZE + 1;
	for(int i = 0; i < size; ++i)
	{
		curr->next = new PLN<int>(i+1);
		advance(curr);
		jump_set.push_back(curr);
	}

	for(int i = 0; i < SIZE; ++i)
	{
		const int lhs = rand() % size;
		const int rhs = rand() % size;
		std::swap(jump_set[lhs], jump_set[rhs]);
	}

	int pos = 0;
	curr = head;
	for(auto& v : jump_set)
	{
		if(v->value > pos)
		{
			curr->jump = v;
			advance(curr);
		}
	}
	return head;
}

void print_jump(PLN<int>* list)
{
	while(list != NULL)
	{
		std::cout << list->value << " ";
		jump(list);
	}
	std::cout << "NULL" << std::endl;
}

void print_cycle(LN<int>* list)
{
	LN<int>* prev = list;
	advance(list);
	while((list != NULL) && (prev->value < list->value))
	{
		std::cout << prev->value << " ";	
		advance(prev);
		advance(list);
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

void jump(PLN<int>*& node)
{
	if(node != nullptr)
	{
		node = node->jump;
	}
}
