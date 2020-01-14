#include <iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#pragma warning(disable: 4996)  
using namespace std;
#define MaxTelNum 11
#define MaxSize 200000
typedef char Elementype[MaxTelNum+1];
typedef struct ListNode* List;
typedef struct HashNode* HashTable;
typedef int Index;
typedef Index Position;
struct ListNode {
	Elementype key;
	int times;
	List next;
	ListNode() :times(0), next(NULL) {};
};
struct HashNode {
	int Size;
	List heads;
};

int NextPrime(int N) {
	int res,i;
	int IsPrime=1;
	res = (N % 2) ? N + 2 : N + 1;
	while (1) {
		IsPrime = 1;
		for (i = 2; i*i<=res; i++) {
			if (res%i == 0) {
				IsPrime = 0; break;
			}
		}
		if (IsPrime == 1)
			break;
		else
			res = res + 2;
	}
	return res;
}

Index Hash(Elementype key,HashTable H) {
	int TableSize = H->Size;
	Index pos = atoi(key + 6)%TableSize;
	return pos;
}

List FindElement(Elementype key, HashTable H) {
	Index Pos;
	List tmp=NULL;
	Pos = Hash(key, H);
	tmp = H->heads[Pos].next;
	while (tmp != NULL) {
		if (strcmp(key, tmp->key) == 0) break;
		else tmp = tmp->next;
	}
	return tmp;
}

void InsertHashTable(Elementype key, HashTable H) {
	List PosToInsert, tmp;
	Index Pos;
	Pos = Hash(key, H);
	PosToInsert = FindElement(key, H);
	if (PosToInsert != NULL) {
		PosToInsert->times++;
	}
	else {
		PosToInsert = new ListNode;
		PosToInsert->next = H->heads[Pos].next;
		strcpy(PosToInsert->key, key);
		PosToInsert->times = 1;
		H->heads[Pos].next = PosToInsert;
	}
}

HashTable BuildHashTable(HashTable H) {
	int N;
	Elementype tmp;
	cin >> N;
	int TableSize;
	TableSize = NextPrime(2*N);
	H->Size = TableSize;
	H->heads = new ListNode[TableSize];
	for (int i = 0; i < N; i++) {
		cin >> tmp; InsertHashTable(tmp, H);
		cin >> tmp; InsertHashTable(tmp, H);
	}
	return H;
}

void StaticHashTable(HashTable H) {
	/*遍历hashtable中的最大的数，并记录下最大节点*/
	List P;
	List tmp=NULL;
	int MaxTimes = 0;
	int count = 1;
	for (int i = 0; i < H->Size; i++) {
		P = H->heads[i].next;/*从每一个的头结点开始*/
		while (P != NULL) {
			if (MaxTimes < P->times) {
				MaxTimes = P->times;
				tmp = P;
				count = 1;
			}
			else if(MaxTimes == P->times) {
				tmp = strcmp(tmp->key, P->key) < 0 ? tmp : P;
				count++;
			}
			P = P->next;
		}
	}
	cout << tmp->key << " " << tmp->times;
	if (count != 1) {
		cout << " " << count;
	}
}

void DestroyTable(HashTable H) {
	List tmp1;
	List tmp2;
	for (int i = 0; i < H->Size; i++) {
		tmp1 = H->heads[i].next;
		while (tmp1 != NULL) {
			tmp2 = tmp1->next;
			delete tmp1;
			tmp1 = tmp2;
		}
	}
	delete[]H->heads;
	delete H;
}

int main() {
	HashTable H= new HashNode;;/*没有经过初始化的指针没法传到函数中，因为函数不知道要复制什么*/
	H=BuildHashTable(H);
	StaticHashTable(H);
	return 0;
}