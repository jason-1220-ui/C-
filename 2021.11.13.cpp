#include <iostream>
#include<list>
using namespace std;

struct ListNode {
	ListNode* _next;
	ListNode* _prev;
	int _data;
	void* operator new(size_t n) {
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}
	void operator delete(void* p) {
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};

class List {
public:
	List() {
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List() {
		ListNode* cur = _head->_next;
		while (cur != _head) {
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};
int main() {
	List l;
	return 0;
}

/*
namespace bit_list {
	template<typename _Ty>
	class list {
	public:
		struct _Node;
		typedef struct _Node* _Nodeptr;
		struct _Node {
			_Nodeptr _Next, _Prev;
			_Ty _Value;
		};
		struct _Acc {
			typedef struct _Node*& _Nodepref;
			typedef _Ty& _Vref;
			static _Nodepref _Next(_Nodeptr _P) {
				return _P->_Next;
			}
			static _Nodepref _Prev(_Nodeptr _P) {
				return _P->_Prev;
			}
			static _Vref _Value(_Nodeptr _P) {
				return _P->_Value;
			}
		};
		typedef size_t size_type;
	public:
		list() :_Head(_Buynode()), _Size(0) 
		{}
	public:
		void push_back(const _Ty& _X) {
			_Nodeptr _S = _Buynode(_Head, _Acc::_Prev(_Head));
			_Acc::_Value(_S) = _X;
			_Acc::_Next(_Acc::_Prev(_S)) = _S;
			_Acc::_Prev(_Acc::_Next(_S)) = _S;
			_Size++;
		}
	protected:
		_Nodeptr _Buynode(_Nodeptr _Narg = 0,_Nodeptr _Parg = 0) {
			_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
			_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
			_Acc::_Prev(_S) = _Parg != 0 ? _Parg : _S;
			return _S;
		}
	private:
		_Nodeptr _Head;
		size_type _Size;
	};
};

int main() {
	bit_list::list<int> mylist;
	for (int i = 1; i <= 5; ++i)
		mylist.push_back(i);
	return 0;
}*/

/*
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	list<int> mylist(arr, arr + n);

	mylist.push_front(20);
	mylist.push_back(12);
	mylist.pop_front();
	mylist.pop_back();

	cout << "empty = " << mylist.empty() << endl;
	cout << "size = " << mylist.size() << endl;
	cout << "front = " << mylist.front() << endl;
	cout << "back = " << mylist.back() << endl;

	for (const auto &e : mylist)
		cout << e << " ";
	cout << endl;
	return 0;
}*/

/*
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	list<int> mylist(arr, arr + n);

	for (const auto &e : mylist)
		cout << e << " ";
	cout << endl;

	list<int>::iterator it = mylist.begin();
	while (it != mylist.end()) {//end返回的是最后一个元素的下一个位置的迭代器
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int>::reverse_iterator rit = mylist.rbegin();
	while (rit != mylist.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	return 0;
}
*/