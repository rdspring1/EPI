#include <list>
#include <assert.h>

using namespace std;

template<typename T>
class max_stack
{
	public:
		bool empty() const
		{
			return data.empty();
		}

		unsigned size() const
		{
			return data.size();
		}

		void push(const T& value)
		{
			data.push_back(value);
			T& new_max = (max_data.back() < value) ? value : max_data.back();
			max_data.push_back(new_max);
		}

		void push(const T&& value)
		{
			data.push_back(value);
			T new_max = (max_data.back() < value) ? value : max_data.back();
			max_data.push_back(new_max);
		}

		T& pop()
		{
			T& value = data.back();
			data.pop_back();
			max_data.pop_back();
			return value;
		}

		T& max()
		{
			assert(data.size() == max_data.size());
			assert(max_data.size() > 0);
			return max_data.back();
		}
	private:
		list<T> data;
		list<T> max_data;
};
