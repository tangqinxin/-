#include<iostream>
#include<algorithm>
#define maxsize 105
using namespace std;

char mat[maxsize][maxsize];
int vist[maxsize][maxsize];
char word[10] = "yizhong";
int n;
int dir[][2] = { {-1,0},{-1,-1},{-1,1},{0,1},{0,-1},{1,1},{1,0},{1,-1} };
struct node{
	int x;
	int y;
}path[2*maxsize];

void dfs(int curx,int cury,node p[],int k,int curstep) {
	//��[curx,cury]��ʼ��k�������������curstep��ʾֱ��word[curstepΪֹ��ƥ�����
	if (curstep == 7) {
		//����ķ����ص���ֱ����β�Ž���ͳһ��¼
		for (int i = 0; i < 7; i++) {
			int x = p[i].x;
			int y = p[i].y;
			vist[x][y] = 1;
		}
		return;
	}
	
	int NextX = curx + dir[k][0];
	int NextY = cury + dir[k][1];
	if (curstep==6||mat[NextX][NextY] == word[curstep + 1]) {//curstep����6����ҪĿ����Ϊ�˼�¼��λ��
		p[curstep].x = curx;
		p[curstep].y = cury;
		dfs(NextX, NextY, p, k, curstep + 1);
	}

}

void Search(char Mat[][maxsize], char wrd[]){
	//��Mat�����������ַ���wrd�����ϵı��Ϊ1
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Mat[i][j] == wrd[0]) {
				for (int k = 0; k < 8; k++) {
					int dx = i + dir[k][0];
					int dy = j + dir[k][1];
					if (Mat[dx][dy] == wrd[1]) {
						dfs(i, j, path, k, 0);
					}
				}
			}
		}
	}
}

void disp(int vst[][maxsize]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vst[i][j] == 1)cout << mat[i][j];
			else if (vst[i][j] == 0)cout << "*";
		}
		cout << endl;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	Search(mat, word);
	disp(vist);
	return 0;
}