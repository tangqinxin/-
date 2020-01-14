#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define maxSize 10
#define Null -1
/*����һ�����Ľṹ*/
struct Tree {
	int element;
	int left;
	int right;
}T[maxSize];

/*����һ������*/
struct TreeQueue {
	int front;
	int rear;
	int* data;
};

typedef struct TreeQueue* Queue;
int N;
/*��������,Ҫ�����N��Ȼ����������N���ַ����洢������˳�������У�����int��ͷ�ڵ�����,�ڵ���Ŵ�0��ʼ��
��������洢��Ŵ�0��ʼ*/
int creatTree(struct Tree T[]) {

	int check[maxSize];
	for (int i = 0; i < maxSize; i++) check[i] = 0;
	scanf("%d", &N);
	if (N<0 || N>maxSize) return Null;
	char l, r;
	if (N) {
		for (int i = 0; i < N; i++) {
			scanf("%c %c\n", &l, &r);
			if (l != '-') {
				T[i].left = l - '0';
				check[T[i].left] = 1;
			}
			else {
				T[i].left = Null;
			}
			if (r != '-') {
				T[i].right = r - '0';
				check[T[i].right] = 1;
			}
			else {
				T[i].right = Null;
			}
		}
		for (int i = 0; i < N; i++) {
			if (check[i] == 0) {
				return i;
			}
		}
	}
	return Null;/*N<0����-1��û�нڵ�*/
}

/*���ɶ���,���ض��У��˴��Ķ�����һ��ָ�룬����������*/
Queue CreateQueue() {
	Queue s = (Queue)malloc(sizeof(struct TreeQueue));
	s->data = (int*)malloc(sizeof(maxSize*sizeof(int)));
	s->front = -1;
	s->rear = -1;
	return s;
}
/*�ж϶����Ƿ��ǿյ�*/
int IsEmpty(Queue s) {
	if (s->front == s->rear) {
		return 1;
	}
	else
		return 0;
}

/*Ԫ��item�����*/
void Add(Queue s, int item) {
	if ((s->rear + 1) % maxSize == s->front) {
		return;
	}
	else {
		s->rear = (s->rear + 1) % maxSize;
		s->data[s->rear] = item;
		return;
	}
}
/*ɾ������Ԫ��,Ҫ�󷵻�ɾ���Ķ��е�Ԫ��*/
int Delete(Queue s) {
	if ((s->front + 1) % maxSize == s->rear) {
		return;
	}
	else {
		s->front = (s->front + 1) % maxSize;
		return s->data[s->front];
	}
}

/*�������������,ֻҪ�����Ҷ�ӽڵ�����*/
void LevelOrderTraversal(int root) {
	Queue s;
	int t = root, count = 0;
	if (t == -1)return;//���������ֱ�ӷ���
	s = CreateQueue();//����һ������
	Add(s, t);//���ڵ����
	while (!IsEmpty(s)) {//ѭ��ֱ�����п�
		t = Delete(s);
		count++;
		if (T[t].left != -1 && T[t].right == -1) {
			Add(s, T[t].left);
		}
		else if (T[t].left = -1 && T[t].right != -1) {
			Add(s, T[t].right);
		}
		else if (T[t].left != -1 && T[t].right != -1) {
			Add(s, T[t].left);
			Add(s, T[t].right);
		}
		else {
			if (count != N) {
				printf("%d ", t);
			}
			else {
				printf("%d", t);
			}
		}
	}
}

int main() {
	int r;
	/*���������ڵĵ�ַ���������ĸ�����ַ*/
	r = creatTree(T);
	/*�������*/
	LevelOrderTraversal(r);

	return 0;
}