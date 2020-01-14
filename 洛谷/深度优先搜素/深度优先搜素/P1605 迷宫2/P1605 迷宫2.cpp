#include<iostream>//���˽��鲻ʹ������ͷ�ļ������Ҫʹ������ͷ�ļ����Ͳ��ܶ�������map��
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int map[6][6];//��ͼ��
bool temp[6][6];//�߹��ı�ǣ�
int dx[4] = { 0,0,1,-1 };//���
int dy[4] = { -1,1,0,0 };//���
int total, fx, fy, sx, sy, T, n, m, l, r;//total��������fx��fy���յ����꣬sx��sy��������꣬T���ϰ�������n��m�ǵ�ͼ�ĳ��Ϳ�l��r���ϰ��ĺ�����������ꣻ
void walk(int x, int y)//����walk��
{
	if (x == fx&&y == fy)//fx��ʾ����x���꣬fy��ʾ����y���ꣻ
	{
		total++;//�������ӣ�
		return;//���أ�����������
	}
	else
	{
		for (int i = 0; i <= 3; i++)//0����3�����ң��£����ĸ�����
		{
			if (temp[x + dx[i]][y + dy[i]] == 0 && map[x + dx[i]][y + dy[i]] == 1)//�ж�û���߹���û���ϰ���
			{
				temp[x][y] = 1;//�߹��ĵط����ϱ�ǣ�
				walk(x + dx[i], y + dy[i]);
				temp[x][y] = 0;//��ԭ״̬��
			}
		}
	}
}
int main()
{
	cin >> n >> m >> T;//n��m���ȿ�ȣ�T�ϰ����� 
	for (int ix = 1; ix <= n; ix++)
		for (int iy = 1; iy <= m; iy++)
			map[ix][iy] = 1;//�ѵ�ͼˢ��1��
	cin >> sx >> sy;//��ʼx��y 
	cin >> fx >> fy;//����x��y 
	for (int u = 1; u <= T; u++)
	{
		cin >> l >> r;//l��r���ϰ����ꣻ
		map[l][r] = 0;
	}
	walk(sx, sy);
	cout << total;//���������
	return 0;
}