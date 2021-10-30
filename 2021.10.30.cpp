#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 求1+2+3+...+n[https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking]
//递归
class Solution {
public:
	int Sum_Solution(int n) {
		if (n == 1)
			return n;
		return n + Sum_Solution(n - 1);
	}
};
//非递归
class Solution {
public:
	int Sum_Solution(int n) {
		int sum = n;
		for (int i = 1; i < n; i++) {
			sum += i;
		}
		return sum;
	}
};

//计算日期到天数的转换[https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking]
/*
int main() {
	int year, month, day;
	int count = 0;
	while (cin >> year >> month >> day) {
		int days[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			days[1] = 29;
		}
		else {
			days[1] = 28;
		}
		for (int i = 0; i < month - 1; i++) {
			count += days[i];
		}
		count += day;
		cout << count << endl;
	}
	return 0;
}*/

//日期差值[https://www.nowcoder.com/practice/ccb7383c76fc48d2bbc27a2a6319631c?tpId=62&&tqId=29468&rp=1&ru=]
/*
bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int monthDays[2][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
	};
	char date1[9];//多申请一个空间给\n
	char date2[9];
	int y1, m1, d1, y2, m2, d2;
	int n1 = 0, n2 = 0;
	while (cin >> date1 >> date2) {
		n1 = n2 = 0;
		sscanf(date1, "%4d%2d%2d", &y1, &m1, &d1);
		sscanf(date2, "%4d%2d%2d", &y2, &m2, &d2);
		for (int i = 0; i <= y1; ++i) {
			n1 += isLeapYear(i) ? 366 : 365;
		}
		for (int i = 0; i <= y2; ++i) {
			n2 += isLeapYear(i) ? 366 : 365;
		}
		for (int j = 1; j < m1; ++j) {
			n1 += monthDays[isLeapYear(y1)][j - 1];
		}
		for (int j = 1; j < m2; ++j) {
			n2 += monthDays[isLeapYear(y2)][j - 1];
		}
		n1 += d1;
		n2 += d2;
		cout << abs(n1 - n2) + 1 << endl;
	}
	return 0;
}*/

//打印日期[https://www.nowcoder.com/practice/b1f7a77416194fd3abd63737cdfcf82b?tpId=69&&tqId=29669&rp=1&ru=/activity/oj&qru=/ta/hust-kaoyan/question-ranking]
/*
int main() {
	int year, month, day;
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int b[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	while (scanf("%d%d", &year, &day) != EOF) {
		month = 1;
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			while (day > b[month]) {
				day -= b[month++];
			}
		}
		else {
			while (day > a[month]) {
				day -= a[month++];
			}
		}
		printf("%04d-%02d-%02d\n", year, month, day);
	}
	return 0;
}
*/

//日期累加[https://www.nowcoder.com/practice/eebb2983b7bf40408a1360efb33f9e5d?tpId=40&&tqId=31013&rp=1&ru=/activity/oj&qru=/ta/kaoyan/question-ranking]
/*
int GetMonthDay(int year, int month) {
	static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = days[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0)) || (year % 400 == 0)) {
		day += 1;
	}
	return day;
}

int main() {
	int m, _year, _month, _day, n;
	cin >> m;
	while (m--) {
		cin >> _year >> _month >> _day >> n;
		_day += n;
		while (_day > GetMonthDay(_year, _month)) {
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13) {
				_year++;
				_month = 1;
			}
		}
		printf("%04d-%02d-%02d\n", _year, _month, _day);
	}
	return 0;
}
*/