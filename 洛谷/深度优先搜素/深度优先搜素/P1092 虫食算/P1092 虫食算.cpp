#include<iostream>
#include<cstring>
using namespace std;
int n;
int words[3][30];//��¼����ʽ��ֵ
int used[30];//����ÿ����ĸ��Ψһֵ���������hash���в�ѯ�Ƿ��Ѿ���ʹ��
int res[30];//����ö�ٴ𰸣�0-25��Ӧ��A-Z��26��Ӣ����ĸ
int finalres[30];//������¼���մ�


void dfs(int row,int col,int carry) {
	//���ö��Ӧ����ö������Ϊ������Ȼ��ȥ�ƽ�����

	if (col<0&&carry==0) {
		for (int i = 0; i < n; i++) {
			finalres[i] = res[i];
		}
		return;
	}

	for (int i = col; i >= 0; i--) {
		//���ѭ���Ĵ�����Ϊ�˼�����Щ�Ѿ�ö�ٹ��ģ������ں�������в����ϵ����
		int num1 = res[words[0][i]];
		int num2 = res[words[1][i]];
		int num3 = res[words[2][i]];
		if (num1 == -1 || num2 == -1 || num3 == -1) continue;//���ﵱʱ���߼�����ô�뵽��continue��	
		int sum = num1 + num2;
		if (sum%n != num3 && (sum + 1) % n != num3) return;//�����һ�������ϣ���ôһ���ǲ������
	}

	if (res[words[row][col]] == -1) {
		//�����ǰֵ�ǲ����ڵģ�Ҳ����˵���ֵ��û�б�����,��ô����Ҫö�����ֵ
		for (int i = 0; i <n; i++) {
			if (!used[i]) {//ĳ������û�б�ʹ��,��ô�����ڵ�ǰ��ö���������,��if�п��ԶԵ�ǰ���ҵ���߼�����if����
				if (row != 2) {//���û��ö����ϣ���ô������Ҫ��������row�Ĳ�����ֱ��3��ȫ���������ܼ���
					used[i] = 1;
					res[words[row][col]] = i;
					dfs(row + 1, col, carry);
					used[i] = 0;
					res[words[row][col]] = -1;
				}
				else if (row == 2) {
					//�����֧��Ȼ��Ҫ��䣬ֻ�����Ĺ����ּ��˼�֦(ɸѡ),�����Ҿ�����ʵ���ã���Ϊǰ���Ѿ�������
					int sum = res[words[0][col]] + res[words[1][col]] + carry;
					if (sum%n != i)continue;
					used[i] = 1;
					res[words[row][col]] = i;
					dfs(0, col - 1, sum / n);
					used[i] = 0;
					res[words[row][col]] = -1;
				}
			}
		}
	}
	else if(res[words[row][col]]!=-1){
		//�����ǰ��ֵ�Ѿ����ˣ��ǾͲ���Ҫ�����ˣ�ֱ�Ӹ��ݲ������и���ı���
		if (row != 2) {
			dfs(row + 1, col, carry);
		}
		else if (row == 2) {
			int sum = res[words[0][col]] + res[words[1][col]] + carry;
			if (sum%n != res[words[row][col]])return;
				dfs(0, col - 1, sum / n);
		}
	}
}

void display() {
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cout << finalres[i];
		}
		else {
			cout << " " << finalres[i];
		}
	}
}

int main() {
	memset(res, -1, sizeof(res));//��Ϊ-1��˵��û��ֵ��������Ϊ0����Ϊ0Ҳ����Ч��
	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			char ch;
			cin >> ch;
			words[i][j] = ch - 'A';//����ĸת��Ϊ���ֱ��
		}
	}
	dfs(0, n - 1, 0);
	display();
	return 0;
}