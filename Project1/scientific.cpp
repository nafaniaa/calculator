#include "scientific.h"
#include "function.h"
#include<iostream>
#include<iomanip>
using namespace std;

// модуль
double myabs(double num) {
	if (num < 0)
		num = 0 - num;
	return num;
}

//синус через тейлора 
double mysin(double num) {
	double cur = num;
	double prev = 0;
	double res = 0;
	int k = 1;
	bool IsMinus = 0;
	while (myabs(cur - prev) > 0.0000001) {
		if (IsMinus)
			res -= cur;
		else
			res += cur;
		IsMinus = !IsMinus;
		prev = cur;
		cur = cur * num * num / (k + 1) / (k + 2);
		k++;
		k++;
	}
	return res;
}


//косинус через тейлора
double mycos(double num) {
	double cur = 1;
	double prev = 0;
	double res = 0;
	int k = 0;
	bool IsMinus = 0;
	while (myabs(cur - prev) > 0.0000001) {
		if (IsMinus)
			res -= cur;
		else
			res += cur;
		IsMinus = !IsMinus;
		prev = cur;
		cur = cur * num * num / (k + 1) / (k + 2);
		k++;
		k++;
	}
	return res;
}

// тангенс 
double mytg(double num) {
	return mysin(num) / mycos(num);
}

//котангенс 
double myctg(double num) {
	return mycos(num) / mysin(num);
}

// гиперболический синус через Тейлора
double mysh(double num) {
	double cur = num;
	double prev = 0;
	double res = 0;
	int k = 1;
	while (myabs(cur - prev) > 0.0000001) {
		res += cur;
		prev = cur;
		cur = cur * num * num / (k + 1) / (k + 2);
		k++;
		k++;
	}
	return res;


}

//гиперболический косинус через Тейлора
double mych(double num) {
	double cur = 1;
	double prev = 0;
	double res = 0;
	int k = 0;
	while (myabs(cur - prev) > 0.0000001) {
		res += cur;
		prev = cur;
		cur = cur * num * num / (k + 1) / (k + 2);
		k++;
		k++;
	}
	return res;

	
}

// гиперболический тангенс
double mythx(double num) {
	return mysh(num) / mych(num);
}

//гиперболический котангенс
double mycthx(double num) {
	return mych(num) / mysh(num);
}

//секанс
double mysec(double num) {
	return 1 / mycos(num);
}
//косеканс
double mycsc(double num) {
	return 1 / mysin(num);
}
//Гиперболический секанс
double mysech(double num) {
	return 1 / mych(num);
}

//Гиперболический косеканс
double mycsch(double num) {
	return 1 / mysh(num);
}

//арксинус
double myarcsin(double num) {
	double l = -3.14 / 2;
	double r = 3.14 / 2;
	while (r - l > 0.00001) {
		double m = (r + l) / 2;

		if (mysin(m) >= num) {
			r = m;
		}
		else {
			l = m;
		}
	}
	return r;
}

//арккосинус
double myarccos(double num) {
	if (num < 0)
		return 3.14 / 2 + myarcsin(num);    
	return 3.14 / 2 - myarcsin(num);    
}

//арктангес
double myarctg(double num) {
	double l = -3.14 / 2;
	double r = 3.14 / 2;
	while (r - l > 0.00001) {
		double m = (r + l) / 2;
		if (mytg(m) >= num) {
			cout << m << mytg(m) << num<< "\n";
			r = m;
		}
		else {
			l = m;
		}
	}
	return r;
}

//арккотангенс
double myarcctg(double num) {
	if (num < 0) {
		return 3.14 / 2 + myarctg(num); 
	}
	return 3.14 / 2 - myarctg(num);
}

//арксеканс
double myarcsec(double num) {
	return myarccos(1 / num);
}

//арккосеканс
double myarccsc(double num) {
	return myarcsin(1 / num);
}

//обратные гиперболические функции 
double myarcsh(double num) {
	double l = -1e4;
	double r = 1e4;
	while (r - l > 0.00001) {
		double m = (r + l) / 2;

		if (mysh(m) >= num) {
			r = m;
		}
		else {
			l = m;
		}
	}
	return r;
}
double myarcch(double num) {
	double l = 0;
	double r = 7;
	while (r - l > 0.0001) {
		double m = (r + l) / 2;
		if (mych(m) > num) {
			r = m;
		}
		else {
			l = m;
		}
	}
	return l;
}

double myarcthx(double num) {
	double cur = num;
	double prev = 0;
	double res = 0;
	int k = 1;
	while (myabs(cur / k - prev / (k - 2)) > 0.0000001) {
		res += cur / k;
		prev = cur;
		cur = cur * num * num;
		k++;
		k++;
	}
	if (num < 0)
		return 0 - res; 
	return res;
}



double myarccsch(double num) {		   //arcschx = arsh(1/x)
	return myarcsh(1 / num);
}
double myarcsech(double num) {           //arsechx = arcch(1/x)
	return myarcch(1 / num);
}
double myarccthx(double num) {
	return myarcthx(1 / num);
}

//корень
double FindRoot(double num, int degree) {
	double l = 0;
	double r = num;
	while (r - l > 0.00000001) {
		double m = (r + l) / 2;
		double cur = PowToNaturalDegree(degree, m);
		if (cur >= num) {
			r = m;
		}
		else {
			l = m;
		}
	}
	return r;
}


//n!
double Fact(int value) {
	return factorial(value);
}


double myln(double num) {
	num--;
	int k = 2;
	double res = num;
	double cur = num * num;
	double prev = num;
	while (myabs(cur / k - prev / (k - 1)) > 0.00000001) {
		std::cout << prev / (k - 1) << " " << cur / k << " " << res << "\n";
		if (k & 1) {
			res += cur / k;
		}
		else {
			res -= cur / k;
		}
		prev = cur;
		k++;
		cur = cur * num;
	}
	return res;
}