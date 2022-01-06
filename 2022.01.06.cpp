#include<iostream>
using namespace std;

class Base {
public:
	void fun() {
		cout << "Base::fun()" << endl;
	}
private:
	int m_base;
};

class D : public Base {
public:
	void fun1() {
		cout << "D::fun1()" << endl;
	}
private:
	int m_a;
	int m_b;
};

int main() {
	Base b;
	D d;
	//���Ƽ��ݹ���
	//1.���������Ը����ำֵ
	b = d;
	//2.�������ĵ�ַ���Ը�����ָ�븳ֵ
	Base *pb = &d;
	//3.���������Գ�ʼ�����������
	Base &rd = d;
	return 0;
}

/*
//��̳�
class Base {
public:
	Base() {
		cout << "Base::Base()" << endl;
	}
	~Base() {
		cout << "Base::~Base()" << endl;
	}
private:
	int m_a;
};

class Base1 {
public:
	Base1() {
		cout << "Base1::Base1()" << endl;
	}
	~Base1() {
		cout << "Base1::~Base1()" << endl;
	}
private:
	int m_a1;
};

class D : public Base1,public Base {
public:
	D() {
		cout << "D::D()" << endl;
	}
	~D() {
		cout << "D::~D()" << endl;
	}
private:
	int m_b;
};

int main() {
	D d;//ʵ����һ���������ʱ����ʵ����һ�����������ʵ�����������
	return 0;
}*/

/*
//�����̳�
class Base {
public:
	void fun() {
		cout << "Base::fun()" << endl;
	}
protected:
	void show() {
		cout << "Base::show()" << endl;
	}
private:
	void print() {
		cout << "Base::print()" << endl;
	}
private:
	int a;
	int b;
};

// �����̳У��Ὣ�����еĳ�Ա������������С�������г�Ա���ɱ�����Ա��˽�г�Ա���Բ���
class D : protected Base {
public:
	void list() {
		cout << "D::list()" << endl;
		fun();
		show();
		//print();
		myfun();//�ܹ������Լ���˽�г�Ա����
	}
private:
	void myfun() {
		cout << "D::myfun()" << endl;
	}
};

int main() {
	D d;
	//d.fun();
	d.list();
	return 0;
}*/

/*
//���м̳�
//վ�ڶ���ĽǶȣ�ֻ�ܷ��ʸ���Ĺ��г�Ա
//վ������ĽǶȣ�ֻ�ܷ��ʸ���Ĺ��г�Ա�ͱ�����Ա
class Base {
public:
	void fun() {
		cout << "Base::fun()" << endl;
	}
protected:
	void show() {
		cout << "Base::show()" << endl;
	}
private:
	void print() {
		cout << "Base::print()" << endl;
	}
private:
	int a;
	int b;
};

class D : public Base {
public:
	void list() {
		cout << "D::list()" << endl;
		show();
		//print();//�����в���ֱ�ӷ��ʸ����е�˽�з���
	}
};

int main() {
	D d;
	d.fun();
	//d.show();//�����ܵ��ø����еı�������������ֱ���������з���
	d.list();
	return 0;
}*/

/*
//���ࣨ���ࣩ
class Base {
public:
	void fun() {
		cout << "Base::fun()" << endl;
	}
protected:
	void show() {
		cout << "Base::show()" << endl;
	}
private:
	int a;
	int b;
};
//���ࣨ�����ࣩ
class D : public Base{//�̳е��﷨
public:
	void list() {
		cout << "D::list()" << endl;
	}
};

int main() {
	D d;
	d.fun();
	d.list();
	return 0;
}*/