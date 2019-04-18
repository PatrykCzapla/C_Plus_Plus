#ifndef LLIST_NODE_H
#define LLIST_NODE_H
#include <iostream>
using namespace std;

template<class T>
class LList;


template<class T>
class ListNode
{
	friend class LList<T>;

public:
	ListNode(T _data)
	{
		data = _data;
		next = nullptr;
		prev = nullptr;
	}
	

private:
	T data;
	ListNode* next;
	ListNode* prev;
	friend ostream& operator<<(ostream& out, const ListNode<T>& ln)
	{
		out << ln.data;
		return out;
	}
};

#endif