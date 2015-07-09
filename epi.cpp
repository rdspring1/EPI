#include <time.h>
#include <utility>
#include <iostream>
#include <gtest/gtest.h>

#include "linkedlist.h"

using namespace std;

static const int RUNS = 10000;

TEST(EPI8_LinkedList, Merge)
{
	static const unsigned ELMS = 3;
	for(int i = 0; i < RUNS; ++i)
	{
		std::vector<LN<int>*> test = generate_merge();
		ASSERT_TRUE(test.size() == ELMS);
		ASSERT_TRUE(test[0] != nullptr);
		LN<int>* merged_list = merge(test[1], test[2]);
		ASSERT_TRUE(merged_list != nullptr);
		ASSERT_TRUE(compare(merged_list, test[0]));
	}
}

TEST(EPI8_LinkedList, Reverse)
{
	for(int i = 0; i < RUNS; ++i)
	{
		std::pair<LN<int>*, LN<int>*> test = generate_reverse();
		ASSERT_TRUE(test.first != nullptr);
		ASSERT_TRUE(test.second != nullptr);
		EXPECT_FALSE(compare(test.first, test.second));
		LN<int>* reverse_list = reverse(test.first);
		ASSERT_TRUE(reverse_list != nullptr);
		ASSERT_TRUE(compare(reverse_list, test.second));
	}
}

TEST(EPI8_LinkedList, Cyclicity)
{
	for(int i = 0; i < RUNS; ++i)
	{
		std::pair<LN<int>*, int> rnd = generate_cycle();
		LN<int>* cycle_start_ptr = cyclicity(rnd.first);
		if(rnd.second == NONE)
		{
			ASSERT_EQ(nullptr, cycle_start_ptr);
		}
		else
		{
			ASSERT_TRUE(cycle_start_ptr != nullptr); 
			ASSERT_EQ(cycle_start_ptr->value, rnd.second);
		}	
	}
}

TEST(EPI8_LinkedList, PostingList)
{
	for(int i = 0; i < RUNS; ++i)
	{
		PLN<int>* original = generate_posting_list();
		ASSERT_TRUE(original != nullptr);
		PLN<int>* copy = copy_posting_list(original);
		ASSERT_TRUE(copy != nullptr);
		ASSERT_TRUE(compare(original, copy));
	}
}

int main(int argc, char **argv) 
{
	srand (time(NULL));
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
