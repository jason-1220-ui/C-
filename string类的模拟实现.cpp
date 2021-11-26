#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;

namespace bit {
	class string {
		friend ostream& operator<<(ostream &out, const string &s);
	public:
		string(const char *str="") {
			m_capacity = strlen(str) * 2;
			m_size = strlen(str);
			m_str = new char[m_capacity + 1];
			strcpy(m_str, str);
		}
		string(const string&s):m_str(nullptr),m_capacity(0),m_size(0) {
			string tmp(s.m_str);
			swap(tmp);
		}
		string& operator=(string s) {
			if (this != &s)
				swap(s);
			return *this;
		}
		~string() {
			if (m_str) {
				delete[]m_str;
				m_str = nullptr;
				m_capacity = m_size = 0;
			}
		}
	public:
		size_t size()const {
			return m_size;
		}
		size_t capacity()const {
			return m_capacity;
		}
		bool empty()const {
			return size() == 0;
		}
	public:
		void push_back(char c) {
			if (m_size >= m_capacity) {
				//����
				reverse(m_capacity == 0 ? 1 : 2 * m_capacity);
			}
			m_str[m_size] = c;
			m_size++;
			m_str[m_size] = '\0';
		}
	public:
		char& operator[](int pos) {
			assert(pos >= 0 && pos < m_size);
			return m_str[pos];
		}
		const char& operator[](int pos)const {
			assert(pos >= 0 && pos < m_size);
			return m_str[pos];
		}
	public:
		void swap(string &str) {
			std::swap(m_str, str.m_str);
			std::swap(m_capacity, str.m_capacity);
			std::swap(m_size, str.m_size);
		}
	public:
		void reverse(size_t new_capacity) {
			if (new_capacity > m_capacity) {
				char *new_str = new char[new_capacity + 1];
				memcpy(new_str, m_str, m_size + 1);
				delete[]m_str;
				m_str = new_str;
				m_capacity = new_capacity;
			}
		}
		void resize(size_t newSize, char c = '\0') {
			if (newSize > m_size) {
				if (newSize > m_capacity) {
					reverse(newSize);
				}
				memset(m_str + m_size, c, newSize - m_size);
			}
			m_str[newSize] = '\0';
			m_size = newSize;
		}
		void clear() {
			m_str[0] = '\0';
			m_size = 0;
		}
	public:
		typedef char* iterator;
		iterator begin() {
			return m_str;
		}
		iterator end() {
			return m_str + m_size;
		}
	public:
		string& operator+=(char c) {
			push_back(c);
			return *this;
		}
		string& operator+=(const char* str) {
			int len = strlen(str);
			if (m_size + len > m_capacity) {
				reverse(2 * (m_size + len));
			}
			strcat(m_str, str);
			m_size += len;
			return *this;
		}
	public:
		const char* c_str()const {
			return m_str;
		}
		char& operator[](int pos) {
			assert(pos >= 0 && pos < m_size);
			return m_str[pos];
		}
		const char& operator[](int pos)const {
			assert(pos >= 0 && pos < m_size);
			return m_str[pos];
		}
	public:
		bool operator<(const string& s) {
			if (strcmp(m_str, s.m_str) == -1)
				return true;
			else
				false;
		}
		bool operator<=(const string& s) {
			return (*this < s) || (*this == s);
		}
		bool operator>(const string& s) {
			return !(*this <= s);
		}
		bool operator>=(const string& s) {
			return !(*this < s);
		}
		bool operator==(const string& s) {
			if (strcmp(m_str, s.m_str) == 0)
				return true;
			else
				return false;
		}
		bool operator!=(const string& s) {
			return !(*this == s);
		}
	private:
		char *m_str;
		size_t m_capacity;
		size_t m_size;
	};
	ostream& operator<<(ostream &out, const string &s) {
		for (int i = 0; i < s.size(); ++i)
			out << s[i];
		return out;
	}
};

int main() {
	bit::string s("Linux");
	for (auto &e : s)
		cout << e;
	cout << endl;
	bit::string::iterator it = s.begin();
	while (it != s.end()) {
		cout << *it;
		++it;
	}
	cout << endl;

	/*bit::string s("abc");
	cout << s << endl;
	s += "ABCDEF";
	cout << s << endl;
	s.clear();
	cout << s << endl;*/

	/*bit::string s;
	cout << s << endl;
	s.resize(10, 'a');
	cout << s << endl;
	s.resize(5);
	cout << s << endl;*/

	/*bit::string s("abc");
	s.push_back('x');
	s.push_back('y');
	s.push_back('z');
	s.push_back('w');
	cout << s << endl;*/

	return 0;
}