#include<iostream>
using namespace std;
int digit[100];

int main() {
	int A, B,D;//ʮ������
	cin >> A >> B>>D;
	int sum = A + B;//sumΪʮ���ƣ�����ת��ΪD����

	int cnt = 0;
	do {
		digit[cnt++] = sum%D;
		sum = sum / D;
	} while (sum!=0);
	for (int i = cnt - 1; i >= 0; i--) {
		cout << digit[i];
	}

	return 0;
}