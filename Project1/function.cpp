#include "function.h"
#include<iostream>
using namespace std;

//возведение в степень через перегрузку
double PowToNaturalDegree(int degree, int num) {
	int res = 1;
	while (degree) {
		if (degree & 1)
			res *= num;
		num *= num;
		degree >>= 1;
	}
	return res;
}
double PowToNaturalDegree(int degree, double num) {
	
	if (degree == 0)
		return 1;
	if (degree % 2 == 1)
		return PowToNaturalDegree(degree - 1, num) * num;
	else {
		int b = PowToNaturalDegree(degree / 2, num);
		return b * b;
	}
}
double factorial(int n) {
	double res = 1;
	for (int i = 2; i <= n; i++) {
		res *= i;
	}
	return res;
}