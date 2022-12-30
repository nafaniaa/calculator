#include "defoult.h"
//������ ��������� ,string -- ��� ������ ������� ��������� � �������� ����� ,
// double -- ��� ������ ����������� � �������� 
map<string, double(*)(double)> operationsun{ {"sqr",square},{"sqrt",squareRoot} };
map<string, double(*)(double, double)> operationsbin{ {"+",add}, {"*",multiplication}, {"-",minus},{"/",division} };

// ��������
double add(double firstnum, double secondvalue) {
	return  firstnum + secondvalue;
}

//���������
double multiplication(double  firstnum, double secondnum) {
	return  firstnum * secondnum;
}

//��������� 
double minus(double  firstnum, double secondnum) {
	return  firstnum - secondnum;
}

//�������
double division(double  firstnum, double secondnum) {
	return  firstnum / secondnum;
}

//���������� � �������
double square(double num) {
	return num * num;
}

//���������� �����
double squareRoot(double num) {
	double l = 0;
	double r = 1e4;
	while (r - l > 0.000000001) {
		double m = (r + l) / 2;
		if (num - m * m >= 0.000000001) {
			l = m;
		}
		else {
			r = m;
		}
	}
	return l;
}

//���������� ���������
double reverseElement(double num) {
	return 1 / num;
}

//����������
void defoult() {
	cout << "choose the operation\n";
	string s;
	cin >> s;
	if (operationsbin.count(s)) {
		cout << "enter numbers\n";
		double first, second;
		cin >> first >> second;
		cout << operationsbin[s](first, second);
		return;
	}
	if (operationsun.count(s)) {
		cout << "enter number\n";
		double numm;
		cin >> numm;
		cout << operationsun[s](numm);
		return;
	}
	cout << "Operation isn't  found\n";
}