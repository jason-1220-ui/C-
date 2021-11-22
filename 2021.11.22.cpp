#include<iostream>
#include<string>
using namespace std;

class String {
public:
	typedef String this_type;
public:
	String(const char *str = "") {
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String &s):m_data(nullptr){
		String Tmp(s.m_data);
		std::swap(m_data, Tmp.m_data);
	}
	/*String(const String &s) {
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data, s.m_data);
	}*/
	String& operator=(const String &s) {
		if (this != &s) {
			//String(s.m_data).Swap(*this);
			this_type(s.m_data).Swap(*this);//临时对象的语法
		}
		return *this;
	}
	/*String& operator=(const String &s) {
		if (this != &s) {
			String Tmp(s);
			char *tmp_data = m_data;
			m_data = Tmp.m_data;
			Tmp.m_data = tmp_data;
		}
		return *this;
	}*/
	/*String& operator=(const String &s) {
		if (this != &s) {
			char *new_data = new char[strlen(s.m_data) + 1];
			strcpy(new_data, s.m_data);
			delete[]m_data;
			m_data = new_data;
		}
		return *this;
	}*/
	~String() {
		if (m_data) {
			delete[]m_data;
			m_data = nullptr;
		}
	}
public:
	void Swap(String &s) {
		char *tmp = m_data;
		m_data = s.m_data;
		s.m_data = tmp;
	}
private:
	char *m_data;
};

int main() {
	String s1 = "abc";
	String s2 = "xyz";
	s2 = s1;
	String s2(s1);
	return 0;
}

//获取字符串中最后一个单词的长度
/*
int GetLengthLastWord(string &str) {
	int pos = str.rfind(' ');
	if (pos == string::npos)
		return str.size();
	return str.size() - pos - 1;
}

int main() {
	string str;
	getline(cin, str);
	GetLengthLastWord(str);
	return 0;
}*/

//获取字符串中唯一一个字符
//int GetFirstOnly(string str) {
//	int j, i;
//	for (int i = 0; i < str.size(); ++i) {
//		for (j = 0; j < str.size(); ++j) {
//			if (j == i)
//				continue;
//			if (str[i] == str[j])
//				break;
//		}
//		if (j >= str.size())
//			return i;
//	}
//	return -1;
//}
//
//int main() {
//	string str;
//	while (cin >> str) {
//		cout << GetFirstOnly(str) << endl;
//	}
//	return 0;
//}