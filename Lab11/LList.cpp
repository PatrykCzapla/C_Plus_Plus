//
//#include "LList.h"
//
//LList::LList()
//{
//	head = nullptr;
//	tail = nullptr;
//}
//
//LList::~LList()
//{
//	if (!isEmpty())
//	{
//		ListNode *current = head;
//		ListNode *temp;
//
//		while (current != tail)
//		{
//			temp = current;
//			current = current->next;
//			delete temp;
//		}
//		delete current;
//	}
//}
//
//void LList::insertBegin(int _data)
//{
//	if(isEmpty()) 
//	{
//		ListNode *new_node = new ListNode(_data); 
//		head = new_node; 
//		tail = new_node;
//		head->next = head;
//		head->prev = head;
//	}
//	else 
//	{
//		ListNode *new_node = new ListNode(_data);
//		head->prev = new_node;
//		new_node->next = head; 
//		new_node->prev = tail;
//		head = new_node; 
//	}
//}
//
//bool LList::isEmpty() const
//{
//	if (head == nullptr)
//		return 1;
//	else
//		return 0;
//}
//
//ostream& operator<<(ostream& out, const LList& l)
//{
//	l.print(out);
//	return out;
//}
//
//ostream& LList::print(ostream& out) const
//{
//	if (isEmpty())
//	{
//		cout << "Lista jest pusta" << endl;
//
//	}
//	else
//	{
//		ListNode *current = head;
//
//		out << "Zawartosc listy: " << endl;
//		while (current != tail)
//		{
//			out << current->data << ' ';
//			current = current->next;
//		}
//		out << current->data << endl;
//	}
//	return out;
//}
//void LList::insertEnd(int _data)
//{
//	if (isEmpty())
//	{
//		ListNode *new_node = new ListNode(_data);
//		head = new_node;
//		tail = new_node;
//		head->next = head;
//		head->prev = head;
//	}
//	else
//	{
//		ListNode *new_node = new ListNode(_data);
//		tail->next = new_node;
//		new_node->next = head;
//		new_node->prev = tail;
//		tail = new_node;
//	}
//}
//
//void LList::insertSorted(int _data)
//{
//	if (isEmpty())
//	{
//		ListNode *new_node = new ListNode(_data);
//		head = new_node;
//		tail = new_node;
//		head->next = head;
//		head->prev = head;
//	}
//	else if (head->data > _data)insertBegin(_data);
//	else if (tail->data <= _data)insertEnd(_data);
//	else
//	{
//		ListNode *new_node = new ListNode(_data);
//		ListNode *current = head;
//		while (new_node->data > current->data)
//		{
//			current = current->next;
//		}
//		new_node->next = current;
//		new_node->prev = current->prev;
//		new_node->prev->next = new_node;		
//		current->prev = new_node;
//	}
//}
