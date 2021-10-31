#include <iostream>
#include <string>

using namespace std;

//加号运算符重载[https://www.nowcoder.com/practice/b9e27fcf61fc4013875409ed78e0960b?tpId=225&tqId=2191508&ru=/ta/primary-grammar-cpp&qru=/ta/primary-grammar-cpp/question-ranking]
class Time {

public:
	int hours;      // 小时
	int minutes;    // 分钟

	Time() {
		hours = 0;
		minutes = 0;
	}

	Time(int h, int m) {
		this->hours = h;
		this->minutes = m;
	}

	void show() {
		cout << hours << " " << minutes << endl;
	}

	// write your code here......
	Time operator+(Time &t) {
		Time sum;
		sum.hours = hours + t.hours + (minutes + t.minutes) / 60;//小时数相加，加上分钟数多余60进1
		sum.minutes = (minutes + t.minutes) % 60;//分钟数要对60取余
		return sum;
	}

};

int main() {

	int h, m;
	cin >> h;
	cin >> m;

	Time t1(h, m);
	Time t2(2, 20);

	Time t3 = t1 + t2;
	t3.show();

	return 0;
}

//友元全局函数[https://www.nowcoder.com/practice/4f39f32887b643e8a8dca115df4618de?tpId=225&tags=&title=&difficulty=0&judgeStatus=0&rp=0]
/*
class Person {
	friend void showAge(Person& p);
public:
	Person(int age) {
		this->age = age;
	}

private:
	int age;
};

void showAge(Person& p) {
	cout << p.age << endl;
}

int main() {

	Person p(10);
	showAge(p);

	return 0;
}*/

//拷贝构造函数[https://www.nowcoder.com/practice/535753110cbd4e8987adc2e67f392ab7?tpId=225&tags=&title=&difficulty=0&judgeStatus=0&rp=0]
/*
class Person {
public:
	char* name; // 姓名
	int age;    // 年龄

	Person(const char* name, int age) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
	}

	// write your code here......
	Person(const Person &t) {
		this->name = new char[strlen(t.name) + 1];
		strcpy(this->name, t.name);
		this->age = t.age;
	}

	void showPerson() {
		cout << name << " " << age << endl;
	}

	~Person() {
		if (name != nullptr) {
			delete[] name;
			name = nullptr;
		}
	}

};

int main() {

	char name[100] = { 0 };
	int age;

	cin >> name;
	cin >> age;

	Person p1(name, age);
	Person p2 = p1;

	p2.showPerson();

	return 0;
}*/

// 构造函数[https://www.nowcoder.com/practice/2809d720c7024f959b283f8444d9bdc9?tpId=225&tqId=2190803&ru=/ta/primary-grammar-cpp&qru=/ta/primary-grammar-cpp/question-ranking]
/*
class Person {
public:
	string name;    // 姓名
	int age;    // 年龄

	// write your code here......
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}

	void showPerson() {
		cout << name << " " << age << endl;
	}
};

int main() {

	string name;
	int age;

	cin >> name;
	cin >> age;

	Person p(name, age);
	p.showPerson();

	return 0;
}
*/