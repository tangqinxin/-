#include <iostream>
using namespace std;
typedef int ElemenType;
typedef struct HashNode* HashTable;
typedef enum{Legitimate,Empty,Deleted} CellState;
typedef enum{False,True} InsertResult;
typedef struct Cell* PtrToCell;
struct HashNode {
	int Size;
	PtrToCell Cells;
};
struct Cell {
	ElemenType key;
	CellState state;
	Cell() :key(0), state(Empty) {}
};

int NextPrime(int N) {
	int res = (N % 2) ? N + 2 : N + 1;
	int IsPrime = 1;
	while (1) {
		IsPrime = 1;
		for (int i = 2; i*i < res; i++) {
			if (res%i == 0)IsPrime = 0;
		}
		if (IsPrime == 1)break;
		res = res + 2;
	}
	return res;
}

HashTable BuildHashTable(int N) {
	HashTable H = new HashNode;
	int TableSize;
	TableSize = NextPrime(N);
	H->Size = TableSize;
	H->Cells = new Cell[TableSize];
	return H;
}

int HashTableInsert(HashTable H, ElemenType key) {
	InsertResult InsRes=False;
	int Initial_Ind = key%H->Size;//��ʼ���
	int Index;
	for (int i = 0; i < H->Size; i++) {
		Index = (Initial_Ind + i*i) % H->Size;
		if (H->Cells[Index].state == Empty) {
			H->Cells[Index].key = key;
			H->Cells[Index].state = Legitimate;
			InsRes = True;//�ɹ���Index����;
			break;
		}
	}
	if (InsRes == True) return Index;//�ɹ��򷵻��±�
	if (InsRes == False) return -1;//���ɹ�����-1
}

void BulkInsert(HashTable H, int M) {
	/*�ڹ�ϣ��H����������M����,����Ҫ�������Ӧ��״̬�����������ò���һ�������һ��*/
	ElemenType key;
	int Index;
	int IsFinal = 0;
	for (int i = 0; i < M ; i++) {
		cin >> key;
		Index=HashTableInsert(H, key);
		if (i == M - 1)IsFinal = 1;
		if (Index != -1) {
			cout << Index;
		}
		else {
			cout << "-";
		}
		if (IsFinal == 0)cout << " ";
	}
}

int main() {
	int M, N;
	cin >> M >> N;
	HashTable H = BuildHashTable(M);
	BulkInsert(H, N);
	return 0;
}