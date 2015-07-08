#include <time.h>
#include <utility>
#include <iostream>
#include <gtest/gtest.h>

#include "linkedlist.h"

using namespace std;

static const int RUNS = 1000;

TEST(EPI8_LinkedList, cyclicity)
{
	for(int i = 0; i < RUNS; ++i)
	{
		std::pair<LN<int>*, int> rnd = generate_cycle();
		LN<int>* cycle_start_ptr = cyclicity(rnd.first);
		if(rnd.second == NONE)
		{
			ASSERT_EQ(NULL, cycle_start_ptr);
		}
		else
		{
			ASSERT_TRUE(cycle_start_ptr != NULL); 
			ASSERT_EQ(cycle_start_ptr->value, rnd.second);
		}	
	}
}

int main(int argc, char **argv) 
{
	srand (time(NULL));
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
