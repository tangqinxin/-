#include<iostream>
using namespace std;
int main() {
	char expression[300];
	cin >> expression;

	int flag = 0;
	for (int i = 0; expression[i] != '\0'; i++) {
		if (expression[i] == '(')flag++;
		if (expression[i] == ')')flag--;
		if (flag < 0)break;
	}
	if (flag == 0)cout << "YES";
	else cout << "NO";
	return 0;
}