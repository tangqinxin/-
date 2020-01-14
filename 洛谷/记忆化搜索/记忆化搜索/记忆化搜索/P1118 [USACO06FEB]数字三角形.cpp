#include<iostream>
#include<algorithm>
#define maxsize 15
using namespace std;
int n, target;
int used[maxsize];
int ans[maxsize];
int res[maxsize];
int table[maxsize][maxsize];
bool flag = false;

//�������ɹ�ʽ�������㸴�Ӷȴ�n^2����n
void buildtable(int n) {
	table[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j < i) {
				table[i][j] = table[i - 1][j] + table[i - 1][j - 1];
			}
			else if (i == j) {
				table[i][j] = 1;
			}
		}
	}
}


bool ansIsOk(int n,int targetval) {
	//����ans�е�n�����ĵ�ǰ����Ƿ�����targetval
	//ans[1,n]�ļ��㣬һ������n��
	int tmp[maxsize];
	for (int i = 1; i <= n; i++) {
		tmp[i] = ans[i];;//��������
	}
	for (int i = n-1; i >=1 ; i--) {
		for (int j = 1; j <= i; j++) {
			tmp[j] = tmp[j] + tmp[j + 1];
		}
	}
	return tmp[1] == targetval;//�ж��Ƿ���ھ���ֵ
}

//���������Ĺؼ������ʹ��ansIsOk()��������õ���
bool ansIsOk2(int currow, int targetval) {
	int res = 0;
	for (int i = 1; i <= currow; i++) {
		res += table[currow][i] * ans[i];
	}
	return res == targetval;
}

bool PreJudgeNotOk(int currow) {
	if (currow < n + 1) {
		int res = 0;
		for (int i = 1; i < currow; i++) {
			res += table[n][i] * ans[i];
		}
		if (res >= target) {
			return true;
		}
	}
	return false;
}


void dfs(int row) {
	//����Ŀ����Ȼ����ö�٣����жϡ������ö�����Ȱ��������г�����������ȥ������������Ƿ�����Ҫ��(��Ϊ����Ҫ��
	//rowָ׼�����row�������Ѿ����row-1����
	if (row < n + 1) {
		if (PreJudgeNotOk(row)) {
			return;
		}
	}

	if (row == n + 1) {
		if (ansIsOk2(n,target)) {
			flag = true;
			for (int i = 1; i <= n; i++) {
				res[i] = ans[i];
			}
			return;
		}
	}

	for (int i = 1; i <= n; i++) {//�˴�Ϊö�ٿ�����
		if (flag == true) {
			break;//����Ѿ��ҵ���С�����У�ֱ������
		}
		if (used[i] != 1) {
			used[i] = 1;
			ans[row] = i;//�˴�Ϊ�������Դ��뵱ǰ�Ľ�㣬��row���
			dfs(row + 1);
			used[i] = 0;
		}
	}
}

int main() {
	cin >> n >> target;
	//������������
	buildtable(n);
	dfs(1);//�ӵ�1�������е����һ����
	if (flag == true) {
		for (int i = 1; i <= n; i++) {
			cout << res[i] << " ";
		}
	}
	else if (flag == false) {

	}
	return 0;
}