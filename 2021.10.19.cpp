#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Test {
	friend void fun(const Test &t);
public:
	Test(int data = 0) {
		m_data = data;
	}
	Test(const Test &t) {
		m_data = t.m_data;
	}
	Test& operator=(const Test &t) {
		if (this != &t) {
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{}
public:
	Test* operator&() {//普通地址取地址符
		return this;
	}
	const Test* operator&()const {//常对象取地址符
		return this;
	}
private:
	int m_data;
};
void main() {
	Test t1(10);
	Test t2 = t1;
	Test t3;
	t3 = t2;

	Test *pt = &t1;
	const Test *pt1 = &t2;
}

/*
class Complex {
public:
	Complex(int real, int image):m_real(real),m_imag(image)//参数列表的初始化方式
	{}
	~Complex()
	{}
public:
	friend Complex operator+(int value, const Complex &x);
	friend ostream& operator<<(ostream &out, const Complex &x);//重载运算符的输出
public:
	//复数的加减运算
	Complex operator+(const Complex &c) {
		return Complex(m_real + c.m_real, m_imag + c.m_imag);
	}
	Complex operator-(const Complex &c) {
		return Complex(m_real - c.m_real, m_imag - c.m_imag);
	}
private:
	int m_real;
	int m_imag;
};
Complex operator+(int value, const Complex &x) {
	return Complex(value + x.m_real, x.m_imag);
}
ostream& operator<<(ostream &out, const Complex &x) {
	out << "(" << x.m_real << "," << x.m_imag << ")";
	return out;
}
void main() {
	Complex c1(1, 2);
	Complex c2(3, 4);
	Complex c = c1 + c2;
	//按照友元方式进行，即可执行代码
	Complex d = 10 + c1;

	cout << c << endl;//重载运算符的输出
	//operator<<(cout, c1);
}
*/

/*
class MyInt;
ostream& operator<<(ostream &out, const MyInt &t);
class MyInt {
	friend ostream& operator<<(ostream &out, const MyInt &t);
public:
	MyInt(int i = 0) {
		m_i = i;
	}
public:
	//a + b ，a通过this指针传递，所以此处传一个参数即可
	MyInt operator+(const MyInt &x) {
		/*MyInt tmp(data);
		return tmp;*/
		/*return MyInt(m_i + x.m_i);
	}
public:
	MyInt& operator+=(const MyInt &x) {//MyInt后面的引号是因为返回的this指针不受作用域的影响 
		m_i += x.m_i;
		return *this;
	}
public://逻辑运算符的重载
	bool operator>(const MyInt &x) {
		return this->m_i > x.m_i;
	}
	bool operator<=(const MyInt &x) {
		return !(*this > x);
		//return m_i <= x.m_i;
	}
	bool operator<(const MyInt &x) {
		return m_i < x.m_i;
	}
	bool operator>=(const MyInt &x) {
		return !(*this < x);
	}
	bool operator==(const MyInt &x) {
		return m_i == x.m_i;
	}
	bool operator!=(const MyInt &x) {
		return m_i != x.m_i;
	}
public:
	MyInt& operator++()//前++
	{
		m_i++;
		return *this;
	}
	MyInt operator++(int)//后++   
	//给参数是为了避免与前++发生重载，有没有参数名无所谓，因为在执行中该参数不参与执行
	{
		MyInt tmp = *this;
		m_i++;
		return tmp;
	}
	MyInt& operator--()//前--
	{
		m_i--;
		return *this;
	}
	MyInt& operator--(int)//后--
	{
		MyInt tmp = *this;
		m_i--;
		return tmp;
	}
private:
	int m_i;
};
ostream& operator<<(ostream &out, const MyInt &t) {
	out << t.m_i;
	return out;
}
void main() {
	MyInt a = 10;
	MyInt b = 20;
	MyInt c;
	c = a + b;

	a += b;
	cout << "c = " << c << endl;
	cout << "a = " << a << endl;

	if (a > b) 
		cout << "a>b" << endl;
	else 
		cout << "a<=b" << endl;

	MyInt x = ++a;
	cout << a << endl;
	MyInt y = b++;
	cout << b << endl;

	MyInt n = --a;
	cout << a << endl;
	MyInt m = b--;
	cout << b << endl;
}
*/

/*
class Test;
ostream& operator<<(ostream &out, const Test &t);

class Test {
	friend ostream& operator<<(ostream &out, const Test &t);
public:
	Test(int data = 0) {
		m_data = data;
	}
	Test(const Test &t) {
		m_data = t.m_data;
	}
	~Test() 
	{}
private:
	int m_data;
};

ostream& operator<<(ostream &out, const Test &t) {
	out << t.m_data;
	return out;
}

void main() {
	Test t(100);
	cout << "t = " << t << endl;
}
*/

/*
class String {
public:
	String(const char *str = "") {
		if (str == nullptr)
			m_data = nullptr;
		else {
			//int len = sizeof(str);
			m_data = (char*)malloc(strlen(str) + 1);//1 是"\0"
			//m_data = (char*)malloc(sizeof(str));//不能用sizeof是因为sizeof里面传的str是指针，无论主函数中是多少个字符串，均打印4个字节
			strcpy(m_data, str);
		}
	}
	String(const String &s) {
		m_data = s.m_data;
	}
	//异常不安全
	String& operator=(const String &s) {//s2刚开始可能有自己指向的空间，若不释放原有空间，则会发生内存泄漏
		//深拷贝
		if (this != &s) {
			free(m_data);
			m_data = (char*)malloc(strlen(s.m_data) + 1);
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String() {
		free(m_data);
		m_data = nullptr;
	}
	void Show()const {
		cout << m_data << endl;
	}
private:
	char *m_data;
};
void main() {
	String s1("abc");
	String s2("xyz");
	s2 = s1;
}
*/

/*
int main() {
	String s("abcxyz");
	s.Show();

	String s1 = s;
	String s2;
	s2 = s1;

	String str(nullptr);
}
*/
/*
class Test {
public:
	void SetData(int data) {
		m_data = data;
	}
	//int GetData(const Test * const this)
	int GetData()const {//常方法
		this->Show();//常方法不能在内部调用普通方法
		return m_data;
	}
	//int GetData(Test * const this)
	int GetData(){//两个可以同时存在，原因就是两个参数不同，形成重载
		return m_data;
	}
	//Test * const this
	void Show() {
		GetData();//普通方法在内部可以调动常方法
		cout << m_data << endl;
	}
private:
	int m_data;
};
void main() {
	Test t;//普通对象可以调用int GetData()方法
	t.GetData();
	const Test t1;//常变量只能调动常方法
	cout << "t1=" << t1.GetData() << endl;
}
*/