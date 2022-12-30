#include "defoult.h"
#include "scientific.h"
#include "function.h"
#include<iomanip>
using std::cin;
using std::cout;
map<string, void(*)()> selects{ {"defoult",defoult} };


int main() {
	//while (1) {
	//	cout << "choose the mode\n";
	//	string s;
	//	cin >> s;
	//	if (selects.count(s)) {
	//		selects[s]();
	//	}
	//	else {
	//		cout << "wrong mode";
	//	}
	//}
	//cout << setprecision(20) << myarcch(1);
	//cout << mych(0);
	return 0;
}