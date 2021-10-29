#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//引用计数器类
class String_rep {
	friend class String;
	friend ostream& operator<<(ostream& out, const String &s);
public:
	String_rep(const char *str = ""):use_count(0) {
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String_rep(const String_rep &rep) :use_count(0) {
		m_data = new char[strlen(rep.m_data) + 1];
		strcpy(m_data, rep.m_data);
	}
	//String_rep& operator=(const String_rep &rep);
	~String_rep() {
		delete []m_data;
		m_data = nullptr;
	}
public:
	void increment(){
		++use_count; 
	}
	void decrement(){
		if (--use_count == 0) {
			delete this;//自杀行为
		}
	}
private:
	char *m_data;
	size_t use_count;
};

class String {
	friend ostream& operator<<(ostream& out, const String &s);
public:
	String(const char *str = "") :m_rep(new String_rep(str)) {
		m_rep->increment();
	}
	String(const String &s):m_rep(s.m_rep) {
		m_rep->increment();
	}
	String& operator=(const String &s) {
		if (this != &s) {
			m_rep->decrement();//释放对象
			m_rep = s.m_rep;//拷贝赋值
			m_rep->increment();//增加引用计数
		}
		return *this;
	}
	~String(){
		m_rep->decrement();
	}
public:
	//写实拷贝
	void to_upper() {
		String_rep *new_rep = new String_rep(*m_rep);
		m_rep->decrement();
		m_rep = new_rep;

		char *pch = m_rep->m_data;
		while (*pch != '\0') {
			if (*pch >= 'a' && *pch <= 'z') {
				*pch -= 32;
				pch++;
			}
		}
		m_rep->increment();
	}
private:
	String_rep *m_rep;
};

ostream& operator<<(ostream& out, const String &s) {
	out << s.m_rep->m_data;
	return out;
}
int main() {
	String s1("abc");
	String s2 = s1;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;

	s1.to_upper();
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	return 0;
}

/*
class String {
	friend ostream& operator<<(ostream& out, const String &s);
public:
	String(const char *str = "") {
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);//预防不能求空串的问题
	}
	String(const String &s) {
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s) {
		if (this != &s) {
			delete []m_data;
			m_data = new char[strlen(s.m_data) + 1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String() {
		delete []m_data;
		m_data = nullptr;//预防野指针的使用
	}
private:
	char *m_data;
};
ostream& operator<<(ostream& out, const String &s) {
	out << s.m_data;
	return out;
}

int main() {
	String s("abc");
	String s1;
	s1 = s;
	cout << "s = " << s << endl;
	cout << "s1 = " << s1 << endl;
	return 0;
}
*/