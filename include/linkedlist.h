#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <utility>

static const int NONE = -1;
static const int SIZE = 100;

template<typename T>
struct LN
{
	LN(T v)
	{
		this->value = v;
		this->next = NULL;
	}

	T value;
	LN<T>* next;
};

// Iterator Functions
LN<int>* advance(LN<int>* node);

// Unit Test Functions
std::pair<LN<int>*, LN<int>*> generate_list();
std::pair<LN<int>*, int> generate_cycle();

// Debug Functions
void print(LN<int>* list);

// Problem Functions
LN<int>* cyclicity(LN<int>* head);

#endif // LINKEDLIST_H
