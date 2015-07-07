#include "max_stack.h"

int main()
{
	max_stack<int> s;
	s.push(10);
	assert(s.max() == 10);
	s.push(7);
	assert(s.max() == 10);
	s.push(1);
	assert(s.max() == 10);
	s.push(150);
	assert(s.max() == 150);
	s.pop();
	assert(s.max() == 10);

	return 0;
}
