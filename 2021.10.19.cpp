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
	Test* operator&() {//��ͨ��ַȡ��ַ��
		return this;
	}
	const Test* operator&()const {//������ȡ��ַ��
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
	Complex(int real, int image):m_real(real),m_imag(image)//�����б�ĳ�ʼ����ʽ
	{}
	~Complex()
	{}
public:
	friend Complex operator+(int value, const Complex &x);
	friend ostream& operator<<(ostream &out, const Complex &x);//��������������
public:
	//�����ļӼ�����
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
	//������Ԫ��ʽ���У�����ִ�д���
	Complex d = 10 + c1;

	cout << c << endl;//��������������
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
	//a + b ��aͨ��thisָ�봫�ݣ����Դ˴���һ����������
	MyInt operator+(const MyInt &x) {
		/*MyInt tmp(data);
		return tmp;*/
		/*return MyInt(m_i + x.m_i);
	}
public:
	MyInt& operator+=(const MyInt &x) {//MyInt�������������Ϊ���ص�thisָ�벻���������Ӱ�� 
		m_i += x.m_i;
		return *this;
	}
public://�߼������������
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
	MyInt& operator++()//ǰ++
	{
		m_i++;
		return *this;
	}
	MyInt operator++(int)//��++   
	//��������Ϊ�˱�����ǰ++�������أ���û�в���������ν����Ϊ��ִ���иò���������ִ��
	{
		MyInt tmp = *this;
		m_i++;
		return tmp;
	}
	MyInt& operator--()//ǰ--
	{
		m_i--;
		return *this;
	}
	MyInt& operator--(int)//��--
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
			m_data = (char*)malloc(strlen(str) + 1);//1 ��"\0"
			//m_data = (char*)malloc(sizeof(str));//������sizeof����Ϊsizeof���洫��str��ָ�룬�������������Ƕ��ٸ��ַ���������ӡ4���ֽ�
			strcpy(m_data, str);
		}
	}
	String(const String &s) {
		m_data = s.m_data;
	}
	//�쳣����ȫ
	String& operator=(const String &s) {//s2�տ�ʼ�������Լ�ָ��Ŀռ䣬�����ͷ�ԭ�пռ䣬��ᷢ���ڴ�й©
		//���
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
	int GetData()const {//������
		this->Show();//�������������ڲ�������ͨ����
		return m_data;
	}
	//int GetData(Test * const this)
	int GetData(){//��������ͬʱ���ڣ�ԭ���������������ͬ���γ�����
		return m_data;
	}
	//Test * const this
	void Show() {
		GetData();//��ͨ�������ڲ����Ե���������
		cout << m_data << endl;
	}
private:
	int m_data;
};
void main() {
	Test t;//��ͨ������Ե���int GetData()����
	t.GetData();
	const Test t1;//������ֻ�ܵ���������
	cout << "t1=" << t1.GetData() << endl;
}
*/