#include <iostream>
using namespace std;

class Test {
public:
	Test() :m_data(0) {
		cout << "Test():" << this << endl;
	}
	~Test() {
		cout << "~Test():" << this << endl;
	}
private:
	int m_data;
};

void main(){
	//pt现在指向的只不过是与Test对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
	Test* pt = (Test*)malloc(sizeof(Test));
	new(pt) Test;//定位new  注：如果Test类的构造函数有参数时，此处需要传参
}

/*
struct ListNode {
	ListNode *_next;
	ListNode *_prev;
	int _data;
	void* operator new(size_t n) {
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);//allocator函数分配未初始化的存储
		cout << "menmory pool allocate" << endl;
		return p;
	}
	void operator delete(void* p) {
		allocator<ListNode>().deallocate((ListNode*)p, 1);//deallocate函数解分配存储
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
		ListNode * cur = _head->_next;
		while (cur != NULL) {
			ListNode * next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode *_head;
};

int main() {
	List l;
	return 0;
}*/

/*
void* operator new(size_t sz) {
	//要求：1.返回值必须是无类型指针  2.第一个参数必须是无类型整型参数
	void *ptr = malloc(sz);
	return ptr;
}

void operator delete(void *ptr) {
	free(ptr);
}

class Test {
public:
	Test() {
		cout << "Test::Test()" << endl;
	}
	~Test() {
		cout << "Test::~Test()" << endl;
	}
private:
	int m_data;
};
//new 操作符     new operator
//操作符 new     operator new

int main() {
	Test *pt = new Test;//先调度operator new申请空间  再调用构造函数
	delete pt;//先调用相关的析构函数，再释放相应的空间
	//Test *pt1 = (Test*)operator new(sizeof(Test));//只申请空间，不调动构造函数
	return 0;
}
*/