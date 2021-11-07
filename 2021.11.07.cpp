#include <iostream>
using namespace std;

template<typename Type>//类模板  不能分离编译
class SeqList {
public:
	SeqList(int sz) {
		capacity = sz;
		base = new Type[capacity];
		size = 0;
	}
	~SeqList() {
		delete[]base;
		base = nullptr;
		capacity = size = 0;
	}
public:
	void push_back(const Type &x);
	void show()const;
private:
	Type *base;
	size_t capacity;
	size_t size;
};

template<typename Type>
void SeqList<Type>::push_back(const Type &x) {
	base[size++] = x;
}

template<typename Type>
void SeqList<Type>::show()const {
	for (int i = 0; i < size; ++i) {
		cout << base[i] << " ";
	}
	cout << endl;
}

class Test
{};

int main() {
	SeqList<int> lt1(10);
	SeqList<char> lt2(10);
	SeqList<Test> lt3(10);
	
	return 0;
}

/*
//函数模板-->模板函数
template<typename Type>
Type Sum(Type a, Type b) {
	return a + b;
}
int main() {
	cout << Sum(10, 20) << endl;
	cout << Sum('A', 'B') << endl;
	cout << Sum(1.2, 2.3) << endl;
	cout << Sum(10, (int)12.34) << endl;
	cout << Sum((double)10, 12.34) << endl;
	cout << Sum<int>(10, 12.34) << endl;
	return 0;
}
*/