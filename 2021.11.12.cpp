#include <iostream>
#include <list>
using namespace std;

//list的构造
int main() {
	std::list<int> l1;//构造一个空链表l1
	std::list<int> l2(4, 100);//l2中放4个值为100的元素

	std::list<int> l3(l2.begin(), l2.end());//用l2的[begin(),end()) 左闭右开的区间构造l3
	std::list<int> l4(l3);//用l3拷贝构造l4

	int arry[] = { 16,3,56,29 };//以数组为迭代器构造l5
	std::list<int> l5(arry, arry + sizeof(arry) / sizeof(arry[0]));

	//以迭代器方式打印l5中的元素
	for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
		std::cout << *it << " ";
	std::cout << endl;

	for (auto &e : l5)//C++11范围for的方式遍历
		std::cout << e << " ";
	std::cout << endl;
	return 0;
}

/*
int main() {
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(ar) / sizeof(ar[0]);
	//list<int> mylist;//实例化一个带头结点的双向循环链表
	//list<int> mylist(10, 5);
	list<int> mylist(ar, ar + n);

	for (const auto &e : mylist)
		cout << e << " ";
	cout << endl;

	list<int> youlist = mylist;
	for (const auto &e : youlist)
		cout << e << " ";
	cout << endl;
	return 0;
}
*/

/*
int main() {
	list<int> mylist;
	mylist.push_back(3);
	mylist.push_back(30);
	mylist.push_back(13);
	mylist.push_back(5);
	mylist.push_back(8);
	mylist.push_back(6);

	list<int>::iterator it = mylist.begin();
	while (it != mylist.end()) {
		cout << *it << "->";
		++it;
	}
	cout << "Over." << endl;

	mylist.sort();
	it = mylist.begin();
	while (it != mylist.end()) {
		cout << *it << "->";
		++it;
	}
	cout << "Over." << endl;
	return 0;
}*/