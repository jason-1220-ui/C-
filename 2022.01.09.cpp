#include<iostream>
using namespace std;

//ʵ�ֶ�̬������.
//1.����Ҫ���麯��2.����Ҫ��д������麯��3.����ʹ�ø����ָ��������õ����麯��
class Base {
public:
	//��̬��
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
	//��д�麯��Ҫ��:������ͬ��������ͬ������ֵ��ͬ
	void fun() {
		cout << "D::fun()" << endl;
	}
};

int main() {
	D d;
	Base *pb = &d;
	pb->fun();//��̬
	Base &rb = d;
	rb.fun();
	return 0;
}

/*
//��̬:����ͬ�Ľӿ�ʵ�ֲ�ͬ�Ĺ���
class A {
public:
	virtual void Eat() {//�麯��
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
//���μ̳�
class A {//�����
public:
	int m_a = 1;
};

class B :virtual public A {//��̳�
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

//static ��Ա
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

//��Ԫ���ܱ��̳�
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
	//ͬ������
	void fun() {
		cout << "D::fun()" << endl;
	}
};

int main() {
	Base b;
	D d;
	d.fun();//���õ�������ĳ�Ա����
	//d.fun(1);//���ܱ���
	d.Base::fun();//���õ��Ǹ�����޲γ�Ա����
	d.Base::fun(1);//���õ��Ǹ�����вγ�Ա����
	//���Ƽ��ݹ���
	b = d;
	Base *pb = &d;
	Base &rb = d;
	return 0;
}*/