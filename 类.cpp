#include <iostream>
#include <assert.h>
using namespace std;

/*
class List {
public:
	//�ڲ���
	class iterator {
	public:
		void show()const {
			cout << "List::iterator::show()." << endl;
			List lt;
			lt.m_a = 10;
		}
	private:
		int m_c = 0;
	};
private:
	int m_a = 0;
	int m_b = 0;
};
void main() {
	cout << sizeof(List) << endl;
	//List::iterator it;
	//it.show();
}
*/

/*
class List;
//����ڵ�
class ListNode {
	friend class List;//��Ԫ��
public:
	ListNode():m_data(0),m_next(nullptr)
	{}
	~ListNode()
	{}
public:
	//void fun() {
	//	List t;
	//	//��Ԫ��ϵ�ǵ���ģ������н�����
	//	cout << t.m_head << endl;//tʹ����δ�����class"List"
	//}
private:
	int m_data;
	ListNode *m_next;
};
class List {
public:
	List() :m_head(nullptr)
	{}
	~List()
	{}
public:
	void push_front(int v) {
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->m_data = v;
		s->m_next = nullptr;

		s->m_next = m_head;
		m_head = s;
	}
	void show_list() const {
		ListNode *p = m_head;
		while (p != nullptr) {
			cout << p->m_data << "-->";
			p = p->m_next;
		}
		cout << "Over." << endl;
	}
private:
	ListNode *m_head;
};

int main() {
	List myList;
	for (int i = 1; i <= 10; ++i) {
		myList.push_front(i);
	}
	myList.show_list();
	return 0;
}
*/

/*
class Test;//ǰ������
class A {
	friend void fun(const Test &t, const A &a);
private:
	int m_a = 0;
};

class Test {
	friend void fun(const Test &t, const A &a);
	friend ostream& operator<<(ostream &out, const Test &t);
	friend istream& operator>>(istream &in, Test &t);
public:
	Test(int data = 0) :m_data(data) {}
	~Test() {}
private:
	int m_data;
};

void fun(const Test &t, const A &a) {//һ�����������Ƕ�������Ԫ����
	cout << "data = " << t.m_data << endl;
}

ostream& operator<<(ostream &out, const Test &t) {
	out << t.m_data;
	return out;
}

istream& operator>>(istream &in, Test &t) {
	in >> t.m_data;
	return in;
}

void main() {
	Test t;
	A a;
	cin >> t;
	cout << "t = " << t << endl;
}
*/

/*
class Test {
public:
	//���﷨����˵����������������Ϊ��Ա����,ֻ����ʹ��ʱ����t<<cout
	ostream& operator<<(ostream &out) {
		out << m_data;
		return out;
	}
	Test(int data = 0) :m_data(data)
	{}
	~Test()
	{}
private:
	int m_data;
};

void main() {
	Test t(1);
	cout << "t = ";
	t << cout << endl;//t.operator<<(cout)
}
*/

//�ڴ����
/*
void main() {
	int *p1 = (int *)malloc(sizeof(int) * 10);//C����
	if (p1 = NULL) {
		return;
	}
	free(p1);

	int *p2 = new int[10];//new��ʼ��
	delete[]p2;
}*/

class Test {
public:
	Test() {
		cout << "Creat Test Object." << endl;
	}
	~Test() {
		cout << "Free Test Object." << endl;
	}
public:
	void InitTest(int data = 0) {
		cout << "Init Test." << endl;
		m_data = data;
	}
	void DestroyTest(){
		cout << "Destroy Test." << endl;
	}
private:
	int m_data;
};
//C++
int main() {
	Test *pt = new Test;//1.����ռ�  2.�������캯��
	delete pt;//1.�ݻٶ���   2.�ͷſռ�
	return 0;
}

//C����
/*
int main() {
	Test *pt = (Test*)malloc(sizeof(Test));
	if (pt == NULL)
		return;
	pt->InitTest(1);
	pt->DestroyTest();
	free(pt);
	return 0;
}
*/