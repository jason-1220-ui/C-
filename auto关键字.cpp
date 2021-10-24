#include<iostream>
using namespace std;

//实现四舍五入
#include <iostream>
using namespace std;

int main() {
	double d;
	cin >> d;
	int a = (int)d;
	if (d >= 0) {
		if (d + 0.5 >= a + 1) {
			cout << a + 1 << endl;
		}
		else {
			cout << a << endl;
		}
	}
	else {
		if (d - 0.5 <= a - 1) {
			cout << a - 1 << endl;
		}
		else {
			cout << a << endl;
		}
	}
	return 0;
}

//void Test(int arr) {
//	for (auto &e : arr) {//for的范围不确定
//		cout << e << endl;
//	}
//}

//void Test() {
//	int arr[] = { 1,2,3,4,5 };
//	for (auto&e : arr) {
//		e *= 2;
//	}
//	for (auto e : arr) {
//		cout << e << " ";
//	}
//}

//void Test() {
//	int arr[] = { 1,2,3,4,5,6 };
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
//		arr[i] *= 2;
//	}
//	for (int *p = arr; p < arr + sizeof(arr) / sizeof(arr[0]); ++p) {
//		cout << *p << endl;
//	}
//}

//int main() {
//	Test();
//	return 0;
//}

//int main() {
//	int x = 10;
//	auto* a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	*a = 20;
//	*b = 30;
//	c = 40;
//	return 0;
//}

//int main() {
//	int x = 10;
//	auto* a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	*a = 20;
//	*b = 30;
//	c = 40;
//	return 0;
//}

//int TestAuto() {
//	return 10;
//}
//
//int main() {
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	auto e = 0;//无法通过编译，使用auto定义变量时必须对其进行初始化
//	return 0;
//}