#include <iostream>
#include <string>
using namespace std;

//反转字符串 II[https://leetcode-cn.com/problems/reverse-string-ii/]
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
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += 2 * k) {
			if (i + k < s.size())
				reverse(s, i, i + k);
			else
				reverse(s, i, s.size());
		}
		return s;
	}
};

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