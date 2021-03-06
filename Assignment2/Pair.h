#pragma once
struct Pair
{
	int first, second;

	Pair(): first(0), second(0)
	{}

	Pair(int first, int second) :	first(first), second(second)
	{}
};

inline bool operator<(const Pair& lhs, const Pair& rhs)
{
    return lhs.first == rhs.first ?
        lhs.second < rhs.second : 
        lhs.first < rhs.first;	
}

inline bool operator>(const Pair& lhs, const Pair& rhs)
{
    return rhs < lhs;
}

inline bool operator<=(const Pair& lhs, const Pair& rhs)
{
	return !(rhs < lhs);
}

inline bool operator>=(const Pair& lhs, const Pair& rhs)
{
	return !(lhs < rhs);
}
