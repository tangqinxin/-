#include<iostream>
#include "addfun.h"//只需包含头文件
using namespace std;
using namespace StructureLine;

enum MyEnum
{
	MYFALSE,
	MYTRUE
};

bool modfun(int testval, int modval);

int main() {

	int a = 1;
	int b = 2;
	cout << myadd(a, b)<<endl;

	f_mod f3(3);

	bool(*p)(int, int);

	p = modfun;
	cout << p(3, 3) << endl;
	cout << (*p)(3, 3) << endl;

	return 0;
}

bool modfun(int testval, int modval) {
	return testval%modval==0;
}