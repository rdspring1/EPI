#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
		LN(T v)
		{
			this->value = v;
			this->next = NULL;
		}
};

template<typename T>
class PLN : public LN<T>
{
	public:
		LN<T>* jump;

	public:
		PLN(T v) : LN<T>(v)
	{
		this->jump = NULL;
	}
};

// Iterator Functions
LN<int>* advance(LN<int>* node);

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
void print(LN<int>* list);

// Problem Functions
LN<int>* merge(LN<int>* first, LN<int>* second);
LN<int>* reverse(LN<int>* original);
LN<int>* cyclicity(LN<int>* head);
PLN<int>* copy_posting_list(PLN<int>* original);

#endif // LINKEDLIST_H
