#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
#define maxsize 505
int G[maxsize][maxsize];//��Ȩ
int dist[maxsize];//���·����¼����c1����������ĵ�Դ���·��
bool visit[maxsize] = { false };
int CityWeight[maxsize];//��Ȩ���ݺ�
int CityWeightSum[maxsize];//��Ȩ�ʹ�c1��c2
int Count[maxsize];//���·����
int  N, M, c1, c2;

int FindMinDist(int Dist[]) {
	int mindist = INT_MAX;
	int minindex = -1;
	for (int i = 0; i < N; i++) {
		if (visit[i]==false&&dist[i] < mindist) {
			mindist = dist[i];
			minindex = i;
		}
	}
	return minindex;
}


void Dijkstra(int s) {
	//��Դ���·����Ҫ����µ���������·����������̱�Ȩ���Լ�����Ȩ��

	//��ʼ��Count[]�����·����Count[]����ȨCityWeight[]
	memset(Count, 0, sizeof(Count));
	Count[c1] = 1;//���������·����ʼ��Ϊ1
	//��ʼ��CityWeightSum[]����Ȩ��
	fill(CityWeightSum, CityWeightSum + maxsize, 0);//��ʼ��Ϊ0
	CityWeightSum[c1] = CityWeight[c1];//����ʼ��Ϊ��ʼֵ
	//��ʼ�����·������
	fill(dist, dist + maxsize, INT_MAX);
	dist[c1] = 0;

	for (int i = 0; i < N; i++) {//ѭ��N��
		//Ѱ����С·��
		int u = FindMinDist(dist);//�ҵ�·�����

		if (u == -1) {
			break;//�Ѿ��Ҳ����ˣ���ô������
		}
		
		//����ǺϷ���u��ô�����¼Ϊ���ʹ�
		visit[u] = true;
		for (int v = 0; v < N; v++) {//ö���н��u���ڱ�,���и���
			if (visit[v]==false&&G[u][v] != INT_MAX) {
				if (G[u][v]+dist[u]<dist[v]) {
					dist[v] = dist[u] + G[u][v];
					Count[v] = Count[u];
					CityWeightSum[v] = CityWeightSum[u] + CityWeight[v];
				}
				else if (dist[u]+G[u][v]==dist[v]) {
					Count[v] += Count[u];
					CityWeightSum[v] = max(CityWeightSum[v], CityWeightSum[u] + CityWeight[v]);//�Ƚ�ѡ��������һ��
				}
			}
		}
	}
	
}

int main() {
	scanf("%d %d %d %d", &N, &M, &c1, &c2);
	for (int i = 0; i < N; i++) {
		scanf("%d",&CityWeight[i]);
	}

	fill(G[0], G[0] + maxsize*maxsize, INT_MAX);//��άͼ��ʼ��
	for (int i = 0; i < M; i++) {
		int u, v,edge;
		scanf("%d %d %d", &u, &v, &edge);
		G[u][v] = edge;
		G[v][u] = edge;
	}
	Dijkstra(c1);
	printf("%d %d", Count[c2], CityWeightSum[c2]);

	return 0;
}