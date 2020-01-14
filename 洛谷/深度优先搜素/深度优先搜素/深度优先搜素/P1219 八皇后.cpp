#include<iostream>
using namespace std;

int ans[100];
int column[100];
int rightupleftdown[100];
int leftuprightdown[100];
int n;
int total = 0;
int NumOfSol = 0;

void DispAns() {
	//��ӡ���
	if (total < 3) {
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	total++;
}

bool check(int row, int col) {
	//���row��column���Ƿ������Ϊһ����
	bool ColumnIsOk, RupLdown, LupRdown;
	ColumnIsOk = RupLdown = LupRdown = false;
	if (column[col] == 0)ColumnIsOk = true;
	if (rightupleftdown[row+col] == 0)RupLdown = true;
	if (leftuprightdown[row - col+n] == 0)LupRdown = true;
	return ColumnIsOk&&RupLdown&&LupRdown;
}

void Mark(int row, int col) {
	//��ӱ��
	column[col] = 1;
	rightupleftdown[row + col] = 1;
	leftuprightdown[row-col+n] = 1;
}

void CleanMark(int row, int col) {
	//������
	column[col] = 0;
	rightupleftdown[row + col] = 0;
	leftuprightdown[row - col + n] = 0;
}

void DFS(int row) {
	//part1 �ж��Ƿ񵽴�����β��
	if (row > n) {
		DispAns();
		NumOfSol++;
		return;
	}

	//part2 �жϵ�ǰ�ڵ����Χ
	for (int j = 1; j <= n; j++) {
		if (check(row, j)) {//[row,j]���ԷŻʺ�
			ans[row] = j;//��¼��
			Mark(row, j);//���
			DFS(row + 1);//��һ������
			CleanMark(row, j);//����һ�������������
		}
	}
}


int main() {
	cin >> n;
	DFS(1);
	cout << NumOfSol;
	return 0;
}