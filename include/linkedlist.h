#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>
#include <utility>

static const int NONE = -1;
static const int SIZE = 100;

template<typename T>
class LN
{
	public:
		T value;
		LN<T>* next;

	public:
		LN(const T& v)
		{
			this->value = v;
			this->next = nullptr;
		}

	bool operator<(const LN& other) const
	{
		return this->value < other.value;
	}

	bool operator<=(const LN& other) const
	{
		return !(*this > other);
	}

	bool operator>(const LN& other) const
	{
		return this->value > other.value;
	}

	bool operator>=(const LN& other) const
	{
		return !(*this < other);
	}

	bool operator==(const LN& other) const
	{
		return this->value == other.value;
	}

	bool operator!=(const LN& other) const
	{
		return !(*this == other);
	}
};

template<typename T>
class PLN
{
	public:
		T value;
		PLN<T>* next;
		PLN<T>* jump;

	public:
		PLN(const T& v)
	{
		this->value = v;
		this->next = nullptr;
		this->jump = nullptr;
	}

	bool operator<(const PLN& other) const
	{
		return this->value < other.value;
	}

	bool operator<=(const PLN& other) const
	{
		return !(*this > other);
	}

	bool operator>(const PLN& other) const
	{
		return this->value > other.value;
	}

	bool operator>=(const PLN& other) const
	{
		return !(*this < other);
	}

	bool operator==(const PLN& other) const
	{
		return this->value == other.value;
	}

	bool operator!=(const PLN& other) const
	{
		return !(*this == other);
	}
};

// Iterator Functions
template<typename T>
void advance(T& node)
{
	if(node != nullptr)
	{
		node = node->next;
	}
}
void jump(PLN<int>*& node);

// Unit Test Functions
bool compare(LN<int>* first, LN<int>* second);
bool compare(PLN<int>* first, PLN<int>* second);

// Generate Functions
std::pair<LN<int>*, LN<int>*> generate_list();
std::vector<LN<int>*> generate_merge();
std::pair<LN<int>*, LN<int>*> generate_reverse();
std::pair<LN<int>*, int> generate_cycle();
PLN<int>* generate_posting_list();

// Debug Functions
template<typename T>
void print(T* list)
{
	while(list != NULL)
	{
		std::cout << list->value << " ";
		advance(list);
	}
	std::cout << "NULL" << std::endl;
}
void print_jump(PLN<int>* list);
void print_cycle(LN<int>* list);

// Problem Functions
LN<int>* merge(LN<int>* first, LN<int>* second);
LN<int>* reverse(LN<int>* original);
LN<int>* cyclicity(LN<int>* head);
PLN<int>* copy_posting_list(PLN<int>* original);

#endif // LINKEDLIST_H
