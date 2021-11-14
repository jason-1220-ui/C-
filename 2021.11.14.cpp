#include <iostream>
using namespace std;

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
		//iterator 内部类
		class iterator{
		public:
			iterator() {
			}
			iterator(_Nodeptr _P) :_Ptr(_P){
			}
			~iterator() {
			}
		public:
			_Ty& operator*()const {
				return _Acc::_Value(_Ptr);
			}
			_Ty* operator->()const {
				return (&_Acc::_Value(_Ptr));
			}
			iterator& operator++() {
				_Ptr = _Acc::_Next(_Ptr);//_Ptr = _Ptr->_Next;
				return *this;
			}
			bool operator!=(const iterator &_X)const {
				return _Ptr != _X._Ptr;
			}
			bool operator==(const iterator &_X)const {
				//return !(*this != _X);
				return _Ptr == _X._Ptr;
			}
			_Nodeptr _Mynode()const {
				return _Ptr;
			}
		private:
			_Nodeptr _Ptr;
		};
	public:
		list() :_Head(_Buynode()), _Size(0)
		{}
	public:
		iterator begin() {
			return iterator(_Acc::_Next(_Head));
		}
		iterator end() {
			return iterator(_Head);
		}
	public:
		void push_front(const _Ty& _X) {
			insert(begin(), _X);
		}
		void push_back(const _Ty& _X) {
			/*_Nodeptr _S = _Buynode(_Head, _Acc::_Prev(_Head));
			_Acc::_Value(_S) = _X;
			_Acc::_Next(_Acc::_Prev(_S)) = _S;
			_Acc::_Prev(_Acc::_Next(_S)) = _S;
			_Size++;*/
			insert(end(), _X);
		}
	public:
		iterator insert(iterator _P, const _Ty& _X = _Ty()) {//零初始化
			_Nodeptr _S = _P._Mynode();
			_Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
			_S = _Acc::_Prev(_S);
			_Acc::_Next(_Acc::_Prev(_S)) = _S;
			_Acc::_Value(_S) = _X;
			++_Size;
			return (iterator(_S));
		}
	protected:
		_Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0) {
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

class Test {
public:
	Test(int data = 0) :m_data(data) {}
	void fun()const {
		cout << "This is Test::fun():" << m_data << endl;
	}
private:
	int m_data = 0;
};

int main() {
	bit_list::list<Test> mylist;
	Test t1(1);
	Test t2(2);
	Test t3(3);
	mylist.push_back(t1);
	mylist.push_back(t2);
	mylist.push_back(t3);
	bit_list::list<Test>::iterator it = mylist.begin();
	while (it != mylist.end()) {
		it->fun();
		++it;
	}
	/*bit_list::list<int> mylist;
	for (int i = 1; i <= 5; ++i)
		mylist.push_back(i);
	bit_list::list<int>::iterator it = mylist.begin();
	while (it != mylist.end()) {
		cout << *it << "->";
		++it;
	}
	cout << "Over." << endl;

	bit_list::list<int>::iterator pos = mylist.begin();
	++pos;
	mylist.insert(pos,10);
	for (auto &e : mylist)
		cout << e << "->";
	cout << "Over." << endl;*/
	return 0;
}