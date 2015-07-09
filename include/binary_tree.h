#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template<typename T>
class BT
{
	public:
		T v;
		BT<T>* left;
		BT<T>* right;

	public:
		BT(const T& value)
		{
			this->v = value;
			this->left = nullptr;
			this->right = nullptr;
		}

		bool operator<(const BT& other) const
		{
			return this->value < other.value;
		}

		bool operator<=(const BT& other) const
		{
			return !(*this > other);
		}

		bool operator>(const BT& other) const
		{
			return this->value > other.value;
		}

		bool operator>=(const BT& other) const
		{
			return !(*this < other);
		}

		bool operator==(const BT& other) const
		{
			return this->value == other.value;
		}

		bool operator!=(const BT& other) const
		{
			return !(*this == other);
		}
}

#endif // BINARY_TREE_H
