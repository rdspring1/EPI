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
