#include<iostream>
#define MaxSize 100000
#define Radix 10
#define MaxDigit 10
/*��������10^10*/
int a[MaxSize];

using namespace std;
typedef struct Node* PtrToNode;
struct Node {
	int key;
	PtrToNode next;
	Node(int x):key(x),next(NULL){}
};

struct BucketNode {
	PtrToNode head;
	BucketNode():head(NULL){}
};

typedef struct BucketNode Bucket[Radix];

void GetData(int a[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
}

void swap(int* val1, int* val2) {
	int tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

void DispArr(int a[], int N) {
	cout << a[0];
	N--;
	int i = 1;
	while (N--) {
		cout << " " << a[i++];
	}
}

PtrToNode ArrToList(int a[], int N) {
	/*������ת��Ϊһ�����������������ָ��*/
	PtrToNode tmp, List;
	List = NULL;
	for (int i = 0; i < N; i++) {
		tmp = new Node(a[i]);
		tmp->next = List;
		List = tmp;
	}
	return List;
}

int GetDigit(int x,int D) {
	/*������x��ȡ��Dλ������*/
	int d;
	for (int i = 1; i <= D; i++) {
		d = x%Radix;
		x = x / Radix;
	}
	return d;
}
/*---------------------------����Ͱ------------------------------*/
void InsertNodeToBucket(PtrToNode& List,Bucket B,int D) {
	/*���ڵ�List���뵽Bucket B�ĵ�D��Ͱ*/
	PtrToNode tmp;
		tmp=List->next;
		List->next = B[D].head;
		B[D].head = List;
		List = tmp;
}

void ListToBucket(PtrToNode& List, Bucket B, int D) {
	/*����D����List�е�ֵ���뵽Bucket B��*/
	PtrToNode& Ptr2ListNode=List;
	int d;
	while (Ptr2ListNode != NULL) {
		d = GetDigit(Ptr2ListNode->key, D);
		InsertNodeToBucket(Ptr2ListNode, B, d);
	}
}

void BucketToList(PtrToNode& List, Bucket B, int Di) {
	/*����Di��Ͱ�е�Ԫ�ز��뵽����List��*/
	PtrToNode tmp;
	while (B[Di].head != NULL) {
		if (List == NULL) {
			List = B[Di].head;
			B[Di].head = B[Di].head->next;
			List->next = NULL;
		}
		else {
			tmp = B[Di].head;
			B[Di].head = B[Di].head->next;
			tmp->next = List;
			List = tmp;
		}
	}
}

void ListToArr(PtrToNode List, int a[], int N) {
	PtrToNode tmp = List;/*��¼�µ�ַ�������ͷſռ�*/
	for (int i = 0; i < N; i++) {
		a[i] = List->key;
		List = List->next;
	}
	delete[]tmp;
}
/*----------------------------����------------------------------*/
void LSDRadixSort(int a[], int N) {
	PtrToNode List;
	List = ArrToList(a, N);
	int D,Di;
	Bucket B;
	/*����ʼ,DҪһֱѭ����ֱ��������йؼ���Ϊֹ*/
	for (D = 1; D <= MaxDigit; D++) {
		/*����D���������е������뵽Ͱ��*/
		ListToBucket(List,B,D);
		/*��Ͱ��������Ϊ�˷���������룬��������һ��Ͱ��ʼ���������*/
		List = NULL;
		for (Di = Radix-1; Di>=0; Di--) {
			BucketToList(List,B,Di);
		}
	}
	ListToArr(List, a, N);
}

struct NewStr {
	int x;
	int y;
};
typedef NewStr NS_10[10];
//void test(NS_10 b)//��ȷд��1
//void test(NewStr* b)//��ȷд��2
//void test(NS_10 b[])//����д��
void test(NS_10 b) {
	for (int i = 0; i < 10; i++) {
		b[i].x = 2 * i;
	}
}

int main() {
	int N;
	cin >> N;
	GetData(a, N);
	LSDRadixSort(a, N);
	DispArr(a, N);
	/*
	NS_10 b;
	for (int i = 0; i < 10; i++) {
		b[i].x = i;
	}
	test(b);
	for (int i = 0; i < 10; i++) {
		cout << b[i].x << endl;
	}
	*/
	return 0;
}