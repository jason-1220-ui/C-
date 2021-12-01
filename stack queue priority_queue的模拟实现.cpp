#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

namespace bit {
	template<class T, class Cont = vector<T>, class Pred = less<T>>
	class priority_queue {
		typedef size_t size_type;
	public:
		priority_queue()
		{}
		priority_queue(const T *frist, const T *last) {
			while (frist != last)
				c.push_back(*frist++);
			int curpos = c.size() / 2 - 1;
			while (curpos >= 0) {
				_AdjustDown(curpos);
				curpos--;
			}
		}
	public:
		bool empty()const {
			return c.empty();
		}
		size_type size()const {
			return c.size();
		}
		void push(const T& x) {
			c.push_back(x);
			_AdjustUp(c.size() - 1);
		}
		void pop() {
			c[0] = c[c.size() - 1];
			c.pop_back();
			_AdjustDown(0);
		}
		T& top() {
			return c.front();
		}
	public:
		void Show()const {
			for (int i = 0; i < c.size(); ++i)
				cout << c[i] << " ";
			cout << endl;
		}
	protected:
		void _AdjustUp(int start) {
			int j = start;
			int i = (j - 1) / 2;
			while (j > 0) {
				if (c[i] < c[j]) {
					T tmp = c[i];
					c[i] = c[j];
					c[j] = tmp;

					j = i;
					i = (j - 1) / 2;
				}
				else
					break;
			}
		}
		void _AdjustDown(int start) {
			int i = start;
			int j = 2 * i + 1;
			while (j < c.size()) {
				if (j + 1 < c.size() && c[j] < c[j + 1]) {
					j++;
				}
				if (c[i] < c[j]) {
					T tmp = c[i];
					c[i] = c[j];
					c[j] = tmp;
					i = j;
					j = 2 * i + 1;
				}
				else {
					break;
				}
			}
		}
	private:
		Cont c;
		Pred comp;
	};
};

int main() {
	bit::priority_queue<int> pq;
	vector<int> v = { 3,2,7,6,0,4,1,9,8,5 };
	for (const auto &e : v)
		pq.push(e);
	pq.Show();

	pq.pop();
	pq.Show();
	return 0;
}

/*
//优先队列的模拟实现
namespace bit {
	template<class T, class Cont = vector<T>,class Pred =less<T>>
	class priority_queue {
		typedef size_t size_type;
	public:
		priority_queue()
		{}
		priority_queue(const T *frist,const T *last){
			while (frist != last)
				c.push_back(*frist++);
			make_heap(c.begin(), c.end());
		}
	public:
		bool empty()const {
			return c.empty();
		}
		size_type size()const {
			return c.size();
		}
		void push(const T& x) {
			c.push_back(x);
			push_heap(c.begin(), c.end());
		}
		void pop() {
			pop_heap(c.begin(), c.end());
			c.pop_back();
		}
		T& top() {
			return c.front();
		}
	private:
		Cont c;
		Pred comp;
	};
};

int main() {
	int ar[] = { 3,1,4,2,7,5,6,9 };
	int n = sizeof(ar) / sizeof(ar[0]);
	priority_queue<int> pq(ar, ar + n);

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}*/

//int main() {
//	bit::priority_queue<int> pq;
//	pq.push(8);
//	pq.push(2);
//	pq.push(5);
//	pq.push(7);
//	pq.pop();
//	cout << pq.top() << endl;
//	return 0;
//}

//greater是仿函数，在类里重载了()，使其用起来像函数，但并不同于函数
/*
int main() {
	vector<int> v = { 3,1,4,2,7,5,6,9 };
	priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}*/

/*
int main() {
	int ar[15]= { 3,2,7,6,0,4,1,9,8,5 };
	//int n = sizeof(ar) / sizeof(ar[0]);
	int n = 10;
	for (int i = 0; i < n; ++i)
		cout << ar[i] << " ";
	cout << endl;
	make_heap(ar, ar + n);//把数组变成堆结构
	//9 8 7 6 5 4 1 3 2 0 10
	ar[n] = 10;
	n++;
	push_heap(ar, ar + n);
	int tmp = ar[0];
	ar[0] = ar[n - 1];
	ar[n - 1] = tmp; 
	n--;
	pop_heap(ar, ar + n);
	for (int i = 0; i < n; ++i)
		cout << ar[i] << " ";
	cout << endl;
	
	return 0;
}*/

/*
//队列的模拟实现
namespace bit{
	template<class T, class Cont = deque<T>>
	class queue {
	public:
		typedef size_t size_type;
		typedef T      value_type;
	public:
		queue(){}
		bool empty()const {
			return c.empty();
		}
		size_type size()const {
			return c.size();
		}
		value_type& front() {
			return c.front();
		}
		const value_type& back()const {
			return c.back();
		}
		void push(const value_type& x) {
			c.push_back(x);
		}
		void pop() {
			c.pop_front();
		}
	private:
		Cont c;
	};
};

int main() {
	bit::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << "size = " << q.size() << endl;
	cout << "empty = " << q.empty() << endl;
	cout << "front value = " << q.front() << endl;
	cout << "back value = " << q.back() << endl;
	while (!q.empty()) {
		cout << q.front() << "出栈" << endl;
		q.pop();
	}
	return 0;
}*/

/*
//栈的模拟实现
namespace bit {
	template<class T,class Cont = deque<T>>
	class stack {
	public:
		typedef size_t size_type;
		typedef T      value_type;
	public:
		stack(){}
		bool empty()const {
			return c.empty();
		}
		size_type size()const {
			return c.size();
		}
		value_type& top() {
			return c.back();
		}
		const value_type& top()const {
			return c.back();
		}
		void push(const value_type& x) {
			c.push_back(x);
		}
		void pop() {
			c.pop_back();
		}
	protected:
		Cont c;
	};
};

int main() {
	bit::stack<int,list<int>> st;
	cout << "empty = " << st.empty() << endl;
	cout << "size = " << st.size() << endl;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	cout << "empty = " << st.empty() << endl;
	cout << "size = " << st.size() << endl;
	cout << "top value = " << st.top() << endl;
	/*st.pop();
	cout << "empty = " << st.empty() << endl;
	cout << "size = " << st.size() << endl;*/
	/*
	while (!st.empty()) {
		cout << st.top() << "出栈" << endl;
		st.pop();
	}
	return 0;
}*/

/*
int main() {
	deque<int> dq;

	dq.push_front(1);
	dq.push_front(2);
	dq.push_front(3);
	dq.push_back(4);
	dq.push_back(5);
	dq.push_back(6);

	cout << dq.at(3) << endl;

	for (const auto &e : dq)
		cout << e << " ";
	cout << endl;
	
	deque<int>::iterator it = dq.begin();
	while (it != dq.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	return 0;
}*/