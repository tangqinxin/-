#include<iostream>
#define MaxSize 100000
#define Radix 10
#define MaxDigit 10
/*长整形是10^10*/
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
	/*将数组转化为一条链表，并返回链表的指针*/
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
	/*对整数x获取第D位的数字*/
	int d;
	for (int i = 1; i <= D; i++) {
		d = x%Radix;
		x = x / Radix;
	}
	return d;
}
/*---------------------------插入桶------------------------------*/
void InsertNodeToBucket(PtrToNode& List,Bucket B,int D) {
	/*将节点List插入到Bucket B的第D个桶*/
	PtrToNode tmp;
		tmp=List->next;
		List->next = B[D].head;
		B[D].head = List;
		List = tmp;
}

void ListToBucket(PtrToNode& List, Bucket B, int D) {
	/*根据D，将List中的值插入到Bucket B中*/
	PtrToNode& Ptr2ListNode=List;
	int d;
	while (Ptr2ListNode != NULL) {
		d = GetDigit(Ptr2ListNode->key, D);
		InsertNodeToBucket(Ptr2ListNode, B, d);
	}
}

void BucketToList(PtrToNode& List, Bucket B, int Di) {
	/*将第Di个桶中的元素插入到链表List中*/
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
	PtrToNode tmp = List;/*记录下地址，方便释放空间*/
	for (int i = 0; i < N; i++) {
		a[i] = List->key;
		List = List->next;
	}
	delete[]tmp;
}
/*----------------------------排序------------------------------*/
void LSDRadixSort(int a[], int N) {
	PtrToNode List;
	List = ArrToList(a, N);
	int D,Di;
	Bucket B;
	/*排序开始,D要一直循环，直到完成所有关键字为止*/
	for (D = 1; D <= MaxDigit; D++) {
		/*按照D，将链表中的数插入到桶中*/
		ListToBucket(List,B,D);
		/*将桶插入链表；为了方便链表插入，这里从最后一个桶开始往链表插入*/
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
//void test(NS_10 b)//正确写法1
//void test(NewStr* b)//正确写法2
//void test(NS_10 b[])//错误写法
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