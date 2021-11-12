#include <iostream>
#include <list>
using namespace std;

//list�Ĺ���
int main() {
	std::list<int> l1;//����һ��������l1
	std::list<int> l2(4, 100);//l2�з�4��ֵΪ100��Ԫ��

	std::list<int> l3(l2.begin(), l2.end());//��l2��[begin(),end()) ����ҿ������乹��l3
	std::list<int> l4(l3);//��l3��������l4

	int arry[] = { 16,3,56,29 };//������Ϊ����������l5
	std::list<int> l5(arry, arry + sizeof(arry) / sizeof(arry[0]));

	//�Ե�������ʽ��ӡl5�е�Ԫ��
	for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
		std::cout << *it << " ";
	std::cout << endl;

	for (auto &e : l5)//C++11��Χfor�ķ�ʽ����
		std::cout << e << " ";
	std::cout << endl;
	return 0;
}

/*
int main() {
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(ar) / sizeof(ar[0]);
	//list<int> mylist;//ʵ����һ����ͷ����˫��ѭ������
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