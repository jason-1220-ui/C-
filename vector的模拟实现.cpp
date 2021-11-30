#include<iostream>
#include<assert.h>
using namespace std;

namespace bit {
	template <class _Ty>
	class vector {
	public:
		typedef _Ty* iterator;
		typedef size_t size_type;
		typedef const _Ty* const_iterator;
	public:
		vector():_start(nullptr),_finish(nullptr),_end_of_storage(nullptr)
		{}
		vector(int n, const _Ty& value = _Ty()) 
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
			reserve(n);
			while (n--)
				push_back(value);
		}
		vector(const_iterator first, const_iterator last)
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
			reserve(last - first);
			while (first != last)
				push_back(*first++);
		}
		vector(const vector<_Ty> &v)
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
			reserve(v.capacity());
			for (int i = 0; i < v.size(); ++i)
				_start[i] = v[i];
			_finish = _start + v.size();
		}
		vector<_Ty>& operator=(const vector<_Ty> &v) {
			if (this != &v) {
				vector<_Ty> tmp = v;
				swap(tmp);
			}
			return *this;
		}
		~vector(){
			if (_start) {
				delete[]_start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}
	public:
		iterator begin() {
			return _start;
		}
		iterator end() {
			return _finish;
		}
		void push_back(const _Ty &x) {
			insert(end(), x);
		}
		void pop_back() {
			erase(end() - 1);
		}
	public:
		_Ty& operator[](size_t pos) {
			return _start[pos];
		}
		const _Ty& operator[](size_t pos)const {
			return _start[pos];
		}
		const _Ty& at(size_type pos)const {
			assert(pos >= 0 && pos < size());
			return _start[pos];
		}
		_Ty& at(size_type pos) {
			assert(pos >= 0 && pos < size());
			return _start[pos];
		}
	public:
		void reserve(size_type n) {
			if (n > capacity()) {
				size_type old_size = size();
				_Ty *new_start = new _Ty[n];
				for (int i = 0; i < old_size; ++i) {
					new_start[i] = _start[i];
				}
				delete[]_start;
				_start = new_start;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}
		}
		void resize(size_t n, const _Ty& value = _Ty()) {
			if (n <= size()) {
				_finish = _start + n;
				return;
			}
			if (n > capacity()) {
				reserve(n);
			}
			size_t offset = n - size();
			while (offset--) {
				*_finish++ = value;
			}
		}
	public:
		iterator insert(iterator pos, const _Ty&x) {
			if (_finish == _end_of_storage) {//如果相同，则说明空间已满
				size_t old_n = pos - _start;
				size_t new_size = capacity() == 0 ? 1 : 2 * capacity();
				reserve(new_size);
				//重新更新迭代器
				pos = _start + old_n;
			}
			iterator cur = end();
			while (cur != pos) {
				*cur = *(cur - 1);
				cur--;
			}
			*cur = x;
			_finish++;
			return cur;
		}
		iterator erase(iterator pos) {
			assert(pos >= _start && pos < _finish);
			iterator cur = pos;
			while (pos < _finish) {
				*pos = *(pos + 1);
				pos++;
			}
			--_finish;
			return cur;
		}
	public:
		size_t size()const {
			return _finish - _start;
		}
		size_t capacity()const{
			return _end_of_storage - _start;
		}
		bool empty()const {
			return size() == 0;
		}
	public:
		void swap(vector &str) {
			std::swap(_start, str._start);
			std::swap(_finish, str._finish);
			std::swap(_end_of_storage, str._end_of_storage);
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
};

//int main() {
//	int ar[] = { 1,2,3,4 };
//	bit::vector<int> iv(ar, ar + 4);
//	cout << "capacity=" << iv.capacity() << endl;
//	cout << "size=" << iv.size() << endl;
//	iv.resize(10);
//	cout << "capacity=" << iv.capacity() << endl;
//	cout << "size=" << iv.size() << endl;
//	iv.resize(3);
//	cout << "capacity=" << iv.capacity() << endl;
//	cout << "size=" << iv.size() << endl;
//	return 0;
//}

//int main() {
//	int ar[] = { 1,2,3,4,5 };
//	int br[] = { 6,7,8,9,10 };
//	bit::vector<int> iv(ar, ar + 5);
//	bit::vector<int> iv1(br, br + 5);
//	iv.swap(iv1);
//	bit::vector<int>::iterator it = iv.begin();
//	while (it != iv.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	it = iv1.begin();
//	while (it != iv1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}

//int main() {
//	int ar[] = { 1,2,3,4 };
//	bit::vector<int> v(ar, ar + sizeof(ar) / sizeof(int));
//	auto it = v.begin();
//	while (it != v.end()) {
//		if (*it % 2 == 0) {
//			it = v.erase(it);
//		}
//		else {
//			++it;
//		}
//	}
//	return 0;
//}

//int main() {
//	bit::vector<int> iv;
//	cout << iv.size() << endl;
//	cout << iv.capacity() << endl;
//	iv.push_back(1);
//	cout << iv.size() << endl;
//	cout << iv.capacity() << endl;
//
//	bit::vector<int>::iterator pos = iv.begin();
//	cout << *pos << endl;
//	iv.push_back(2);
//	cout << *pos << endl;
//	return 0;
//}

//int main() {
//	int ar[] = { 1,2,3,4,5 };
//	int n = sizeof(ar) / sizeof(ar[0]);
//	bit::vector<int> iv(ar, ar + n);
//	bit::vector<int>::iterator it = iv.begin();
//	for (const auto&e : iv)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}