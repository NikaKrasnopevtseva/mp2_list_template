#ifndef __ASD_LIST__
#define __ASD_LIST__

#include <iostream>
#include <sstream>
#include <string>
#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
using namespace std;

template <typename DataType>
struct Node
{
	DataType data;
	Node<DataType>* next;

	Node(DataType d = 0, Node<DataType>* n = nullptr) {
		data = d; next = n;
	}
	Node(const Node<DataType>& node2) {
		data = node2.data;
		next = node2.next;
	}
	Node<DataType>& operator=(const Node<DataType>& node2) {
		if (this != &node2) {
			data = node2.data;
			next = node2.next;
		}
		return *this;
	}
	bool operator==(const Node<DataType>& node2) const {
		return (data == node2.data);
	}
	bool operator!=(const Node<DataType>& node2) const {
		return (data != node2.data);
	}
};

// example
// https://internalpointers.com/post/writing-custom-iterators-modern-cpp 

template <typename DataType>
class listIterator : public iterator<forward_iterator_tag, DataType>
{
public:
	using iterator_category = forward_iterator_tag;
	using difference_type = ptrdiff_t;
	using value_type = DataType;
	using pointer = Node<DataType>*;
	using reference = DataType&;

	listIterator(pointer tmp) : p(tmp) {};
	reference operator*() const { return *p; }; //
	pointer operator->() { return p; };
	const pointer operator->() const { return p; };
	listIterator& operator++() { p++; return *this; };// ���������� ��������
	listIterator operator++(int) { listIterator tmp = *this; ++(*this); return tmp; };// ����������� ��������
	friend bool operator==(const listIterator& it2, const listIterator& it1) { return it2.p == it1.p; }; //���������� ���������
	friend bool operator!=(const listIterator& it2, const listIterator& it1) { return it2.p != it1.p; };
private:
	pointer p;
};

template<typename DataType>
std::string toString(const DataType& value) {
	std::ostringstream os;
	os << value;
	return os.str();
}

template <typename DataType>
class List
{
	Node<DataType>* head;
public:
	List() : head(nullptr) {}; // ������� ������ ������
	List(const DataType& d) { head = new Node<DataType>(d, nullptr); }; // ������� ������ �� ������ �����
	bool isEmpty() const { return head == nullptr; };
	void InsertToHead(const DataType& d)	 // �������� ������� d ������
	{
		if (isEmpty())
		{
			head = new Node<DataType>(d, nullptr);
		}
		else
		{
			head = new Node<DataType>(d, head);
		}
	};
	DataType ViewHead() {	// ���������� �������
		if (isEmpty()) {
			throw ("������ ����");
		}
		return head->data;
	}; 
	void InsertToTail(const DataType& d)	 // �������� ������� d ���������
	{
		Node<DataType>* x = new Node<DataType>(d, nullptr);
		if (head == nullptr) 
			head = x;
		else {
			Node<DataType>* tmp;
			tmp = head;
			while (tmp->next != nullptr)
				tmp = tmp->next;
			tmp->next = x;
		}
	};
	DataType ViewTail() // ���������� ����������
	{
		if (isEmpty()) {
			throw ("������ ����");
		}
		Node<DataType>* tmp = head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		return tmp->data;

	};
	void Delete(const DataType& d)	// ������� ����� �� ��������� data = d	
	{

		if (isEmpty()) {
			throw ("������ ����");
		}
		Node<DataType>* tmp = head; 
		Node<DataType>* prev = nullptr;
		while ((tmp != nullptr) && (tmp->data != d))
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp != nullptr)
		{
			if (prev != nullptr)
			{
				prev->next = tmp->next;
			}
			else
			{
				head = head->next;
			}
			delete tmp;
		}
	}; 
	listIterator<DataType> begin() { return listIterator<DataType>(head); }; // �������� �������� �� ������ ����� 
	listIterator<DataType> tail() // �������� �������� �� ��������� �����
	{
		Node<DataType>* tmp = head;
		while (tmp->next != nullptr) 
		{
			tmp = tmp->next;
		}
		return listIterator<DataType>(tmp);
	}; 
	listIterator<DataType> end() { // �������� �������� �� ����� ������
		return listIterator<DataType>(nullptr);
	}; //���� ��������� c ��������� ������� �� return listIterator(head); ??
	~List()
	{
		if (head != nullptr)
		{
			Node<DataType>* tmp = head;
			while (tmp != nullptr)
			{
				Node<DataType>* next = tmp->next;
				delete tmp;
				tmp = next;
			}
		}
	};
	List(const List& list2)
	{
		if (!list2.isEmpty())
		{
			head = new Node<DataType>(list2.head->data, list2.head->next);
			Node<DataType>* tmp1 = head;
			Node<DataType>* tmp2 = list2.head->next;
			while (tmp2 != nullptr)
			{
				tmp1->next = new Node<DataType>(tmp2->data);
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			}
		}
		else
			head = nullptr;
	};
	List& operator=(const List& list2) noexcept
	{
		if (this != &list2)
		{
			Node<DataType>* p = head, * q = head;
			Clean();
			if (list2.isEmpty())
				head = nullptr;
			else
			{
				head = new Node<DataType>
					(list2.head->data);
				p = head;
				q = list2.head->next;
				while (q != nullptr)
				{
					p->next = new Node<DataType>(q->data);
					p = p->next;
					q = q->next;
				}
			}
		}
		return *this;
	};
	void Clean()// ������� ��� ������  
	{
		Node<DataType>* tmp = head;
		while (tmp != nullptr) {
			Node<DataType>* next = tmp->next;
			delete tmp;
			tmp = next;
		}
		head = nullptr;
	}; 
	void InsertAfter(const listIterator<DataType>& it, const DataType& d)// �������� ������� d ����� ����� node
	{
		if (it == nullptr)
			throw ("it ����� null.");
		Node<DataType>* prev = it.operator->();
		Node<DataType>* new_node = new Node<DataType>(d, nullptr);

		if (prev->next == nullptr) {
			prev->next = new_node;
			head = new_node;
		}
		else {
			new_node->next = prev->next;
			prev->next = new_node;
		}
	};
	listIterator<DataType> Search(const DataType& d) // ����� ��������� �� ����� �� ��������� data = d
	{
		if (isEmpty()) {
			throw ("������ ����");
		}
		Node<DataType>* tmp = head;
		while (tmp != nullptr) {
			if (tmp->data == d)
			{
				return listIterator<DataType>(tmp);
			}
			tmp = tmp->next;
		}
		return listIterator<DataType>(nullptr);
	};
	void Delete(const listIterator<DataType>& start, const listIterator<DataType>& finish)
	{
		Node<DataType>* tmp = head;
		Node<DataType>* prev = nullptr;
		while ((tmp != nullptr) && (tmp != start)) {
			prev = tmp;
			tmp = tmp->next;
		}
		Node<DataType>* f = finish->next;
		while (tmp != f) {
			Node<DataType>* del = tmp; 

			if (prev != nullptr) {
				prev->next = tmp->next; 
			}
			else {
				head = tmp->next;
			}
			tmp = tmp->next; 
			delete del;
		}
	};
	void DeleteAll(const DataType& d)
	{
		if (isEmpty()) {
			throw ("������ ����");
		}
		Node<DataType>* prev = nullptr;
		Node<DataType>* tmp = head;
		while (tmp != nullptr && tmp->data == d) {
			Node<DataType>* toDelete = tmp;
			head = head->next; 
			tmp = head; 
			delete toDelete; 
		}
		prev = head;
		tmp = head;
		while (tmp != nullptr) {
			if (tmp->data == d) {
				prev->next = tmp->next; 
				delete tmp;
				tmp = prev->next; 
			}
			else {
				prev = tmp; 
				tmp = tmp->next;
			}
		}
	};
	void Inverse()	// ������������� ������, �.�. ������ ������ ���� � �������� �������
	{
		Node<DataType>* newhead, * tmp;
		tmp = head->next;
		newhead = head;
		while (tmp != nullptr)
		{
			head->next = tmp->next;
			tmp->next = newhead;
			newhead = tmp;
			tmp = head->next;
		}
		head = newhead;
	}; 
	List Merge(const listIterator<DataType>& start, const List& list2) // ������� ������3, ������� ������2 � ������� ������ ����� ��������� 
	{
		/*List<DataType> list;
		Node<DataType>* tmp = head;
		while (tmp != start) {
			list.InsertToTail(tmp->data);
			tmp = tmp->next;
		}
		list.InsertToTail(tmp->data);
		Node<DataType>* tmp1 = tmp->next;
		tmp = list2.head;
		while (tmp != nullptr) {
			list.InsertToTail(tmp->data);
			tmp = tmp->next;
		}
		while (tmp1 != nullptr) {
			list.InsertToTail(tmp1->data);
			tmp1 = tmp1->next;
		}
		return list;*/
		List<DataType> list; 
		Node<DataType>* tmp = head;
		while (tmp != start) {
			Node<DataType>* newNode = new Node<DataType>(tmp->data);
			if (list.head == nullptr) {
				list.head = newNode; 
			}
			else {
				Node<DataType>* tmp1 = list.head;
				while (tmp1->next != nullptr) {
					tmp1 = tmp1->next; 
				}
				tmp1->next = newNode; 
			}
			tmp = tmp->next;
		}
		Node<DataType>* newNode = new Node<DataType>(tmp->data);
		if (list.head == nullptr) {
			list.head = newNode;
		}
		else {
			Node<DataType>* tmp1 = list.head;
			while (tmp1->next != nullptr) {
				tmp1 = tmp1->next;
			}
			tmp1->next = newNode;
		}
		Node<DataType>* node2 = list2.head;
		while (node2 != nullptr) {
			Node<DataType>* newNode = new Node<DataType>(node2->data);
			if (list.head == nullptr) {
				list.head = newNode;
			}
			else {
				Node<DataType>* tmp1 = list.head;
				while (tmp1->next != nullptr) {
					tmp1 = tmp1->next;
				}
				tmp1->next = newNode;
			}
			node2 = node2->next;
		}
		tmp = start->next;
		while (tmp != nullptr) {
			Node<DataType>* newNode = new Node<DataType>(tmp->data);
			if (list.head == nullptr) {
				list.head = newNode;
			}
			else {
				Node<DataType>* tmp1 = list.head;
				while (tmp1->next != nullptr) {
					tmp1 = tmp1->next;
				}
				tmp1->next = newNode;
			}
			tmp = tmp->next;
		}
		return list;
	}
	void MergeWith(const listIterator<DataType>& start, const List& list2) // � *this �������� ������2 ����� ���������
	{
		Node<DataType>* tmp = head;
		while (tmp != start) {
			tmp = tmp->next;
		}
		Node<DataType>* nexttmp = tmp->next;
		Node<DataType>* tmp1 = list2.head;
		while (tmp1 != nullptr) {
			Node<DataType>* newNode = new Node<DataType>(tmp1->data); 
			tmp->next = newNode;
			newNode->next = nexttmp;
			tmp = newNode;
			tmp1 = tmp1->next; 
		}
	};
	friend ostream& operator<<(ostream& os, const List<DataType>& l)
	{
	    Node<DataType>* tmp = l.head;
	    os << "List: ";
	    while (tmp != nullptr)
	    {
	        os << tmp->data << "; ";
	        tmp = tmp->next;
	   }
	    os << "\b";
	    return os;
	};
	void MadeUnique() // ��������� ������������� ������
	{
		Node<DataType>* tmp = head;
		Node<DataType>* prev = nullptr;
		while (tmp != nullptr)
		{
			Node<DataType>* run = head;
			bool repeat = false;
			while (run != tmp)
			{
				if (run->data == tmp->data)
				{
					repeat = true;
					break;
				}
				run = run->next;
			}
			if (repeat)
			{
				Node<DataType>* repeat = tmp;
				if (prev != nullptr)
				{
					prev->next = tmp->next;
				}
				else
				{
					head = tmp->next;
				}
				tmp = tmp->next;
				delete repeat;
			}
			else
			{
				prev = tmp;
				tmp = tmp->next;
			}
		}
	};
	std::string ToString()// "�� 1; ��2; " 
	{
		string str;
		Node<DataType>* tmp = head;
		while (tmp != nullptr)
		{
			str+=toString(tmp->data);
			str+=";";
			tmp = tmp->next;
		}
		if (str.empty()) 
			str = "������ ������";
		return str;
	}; 
	int GetSize() // ������ ����� ������� � ������
	{
		Node<DataType>* tmp = head;
		int size = 0;
		while (tmp != nullptr)
		{
			size++;
			tmp = tmp->next;
		}
		return size;
	}; 
	List Merge(const List& list2)	// ������� ������3, ������� � ����� �������� ������ ������2
	{
		List<DataType> list;
		Node<DataType>* tmp = head;
		while (tmp != nullptr) {
			list.InsertToTail(tmp->data);
			tmp = tmp->next;
		}
		tmp = list2.head;
		while (tmp != nullptr) {
			list.InsertToTail(tmp->data);
			tmp = tmp->next;
		}
		return list;
	}; 
	bool operator==(const List& list2) const // ������ �����, ���� �������� � ��� ���� � ���������� �������
	{
		if (isEmpty() && list2.isEmpty())
			return true;
		if (isEmpty() || list2.isEmpty())
			return false;
		Node<DataType>* tmp = head;
		Node<DataType>* tmp1 = list2.head;
		while (tmp != nullptr && tmp1 != nullptr) {
			if (tmp->data != tmp1->data) {
				return false;
			}
			tmp = tmp->next;
			tmp1 = tmp1->next;
		}
		return (tmp == nullptr && tmp1 == nullptr);
	};
	bool operator!=(const List& list2) const
	{
		return !(*this == list2);
	};
};
#endif
