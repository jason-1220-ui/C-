#include <iostream>
using namespace std;
   
//类里面默认的6个函数
/*
class Test {
public:
	Test(int data = 0):m_data(data)//参数列表初始化
	{
		//m_data = data;
	}
	Test(const Test &t) {
		m_data = t.m_data;
	}
	Test& operator=(const Test &t) {
		if (this != &t)
			m_data = t.m_data;
		return *this;
	}
	~Test()
	{}
public:
	Test* operator&()
	{
		return this;
	}
	const Test* operator&()const
	{
		return this;
	}
private:
	int m_data;
};

void main() {
	const Test t;
	Test t1 = t;
	Test t2;
	t2 = t1;

	const Test *pt = &t;
}
*/

//class Person {
//public:
//	void PrintPerson() {
//		cout << _name << " " << _sex << " " << _age << endl;
//	}
//public:
//	const char* _name;
//	const char* _sex;
//	int _age;
//};
//
//int main() {
//	Person man;
//	man._name = "jack";
//	man._sex = "男";
//	man._age = 12;
//	man.PrintPerson();
//	return 0;
//}

//class Person {
//public:
//	void showInfo() {
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//private:
//	char* _name;
//	char* _sex;
//	int _age;
//};

/*//this指针
class Test {
public:
	//void SetData(Test *const this,int data)
	void SetData(int data) {
		m_data = data;
	}
	void GetData() {
		cout << m_data << endl;
	}
private:
	int m_data;
};
int main() {
	Test t1, t2;
	t1.SetData(10);
	t2.SetData(20);
	t1.GetData();
	t2.GetData();
	return 0;
}
*/