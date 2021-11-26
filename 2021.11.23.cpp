#include <iostream>
#include <string>
#include <vector>
using namespace std;

//把字符串转换成整数[https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking]
class Solution {
public:
	int StrToInt(string str) {
		if (str.size() == 0)
			return 0;
		int sign = 1;//正数
		int i = 0;
		if (str[0] == '+' || str[0] == '-') {
			if (str[0] == '-')
				sign = -1;//负数
			i++;
		}
		int num = 0;
		while (i < str.size()) {
			if (str[i] < '0' || str[i] > '9')
				return 0;
			num = num * 10 + str[i] - '0';
			i++;
		}
		return sign * num;
	}
};

//字符串相加[https://leetcode-cn.com/problems/add-strings/submissions/]
/*
class Solution {
public:
	int AddItem(int a, int b, int &sign) {
		int sum = a + b + sign;
		if (sum >= 10) {
			sum -= 10;
			sign = 1;
		}
		else {
			sign = 0;
		}
		return sum;
	}
	string addStrings(string num1, string num2) {
		reverse(num1.begin(), num1.end());//654
		reverse(num2.begin(), num2.end());//77
		int sign = 0;//进位
		int i = 0, j = 0;
		int sum;
		string result;
		while (i < num1.size() && j < num2.size()) {
			sum = AddItem(num1[i] - '0', num2[j] - '0', sign);
			result.push_back(sum + '0');
			i++;
			j++;
		}
		while (i < num1.size()) {
			sum = AddItem(num1[i] - '0', 0, sign);
			result.push_back(sum + '0');
			i++;
		}
		while (j < num2.size()) {
			sum = AddItem(0, num2[j] - '0', sign);
			result.push_back(sum + '0');
			j++;
		}
		if (sign > 0) {
			result.push_back(sign + '0');
		}
		reverse(result.begin(), result.end());
		return result;
	}
};*/

//反转字符串[https://leetcode-cn.com/problems/reverse-string/submissions/]
/*
class Solution {
public:
	void reverseString(vector<char>& s) {
		int left = 0;
		int right = s.size() - 1;
		while (left < right) {
			char tmp = s[left];
			s[left] = s[right];
			s[right] = tmp;
			left++;
			right--;
		}
	}
};*/

//验证回文串[https://leetcode-cn.com/problems/valid-palindrome/submissions/]
/*
class Solution {
public:
	bool IsLetterOrDig(char ch) {
		return ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a' && ch <= 'z')) || (ch >= '0' && ch <= '9');
	}
	void transform(string &s) {
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 32;
		}
	}
	bool isPalindrome(string s) {
		if (s.size() <= 1)
			return true;
		transform(s);
		int left = 0;
		int right = s.size() - 1;
		while (left < right) {
			while (left < right && !IsLetterOrDig(s[left]))
				left++;
			while (left < right && !IsLetterOrDig(s[right]))
				right--;
			if (s[left] != s[right])
				return false;
			left++;
			right--;
		}
		return true;
	}
};*/

//字符串最后一个单词的长度[https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking]
/*
int GetLastWordLen(string &str) {
	int pos = str.rfind(' ');
	if (pos == string::npos)
		return str.size();
	return str.size() - pos - 1;
}

int main() {
	string str;
	getline(cin, str);
	cout << GetLastWordLen(str);
	return 0;
}*/

//字符串中的第一个唯一字符（返回索引）[https://leetcode-cn.com/problems/first-unique-character-in-a-string/]
//反向查找法
/*
class Solution {
public:
	int firstUniqChar(string s) {
		for (int i = 0; i < s.size(); ++i) {
			int index = s.find(s[i]);
			int rindex = s.rfind(s[i]);
			if (index == rindex)
				return i;
		}
		return -1;
	}
};*/
//哈希表
/*
class Solution {
public:
	int firstUniqChar(string s) {
		int hash[256] = { 0 };
		for (int i = 0; i < s.size(); ++i)
			hash[s[i]]++;
		for (int i = 0; i < s.size(); ++i) {
			if (hash[s[i]] == 1)
				return i;
		}
		return -1;
	}
};*/
//暴力求解法
/*
class Solution {
public:
	int firstUniqChar(string s) {
		int j;
		for (int i = 0; i < s.size(); ++i) {
			for (j = 0; j < s.size(); ++j) {
				if (i == j)
					continue;
				if (s[i] == s[j])
					break;
			}
			if (j >= s.size())
				return i;
		}
		return -1;
	}
};*/

//字符串相乘[https://leetcode-cn.com/problems/multiply-strings/]
/*
class Solution {
public:
	void MulItem(string &num, int s, string &tmp) {
		int sign = 0;
		for (int i = 0; i < num.size(); ++i) {
			int mul = (num[i] - '0') * s + sign;
			if (mul >= 10) {
				sign = mul / 10;
				mul %= 10;
			}
			else {
				sign = 0;
			}
			tmp.push_back(mul + '0');
		}
		if (sign > 0)
			tmp.push_back(sign + '0');
	}
	int AddItem(int a, int b, int &sign) {
		int sum = a + b + sign;
		if (sum >= 10) {
			sum -= 10;
			sign = 1;
		}
		else
			sign = 0;
		return sum;
	}
	void AddMove(string &num, string &tmp, int k) {
		int i = k;
		int j = 0;
		int sign = 0;
		while (i < num.size() && j < tmp.size()) {
			num[i] = AddItem(num[i] - '0', tmp[j] - '0', sign) + '0';
			i++;
			j++;
		}
		while (i < num.size()) {
			num[i] = AddItem(num[i] - '0', 0, sign) + '0';
			i++;
		}
		while (j < tmp.size()) {
			int sum = AddItem(0, tmp[j] - '0', sign);
			num.push_back(sum + '0');
			j++;
		}
		if (sign > 0)
			num.push_back(sign + '0');
	}
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return string("0");
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		string tmp, result;
		for (int i = 0; i < num2.size(); ++i) {
			MulItem(num1, num2[i] - '0', tmp);
			AddMove(result, tmp, i);
			tmp.clear();
		}
		reverse(result.begin(), result.end());
		return result;
	}
};*/

//反转字符串 II[https://leetcode-cn.com/problems/reverse-string-ii/]
//class Solution {
//public:
//	void reverse(string &s, int start, int end) {
//		int left = start;
//		int right = end - 1;
//		while (left < right) {
//			char tmp = s[left];
//			s[left] = s[right];
//			s[right] = tmp;
//			left++;
//			right--;
//		}
//	}
//	string reverseStr(string s, int k) {
//		for (int i = 0; i < s.size(); i += 2 * k) {
//			if (i + k < s.size())
//				reverse(s, i, i + k);
//			else
//				reverse(s, i, s.size());
//		}
//		return s;
//	}
//};

//反转字符串中的单词 III[https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/]
/*
class Solution {
public:
	void reverse(string &s, int start, int end) {
		int left = start;
		int right = end - 1;
		while (left < right) {
			char tmp = s[left];
			s[left] = s[right];
			s[right] = tmp;
			left++;
			right--;
		}
	}
	string reverseWords(string s) {
		int start = 0;
		int pos;
		while ((pos = s.find(' ', start)) != string::npos) {
			reverse(s, start, pos);
			start = pos + 1;
		}
		reverse(s, start, s.size());
		return s;
	}
};*/

//找出字符串中第一个只出现一次的字符[https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking]
/*
//暴力求解法
int main(){
	string str;
	while(cin>>str){
		int count = 0;
		int temp;
		for(int i = 0;i<str.size();++i){
			for(int j = 0;j<str.size();++j){
				if(str[i] == str[j])
					count++;
			}
			if(count==1){
				cout<<str[i]<<endl;
				break;
			}
			else if(count>=2){
				count = 0;
				temp++;
			}
		}
		if((temp != 0) && (count != 1)){
			cout<<"-1"<<endl;
		}
	}
	return 0;
}
//反向查找法
int main() {
	string str;
	while (getline(cin, str)) {
		int i;
		for (i = 0; i < str.size(); i++) {
			if (str.find(str[i]) == str.rfind(str[i])) {
				cout << str[i] << endl;
				break;
			}
		}
		if (i == str.size())
			cout << "-1" << endl;
	}
	return 0;
}*/
//哈希表
//int main() {
//	string str;
//	while (cin >> str) {
//		int hash[256] = {0};
//		bool flag = false;
//		for (int i = 0; i < str.size(); ++i) {
//			hash[str[i]]++;
//		}
//		for (int i = 0; i < str.size(); ++i) {
//			if (hash[str[i]] == 1) {
//				cout << str[i] << endl;
//				flag = true;
//				break;
//			}
//		}
//		if (!flag)
//			cout << "-1" << endl;
//	}
//	return 0;
//}