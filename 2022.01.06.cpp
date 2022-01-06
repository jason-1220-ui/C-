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
	//复制兼容规则
	//1.子类对象可以给父类赋值
	b = d;
	//2.子类对象的地址可以给父类指针赋值
	Base *pb = &d;
	//3.子类对象可以初始化父类的引用
	Base &rd = d;
	return 0;
}

/*
//多继承
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
	D d;//实例化一个子类对象时，先实例化一个父类对象在实例化子类对象
	return 0;
}*/

/*
//保护继承
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

// 保护继承，会将父类中的成员方法的属性缩小，即公有成员会变成保护成员，私有成员属性不变
class D : protected Base {
public:
	void list() {
		cout << "D::list()" << endl;
		fun();
		show();
		//print();
		myfun();//能够访问自己的私有成员方法
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
//公有继承
//站在对象的角度，只能访问父类的公有成员
//站在子类的角度，只能访问父类的公有成员和保护成员
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
		//print();//子类中不能直接访问父类中的私有方法
	}
};

int main() {
	D d;
	d.fun();
	//d.show();//对象不能调用父类中的保护方法，但可直接在子类中访问
	d.list();
	return 0;
}*/

/*
//父类（基类）
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
//子类（派生类）
class D : public Base{//继承的语法
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