#include<iostream>
#include<string>
using namespace std;

int main() {
	string s1 = "abcxyzab";
	int index = s1.find_first_of("yxza");
	cout << index << endl;
	return 0;
}

//int main() {
//	string s1 = "abcxyzab";
//	int index = s1.find_first_not_of("yxza");
//	cout << index << endl;
//	return 0;
//}

//int main() {
//	string s1 = "abc";
//	string s2 = "xyz";
//	cout << s1 << endl;
//	cout << s2 << endl;
//	s1.swap(s2);
//	cout << s1 << endl;
//	cout << s2 << endl;
//	return 0;
//}

//int main() {
//	string s1 = "axuvhxjs";
//	s1.insert(0, "11");
//	//s1.erase(s1.begin(), s1.end());
//	s1.erase(2, 5);
//	cout << s1 << endl;
//	return 0;
//}

//int main() {
//	string s1 = "abc";
//	char str[] = "axax";
//	s1.copy(str, 3, 0);
//	cout << str << endl;
//	return 0;
//}

//int main() {
//	string s1 = "abc";
//	string s2 = "abc";
//	if (s1.compare(s2) == 0)
//		cout << "s1=s2" << endl;
//	return 0;
//}

//int main() {
//	string s1 = "abc";
//	for (int i = 0; i <= s1.size(); ++i)
//		cout << s1[i];//不检查
//	cout << endl;
//
//	for (int i = 0; i < s1.size(); ++i)
//		cout << s1.at(i);//检查越界
//	cout << endl;
//	return 0;
//}

//int main() {
//	string s1 = "abc";
//	string s2 = "subuucg";
//	//string &rs = s1.assign("xyzshhwguwdiqugy");
//	//s1.assign(s2);
//	s1 = s2;
//	cout << s1 << endl;
//	return 0;
//}

//int main() {
//	string s;
//	//cin >> s;
//	getline(cin, s);//输入的字符串有空格时，不能用cin直接输入
//	cout << s << endl;
//	return 0;
//}

//int main() {
//	string s = "abcxyz";
//	cout << "s = " << s << endl;
//	//string s1 = s.substr(2,3);
//	string s1 = s.substr(2);
//	cout << "s = " << s << endl;
//	cout << "s1 = " << s1 << endl;
//	return 0;
//}

//int main() {
//	string s = "abxcxyz";
//	//int index = s.find('x',3);
//	//int index = s.find('w');
//	//int index = s.find("xyz", 4, 2);
//	int index = s.rfind('x');
//	if (index == string::npos)//npos是静态的，需用类名限定
//		cout << "找不到" << endl;
//	else
//		cout << "index = " << index << endl;
//	return 0;
//}

//int main() {
//	string s("abc");
//	const char *str = "abc";
//	strlen(s.c_str());
//
//	//s.append(s1, 3, 3);
//	//cout << "s=" << s << endl;
//	//s += "xyz";
//	/*s += s1;
//	cout << "s=" << s << endl;*/
//	return 0;
//}

/*
int main() {
	string s;
	cout << "capacity=" << s.capacity() << endl;
	s.reserve(100);
	for (int i = 0; i < 100; ++i) {
		cout << "capacity=" << s.capacity() << endl;
		s.push_back(i);
	}
	return 0;
}*/

/*
int main() {
	string s1("HelloBit");
	cout << "s1=" << s1 << endl;
	cout << "size=" << s1.size() << endl;//STL
	cout << "length=" << s1.length() << endl;
	cout << "capacity=" << s1.capacity() << endl;
	
	string s2;
	cout << s2.empty() << endl;
	s1.clear();
	cout << "s1=" << s1 << endl;
	return 0;
}*/

/*
int main() {
	string s1;
	cout << "s1=" << s1 << endl;
	string s2("HelloBit");
	cout << "s2=" << s2 << endl;
	string s3 = "HelloC++";
	cout << "s3=" << s3 << endl;
	string s4(5, 'a');
	cout << "s4=" << s4 << endl;
	string s5(s4);
	cout << "s5=" << s5 << endl;
	string s6(s2, 5, 3);
	cout << "s6=" << s6 << endl;

	string s7("HelloBit",5);
	cout << "s7=" << s7 << endl;

	const char *str = "abcxyz";
	string s8(str + 1, str + 5);
	cout << "s8=" << s8 << endl;
	return 0;
}
*/