#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)  
using namespace std;
#define Maxsize 10001
typedef struct UserNode{
	int rank;//�ܷ���ͬ������һ��
	int id;
	int p[5];
	int Perfect;
	int Sum;
	int flag;//�������е��û������й��ύ��δ����Ĳ������������Ҫ�и�flag
	UserNode() :rank(0),id(-1), Perfect(0), Sum(0), flag(0) {
		for (int i = 0; i < 5; i++) {
			p[i] = -2;//�ύ��û�б���ͨ���Ļ����0��û���ύ��Ϊ-���ύ��0�ֻ���0,���-2�������ʱ������
		}
	}

}Users[Maxsize];

bool cmp(UserNode& u1,UserNode& u2) {
	if (u1.flag != u2.flag)
		return u1.flag > u2.flag;
	else if (u1.Sum != u2.Sum)
		return u1.Sum > u2.Sum;
	else if (u1.Perfect != u2.Perfect)
		return u1.Perfect > u2.Perfect;
	else if (u1.id != u2.id)
		return u1.id < u2.id;
};


int main()
{
	Users U;
	int N, K, M;
	cin >> N >> K >> M;
	int Pmax[5];
	for (int i = 0; i < K; i++) {
		cin >> Pmax[i];
	}
	for (int i = 0; i <= N; i++) {
		U[i].id = i;
	}
	/*������Ϣ*/
	int id, pro_id, pro_score;
	for (int i = 0; i < M; i++) {
		cin >> id >> pro_id >> pro_score;
		if (U[id].p[pro_id-1]<pro_score) {
			U[id].p[pro_id - 1] = pro_score;
			/*
			if (pro_score >= 0)U[id].p[pro_id - 1] = pro_score;
			if (pro_score == -1)U[id].p[pro_id - 1] = 0;
			*/
		}
	}
	int TotalPerson = 0;
	/*ͳ����Ϣperfect,sum,flag,��������������*/
	for (int i = 1; i <= N; i++) {
		/*perfect*/
		for (int j = 0; j < K; j++) {
			if (U[i].p[j] == Pmax[j]) {
				U[i].Perfect++;
			}
		}
		/*Sum*/
		for (int j = 0; j < K; j++) {
			if (U[i].p[j] >= 0) {
				U[i].Sum = U[i].Sum + U[i].p[j];
				if (U[i].Sum>0) {
					U[i].flag = 1;//�зֵĲŲ�������������û��ͨ��������û�ֵĲ�����
				}
			}
		}
		if (U[i].flag == 1)TotalPerson++;
	}
	sort(U + 1, U + N + 1, cmp);
	/*����rank*/
	U[1].rank = 1;
	for (int i = 2; i <= N; i++) {
		if (U[i].Sum == U[i - 1].Sum) {
			U[i].rank = U[i - 1].rank;
		}
		else
			U[i].rank = i;
	}
	if (TotalPerson == 0)TotalPerson = 1;//�������һ����
	for (int i = 1; i <=TotalPerson; i++) {
		printf("%d %05d %d", U[i].rank, U[i].id, U[i].Sum);
		for (int j = 0; j < K; j++) {
			if (U[i].p[j] >= 0)cout << " " << U[i].p[j];
			else if (U[i].p[j] == -1)cout << " 0";
			else if (U[i].p[j] == -2)cout << " -";
		}
		cout << endl;
	}

	return 0;
}