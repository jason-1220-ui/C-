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
	//pt����ָ���ֻ��������Test������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
	Test* pt = (Test*)malloc(sizeof(Test));
	new(pt) Test;//��λnew  ע�����Test��Ĺ��캯���в���ʱ���˴���Ҫ����
}

/*
struct ListNode {
	ListNode *_next;
	ListNode *_prev;
	int _data;
	void* operator new(size_t n) {
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);//allocator��������δ��ʼ���Ĵ洢
		cout << "menmory pool allocate" << endl;
		return p;
	}
	void operator delete(void* p) {
		allocator<ListNode>().deallocate((ListNode*)p, 1);//deallocate���������洢
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
	//Ҫ��1.����ֵ������������ָ��  2.��һ���������������������Ͳ���
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
//new ������     new operator
//������ new     operator new

int main() {
	Test *pt = new Test;//�ȵ���operator new����ռ�  �ٵ��ù��캯��
	delete pt;//�ȵ�����ص��������������ͷ���Ӧ�Ŀռ�
	//Test *pt1 = (Test*)operator new(sizeof(Test));//ֻ����ռ䣬���������캯��
	return 0;
}
*/