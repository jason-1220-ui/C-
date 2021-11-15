#include<iostream>
#include<list>
#include<vector>
using namespace std;

void PrintList(list<int> &l) {
	for (auto &e : l)
		cout << e << "->";
	cout << "Over." << endl;
}

int main() {
	//int arr[] = { 1,2,3 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//list<int> mylist(arr, arr + n);
	//PrintList(mylist);
	//mylist.push_back(4);//在mylist的尾部插入4，头部插入0
	//mylist.push_front(0);
	//PrintList(mylist);

	//mylist.pop_back();//删除mylist尾部节点和头部节点
	//mylist.pop_front();
	//list<int>::iterator it = mylist.begin();
	//while (it != mylist.end()) {
	//	cout << *it << "->";
	//	it++;
	//}
	//cout << "Over." << endl;

	/*
	int arr1[] = { 1,2,3 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	list<int> mylist1(arr1, arr1 + n1);
	auto pos = ++mylist1.begin();//获取链表中的第二个节点
	cout << *pos << endl;
	mylist1.insert(pos, 4);//在pos前插入值为4的元素
	PrintList(mylist1);
	mylist1.insert(pos, 5, 5);//在pos前插入5个值为5的元素
	PrintList(mylist1);

	vector<int> v{ 7,8,9 };//在pos前插入[v.begin(),v.end())区间的元素
	mylist1.insert(pos, v.begin(), v.end());
	PrintList(mylist1);

	mylist1.erase(pos);//删除pos位置上的元素
	PrintList(mylist1);
	mylist1.erase(mylist1.begin(), mylist1.end());
	PrintList(mylist1);
	*/

	int arr2[] = { 1,2,3 };//用数组来构造list
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	list<int> l1(arr2, arr2 + n2);
	int arr3[] = { 6,7,8 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	list<int> l2(arr3, arr3 + n3);
	l1.swap(l2);//交换l1和l2中的元素
	PrintList(l1);
	PrintList(l2);
	l2.clear();//将l2中的元素清空
	cout << l2.size() << endl;
	PrintList(l2);
	return 0;
}