#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "list.h"

using namespace std;

static const int NONE = -1;
static const int SIZE = 100;
static const int RUNS = 1000;

pair<LN<int>*, int> generate()
{
	LN<int>* head = new LN<int>(0);
	LN<int>* curr = head;
	const int size = rand() % SIZE;
	for(int i = 0; i < size; ++i)
	{
		curr->next = new LN<int>(i+1);
		curr = curr->next;
	}

	const int cycle = (rand() % RUNS) % 2;
	int cycle_pos = NONE;
	if(cycle && (size > 0))
	{
		cycle_pos = rand() % size;
		LN<int>* cycle_start = head;
		for(int i = 0; i != cycle_pos; ++i)
		{
			cycle_start = cycle_start->next;
		}
		curr->next = cycle_start;
	}
	return make_pair(head, cycle_pos); 
}

LN<int>* advance(LN<int>* node)
{
	if(!node)
	{
		return NULL;
	}
	return node->next;
}

LN<int>* cycle_test(LN<int>* head)
{
	// Find Cycle
	LN<int>* slow = head;
	LN<int>* fast = head;
	do
	{
		slow = advance(slow);
		fast = advance(fast);
		fast = advance(fast);
	}
	while(slow != fast);

	if(!slow && !fast)
	{
		return NULL;
	}	

	// Cycle Length
	int length = 1;
	fast = advance(fast);
	while(slow != fast)
	{
		++length;
		fast = advance(fast);
	}

	// Determine Start Node of Cycle
	slow = head;
	fast = head;
	for(int i = 0; i < length; ++i)
	{
		fast = advance(fast);
	}

	while(slow != fast)
	{
		slow = advance(slow);
		fast = advance(fast);
	}
	return slow;
}

void print(LN<int>* list)
{
	int visit = 0;
	LN<int>* prev = list;
	list = advance(list);
	while((list != NULL) && (prev->value < list->value))
	{
		cout << prev->value << " ";	
		prev = prev->next;
		list = list->next;
	}
	if(list != NULL)
	{
		cout << prev->value << " " << list->value << endl;
	}
	else
	{
		cout << "NULL" << endl;
	}
}

int main()
{
	srand (time(NULL));
	for(int i = 0; i < RUNS; ++i)
	{
		pair<LN<int>*, int> rnd = generate();
		//print(rnd.first);
		LN<int>* cycle_start = cycle_test(rnd.first);
		if(rnd.second == NONE)
		{
			assert(cycle_start == NULL);
		}
		else
		{
			assert(cycle_start->value == rnd.second);
		}	
	}
}
