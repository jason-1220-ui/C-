#include<iostream>
#include<assert.h>
using namespace std;

namespace bite{
	// List的节点类
	template<class T>
	struct ListNode{
		ListNode(const T& val = T()) :_pPre(nullptr),_pNext(nullptr),_val(val)
		{}
		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};
	//List的迭代器类
	template<class T>
	class list;
	template<class T, class Ref, class Ptr>
	class ListIterator{
		friend class list<T>;
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode = nullptr):_pNode(nullptr)
		{}
		ListIterator(const Self& l):_pNode(l._pNode)
		{}
		T& operator*() {
			return _pNode->_val;
		}
		T* operator->() {
			return &*this;
		}
		Self& operator++() {
			_pNode = _pNode->_pNext;
			return *this;
		}
		Self operator++(int) {
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}
		Self& operator--() {
			_pNode = _pNode->_pPre;
			return *this;
		}
		Self& operator--(int) {
			Self temp(*this);
			_pNode = _pNode->_pPre;
			return temp;
		}
		bool operator!=(const Self& l) {
			return _pNode != l._pNode;
		}
		bool operator==(const Self& l) {
			return !(*this != l);
		}
	private:
		PNode _pNode;
	};
	//list类
	template<class T>
	class list{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T&> const_iterator;
	public:
		///////////////////////////////////////////////////////////////
		// list的构造
		list(){
			CreateHead();
		}
		list(int n, const T& value = T()) {
			CreateHead();
			for (int i = 0; i < n; ++i)
				push_back(value);
		}
		template <class Iterator>
		list(Iterator first, Iterator last) {
			CreateHead();
			while (first != last) {
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& l) {
			CreateHead();
			list<T> temp(l.cbegin(), l.cend());
			this->swap(temp);
		}
		list<T>& operator=(const list<T> l) {
			this->swap(l);
			return *this;
		}
		~list() {
			clear();
			delete _pHead;
			_pHead = nullptr;
		}
		///////////////////////////////////////////////////////////////
		// list Iterator
		iterator begin(){
			return iterator(_pHead->_pNext);
		}
		iterator end(){
			return iterator(_pHead);
		}
		const_iterator begin() const{
			return const_iterator(_pHead->_pNext);
		}
		const_iterator end() const {
			return const_iterator(_pHead);
		}
		///////////////////////////////////////////////////////////////
		// List Capacity
		size_t size()const {
			size_t size = 0;
			PNode p = _pHead->_pNext;
			while (p != _pHead) {
				size++;
				p = p->_pNext;
			}
			return size;
		}
		bool empty()const {
			return size() == 0;
		}
		////////////////////////////////////////////////////////////
		// List Access
		T& front() {
			assert(!empty());
			return _pHead->_pNext->_val;
		}
		const T& front()const {
			assert(!empty());
			return _pHead->_pNext->_val;
		}
		T& back() {
			assert(!empty());
			return _pHead->_pPre->_val;
		}
		const T& back()const {
			assert(!empty());
			return _pHead->_pPre->_val;
		}
		////////////////////////////////////////////////////////////
		// List Modify
		void push_back(const T& val) 
		{ insert(begin(), val); }
		void pop_back() 
		{ erase(--end()); }
		void push_front(const T& val) 
		{ insert(begin(), val); }
		void pop_front() 
		{ erase(begin()); }
		// 在pos位置前插入值为val的节点
		iterator insert(iterator pos, const T& val) {
			PNode pNewNode = new Node(val);
			PNode cur = pos._pNode;
			//插入新节点
			pNewNode->_pPre = cur->_pPre;
			pNewNode->_pNext = cur;
			
			pNewNode->_pPre->_pNext = pNewNode;
			cur->_pPre = pNewNode;
			return iterator(pNewNode);
		}
		// 删除pos位置的节点，返回该节点的下一个位置
		iterator erase(iterator pos) {
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;
			pDel->_pPre->_pNext = pDel->_pNext;
			pDel->_pNext->_pPre = pDel->_pPre;
			delete pDel;
			return iterator(pRet);
		}
		void clear() {
			iterator p = begin();
			while (p != end()) {
				p = erase(p);
			}
		}
		void swap(list<T>& l) {
			PNode tmp = _pHead;
			_pHead = l._pHead;
			l._pHead = tmp;
		}
	private:
		void CreateHead() {
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
		PNode _pHead;
	};
};

int main() {
	bite::list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);
	bite::list<int>::iterator it = mylist.begin();
	while (it != mylist.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	return 0;
}