#include<iostream>
using namespace std;

class Base {
public:
	Base() {
		cout << "Base::Base()" << endl;
	}
public:
	virtual void fun() {
		cout << "Base::fun()" << endl;
	}
	virtual void show() {
		cout << "Base::show()" << endl;
	}
private:
	char a = 'A';
	int b = 1;
};

class D :public Base {
public:
	D() {
		cout << "D::D()" << endl;
	}
public:
	void fun() {
		cout << "D::fun()" << endl;
	}
	virtual void list() {
		cout << "D::list()" << endl;
	}
private:
	int c = 2;
};

int main() {
	Base b;
	D d;
	return 0;
}

/*
class Base {
public:
	virtual void fun() {
		cout << "Base::fun()" << endl;
	}
};

class D :public Base {
public:
	void fun() {
		cout << "D::fun()" << endl;
	}
};

class C :public Base {
public:
	void fun() {
		cout << "C::fun()" << endl;
	}
};

//通过相同的接口实现不同的功能
void active(Base *pb) {
	pb->fun();
}
//void active(Base &pb) {
//	pb.fun();
//}

int main() {
	D d;
	active(&d);
	//C c;
	//active(c);
	return 0;
}*/