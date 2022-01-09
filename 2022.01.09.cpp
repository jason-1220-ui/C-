#include<iostream>
using namespace std;

//实现多态的条件.
//1.父类要有虚函数2.子类要重写父类的虚函数3.必须使用父类的指针或者引用调用虚函数
class Base {
public:
	//静态绑定
	virtual void fun() {
		cout << "Base::fun()" << endl;
	}
	void fun(int) {
		cout << "Base::fun(int)" << endl;
	}
	void show() {
		cout << "Base::show()" << endl;
	}
};

class D :public Base {
public:
	//重写虚函数要求:名字相同、参数相同、返回值相同
	void fun() {
		cout << "D::fun()" << endl;
	}
};

int main() {
	D d;
	Base *pb = &d;
	pb->fun();//多态
	Base &rb = d;
	rb.fun();
	return 0;
}

/*
//多态:以相同的接口实现不同的功能
class A {
public:
	virtual void Eat() {//虚函数
		cout << "A::Eat" << endl;
	}
	virtual void Sleep() {
		cout << "A::Sleep" << endl;
	}
	virtual void Foot() {
		cout << "A::Foot" << endl;
	}
};

class Dog :public A {
public:
	void Eat() {
		cout << "Dog::Eat" << endl;
	}
	void Sleep() {
		cout << "Dog::Sleep" << endl;
	}
	void Foot() {
		cout << "Dog::Foot" << endl;
	}
};

class Person :public A {
public:
	void Eat() {
		cout << "Person::Eat" << endl;
	}
	void Sleep() {
		cout << "Person::Sleep" << endl;
	}
	void Foot() {
		cout << "Person::Foot" << endl;
	}
};

void Active(A *pa) {
	pa->Eat();
	pa->Sleep();
	pa->Foot();
}

int main() {
	A a;
	Active(&a);

	Dog dog;
	Active(&dog);
	return 0;
}*/

/*
//菱形继承
class A {//虚基类
public:
	int m_a = 1;
};

class B :virtual public A {//虚继承
public:
	int m_b = 2;
};

class C :virtual public A {
public:
	int m_c = 3;
};

class D :public B, public C {
public:
	int m_d = 4;
};

int main() {
	D d;
	cout << d.m_d << endl;
	cout << d.m_b << endl;
	cout << d.m_c << endl;
	cout << d.m_a << endl;
	cout << d.B::m_a << endl;
	cout << d.C::m_a << endl;
	return 0;
}*/

//static 成员
/*
class Base {
public:
	static int m_base;
};
int Base::m_base = 0;

class A :public Base {
public:
	int m_a = 1;
};

class B :public Base {
public:
	int m_b = 2;
};

int main() {
	A a;
	B b;
	cout << "a.m_base = " << a.m_base << endl;
	cout << "b.m_base = " << b.m_base << endl;
	a.m_base = 10;
	cout << "a.m_base = " << a.m_base << endl;
	cout << "b.m_base = " << b.m_base << endl;
	return 0;
}*/

/*
class A;
class B;
class Base {
	friend class A;
	friend class B;
private:
	int m_base = 0;
};

class A {
public:
	A(int a = 0) :m_a(a) 
	{}
public:
	void List(Base &b)const {
		cout << b.m_base << endl;
	}
private:
	int m_a;
};

class B :public A {
public:
	B(int b) :m_b(b) 
	{}
public:
	void Show(Base &a)const {
		cout << a.m_base << endl;
	}
private:
	int m_b;
};

//友元不能被继承
int main() {
	A a(10);
	Base base;
	a.List(base);
	B b(1);
	b.Show(base);
	return 0;
}*/

/*
class Base {
public:
	void fun() {
		cout << "Base::fun()" << endl;
	}
	void fun(int a) {
		cout << "Base::fun(int)" << endl;
	}
};

class D :public Base {
public:
	//同名隐藏
	void fun() {
		cout << "D::fun()" << endl;
	}
};

int main() {
	Base b;
	D d;
	d.fun();//调用的是子类的成员方法
	//d.fun(1);//不能编译
	d.Base::fun();//调用的是父类的无参成员方法
	d.Base::fun(1);//调用的是父类的有参成员方法
	//复制兼容规则
	b = d;
	Base *pb = &d;
	Base &rb = d;
	return 0;
}*/