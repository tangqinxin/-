#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define maxSize 10
#define Null -1
/*定义一个树的结构*/
struct Tree {
	int element;
	int left;
	int right;
}T[maxSize];

/*定义一个队列*/
struct TreeQueue {
	int front;
	int rear;
	int* data;
};

typedef struct TreeQueue* Queue;
int N;
/*建树操作,要求读入N，然后连续读入N个字符，存储在树的顺序数组中，返回int的头节点的序号,节点序号从0开始，
树的数组存储序号从0开始*/
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
	return Null;/*N<0返回-1，没有节点*/
}

/*生成队列,返回队列，此处的队列是一个指针，类似于链表*/
Queue CreateQueue() {
	Queue s = (Queue)malloc(sizeof(struct TreeQueue));
	s->data = (int*)malloc(sizeof(maxSize*sizeof(int)));
	s->front = -1;
	s->rear = -1;
	return s;
}
/*判断队列是否是空的*/
int IsEmpty(Queue s) {
	if (s->front == s->rear) {
		return 1;
	}
	else
		return 0;
}

/*元素item入队列*/
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
/*删除队列元素,要求返回删除的队列的元素*/
int Delete(Queue s) {
	if ((s->front + 1) % maxSize == s->rear) {
		return;
	}
	else {
		s->front = (s->front + 1) % maxSize;
		return s->data[s->front];
	}
}

/*层序遍历二叉树,只要求输出叶子节点的序号*/
void LevelOrderTraversal(int root) {
	Queue s;
	int t = root, count = 0;
	if (t == -1)return;//空树的情况直接返回
	s = CreateQueue();//建立一个队列
	Add(s, t);//根节点入队
	while (!IsEmpty(s)) {//循环直到队列空
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
	/*传入树所在的地址，返回树的根结点地址*/
	r = creatTree(T);
	/*层序遍历*/
	LevelOrderTraversal(r);

	return 0;
}