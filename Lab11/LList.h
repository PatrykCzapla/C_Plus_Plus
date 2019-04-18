#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include<fstream>
using namespace std;
#include "LListNode.h"
#include "Buntownik.h"

//class LList
//{
//public:
//	LList();
//	~LList();
//	void insertBegin(int);
//	void insertEnd(int);
//	void insertSorted(int);
//	bool isEmpty() const;
//	friend ostream& operator<<(ostream&, const LList&);
//protected:
//	ListNode *head;
//	ListNode *tail;
//	ostream& print(ostream&) const;
//};

template<class T>
class LList
{
public:
	LList()
	{
		head = nullptr;
		tail = nullptr;
	}
	~LList()
	{
		if (!isEmpty())
				{
					ListNode<T> *current = head;
					ListNode<T> *temp;
			
					while (current != tail)
					{
						temp = current;
						current = current->next;
						delete temp;
					}
					delete current;
				}
	}

	void insertBegin(T _data)
		{
			if (isEmpty())
			{
				ListNode<T> *new_node = new ListNode<T>(_data);
				head = new_node;
				tail = new_node;
				head->next = head;
				head->prev = head;
			}
			else
			{
				ListNode<T> *new_node = new ListNode<T>(_data);
				head->prev = new_node;
				new_node->next = head;
				new_node->prev = tail;
				head = new_node;
			}
		}
	void insertEnd(T _data) {
			if (isEmpty())
			{
				ListNode<T> *new_node = new ListNode<T>(_data);
				head = new_node;
				tail = new_node;
				head->next = head;
				head->prev = head;
			}
			else
			{
				ListNode<T> *new_node = new ListNode<T>(_data);
				tail->next = new_node;
				new_node->next = head;
				new_node->prev = tail;
				tail = new_node;
			}
		}
	void insertSorted(T _data)
		{
			if (isEmpty())
			{
				ListNode<T> *new_node = new ListNode<T>(_data);
				head = new_node;
				tail = new_node;
				head->next = head;
				head->prev = head;
			}
			else if (head->data > _data)insertBegin(_data);
			else if (tail->data <= _data)insertEnd(_data);
			else
			{
				ListNode<T> *new_node = new ListNode<T>(_data);
				ListNode<T> *current = head;
				while (new_node->data > current->data)
				{
					current = current->next;
				}
				new_node->next = current;
				new_node->prev = current->prev;
				new_node->prev->next = new_node;
				current->prev = new_node;
			}
		}
		bool isEmpty() const
		{
			if (head == nullptr)
				return 1;
			else
				return 0;
		}
		friend ostream& operator<<(ostream& out, const LList<T>& l)
		{
			l.print(out);
			return out;
		}
		void fromFile(string file_name)
		{
			ifstream wej(file_name);
			if (!wej)
			{
				cout << "Brak pliku!" << endl;
				return;
			}
			T l;
			while (!wej.eof())
			{
				wej >> l;
				if (wej.eof())return;
				insertSorted(l);
			}

		}
	protected:
		ListNode<T> *head;
		ListNode<T> *tail;
		ostream& print(ostream& out) const
		{
			if (isEmpty())
			{
				cout << "Lista jest pusta" << endl;

			}
			else
			{
				ListNode<T> *current = head;

				out << "Zawartosc listy: " << endl;
				while (current != tail)
				{
					out << current->data << ' ';
					current = current->next;
				}
				out << current->data << endl;
			}
			return out;
		}
};

#endif