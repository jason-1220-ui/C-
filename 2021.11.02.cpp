#include <iostream>
using namespace std;

//模板：将类型参数化的一个过程
//template<class Type>
template<typename Type>
void Swap(Type &a, Type &b) {
	cout << typeid(Type).name() << endl;
	Type tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int a = 10;
	int b = 20;
	Swap(a, b);

	char ch1 = 'A';
	char ch2 = 'B';
	Swap(ch1, ch2);
	return 0;
}

/*
void* operator new(size_t sz) {
	void *ptr = malloc(sz);
	return ptr;
}

void operator delete(void *ptr) {
	free(ptr);
}

void* operator new[](size_t sz) {
	void *ptr = malloc(sz);
	return ptr;
}

void operator delete[](void *ptr) {
	free(ptr);
}

class Test {
public:
	Test(int data = 0):m_data(data) {
		cout << "Test::Test()" << endl;
	}
	~Test() {
		cout << "Test::~Test()" << endl;
	}
public:
	void* operator new(size_t sz) {
		void *ptr = malloc(sz);
		return ptr;
	}
	void* operator new[](size_t sz) {
		void *ptr = malloc(sz);
		return ptr;
	}
	void *operator new(size_t sz, Test *pta) {
		return &pta[0];
	}
private:
	int m_data;
};

int main() {
	Test *pt = new Test;
	delete pt;
	Test *pta = new Test[10];
	new(pta)Test(1);
	delete []pta;
	int ar[10];
	new(ar)int(100);
	Test t;//实例化对象自动调用构造函数和析构函数的过程称为RAII（资源的获取即初始化）思想
	return 0;
}
*/