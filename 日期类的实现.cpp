#include <iostream>
using namespace std;

class Date{
	friend ostream& operator<<(ostream &out, const Date &d);
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month) {
		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[month];
		//��������¼�1��
		if (month = 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
			day += 1;
		}
		return day;
	}
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1) {
		if (year < 1900 || month<1 || day < 1 || month>12 || day>GetMonthDay(year, month)) {
			cout << "����������ڲ��Ϸ���" << endl;
		}
		_year = year;
		_month = month;
		_day = day;
	}
	// �������캯��
    // d2(d1)
	Date(const Date& d) {
		_year =d._year;
		_month = d._month;
		_day = d._day;
	}
	// ��ֵ���������
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d) {
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	// ��������
	~Date()
	{}
	// ����+=����
	Date& operator+=(int day) {
		if (day < 0) {
			return *this -= _day;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month)) {
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13) {
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	// ����+����   ��+=��������ǲ������Լ�
	Date operator+(int day) {
		Date ret(*this);
		ret += day;
		return ret;
	}
	// ����-����
	Date operator-(int day) {
		Date ret(*this);
		ret -= day;
		return ret;
	}
	// ����-=����
	Date& operator-=(int day) {
		if (day < 0) {
			return *this += _day;
		}
		_day -= day;
		while (_day <= 0) {
			--_month;
			if (_month == 0) {
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	// ǰ��++
	Date& operator++() {
		*this += 1;
		return *this;
	}
	// ����++
	Date operator++(int) {
		Date tmp(*this);
		*this += 1;
		return tmp;
	}
	// ����--
	Date operator--(int) {
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}
	// ǰ��--
	Date& operator--() {
		*this -= 1;
		return *this;
	}
	// >���������
	bool operator>(const Date& d) {
		if (_year > d._year) {
			return true;
		}
		else if (_year == d._year) {
			if (_month > d._month) {
				return true;
			}
			else if (_month == d._month) {
				if (_day > d._day) {
					return true;
				}
			}
		}
		return false;
	}
	// ==���������
	bool operator==(const Date& d) {
		return _year == d._year && _month == d._month && _day == d._day;
	}
	// >=���������
	inline bool operator >= (const Date& d) {
		return *this > d || *this == d;
	}
	// <���������
	bool operator < (const Date& d) {
		return !(*this >= d);
	}
	// <=���������
	bool operator <= (const Date& d) {
		return !(*this > d);
	}
	// !=���������
	bool operator != (const Date& d) {
		return !(*this == d);
	}
	// ����-���� ��������
	int operator-(const Date& d) {
		int flag = 1;
		Date max = *this;
		Date min = d;
		if (*this < d) {
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max) {
			++(min);
			++day;
		}
		return day * flag;
	}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream &out, const Date &d) {
	out << d._year << "��" << d._month << "��" << d._day << "��";
	return out;
}

int main() {
	Date t1(1982, 12, 20);
	cout << "t1 = " << t1 << endl;
	Date t2 = t1;
	cout << "t2 = " << t2 << endl;
	Date t3;
	t3 = t2;
	cout << "t3 = " << t3 << endl;
	Date t4 = t1 + 100;
	cout << "t4 = " << t4 << endl;
	t1 += 100;
	cout << "t1 = " << t1 << endl;
	
	return 0;
}