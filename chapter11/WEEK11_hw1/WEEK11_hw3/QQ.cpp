#include <iostream>
#include<string.h>
#include <time.h>
#define ACCOUNTSIZE 11
#define PASSWORDSIZE 16
using namespace std;
typedef char Account[ACCOUNTSIZE+1];
typedef char PassWord[PASSWORDSIZE+1];
typedef struct HashNode* HashTable;
typedef struct ListNode* List;
#pragma warning(disable: 4996)  
struct HashNode {
	int Size;
	List heads;
};

struct ListNode {
	Account AC;
	PassWord PW;
	List Next;
	ListNode() :Next(NULL) {};
};

int NextPrime(int N) {
	int res;
	res = (N % 2) ? N + 2 : N + 1;
	int IsPrime = 1;
	while (1) {
		IsPrime = 1;
		for (int i = 2; i*i < res; i++) {
			if (res%i == 0) {
				IsPrime = 0;
				break;
			}
		}
		if (IsPrime == 1)break;
		res = res + 2;
	}
	return res;
}

HashTable BuildHashTable(int N) {
	HashTable H=new HashNode;
	int TableSize;
	TableSize = NextPrime(2*N);
	H->Size = TableSize;
	H->heads = new ListNode[TableSize];
	return H;
}

int Hash(HashTable H,Account AC) {
	/*atoi()是a码到int的转换，由于账户超过了长整形，因此这里转换为int可能有问题*/
	if(strlen(AC)>4) return atoi(AC+4)%H->Size;
	else return atoi(AC) % H->Size;
}

List FindAC(HashTable H,Account AC) {
	int Index = Hash(H, AC);
	List tmp = H->heads[Index].Next;//初始化
	while (tmp != NULL) {
		if (strcmp(tmp->AC,AC)==0) {
			break;
		}
		else {
			tmp = tmp->Next;
		}
	}
	return tmp;
}

void Login(HashTable H, Account AC, PassWord PW) {
	List Pos_AC = FindAC(H, AC);
	if (Pos_AC == NULL) {
		cout << "ERROR: Not Exist\n";
	}
	else {
		strcmp(Pos_AC->PW, PW)==0 ? cout << "Login: OK\n" : cout << "ERROR: Wrong PW\n";
	}
}

void CreatAC(HashTable H, Account AC, PassWord PW) {
	List Pos_AC = FindAC(H,AC);
	int IndexToInsert;
	if (Pos_AC == NULL) {
		IndexToInsert = Hash(H,AC);
		Pos_AC = new ListNode;
		strcpy(Pos_AC->AC,AC);
		strcpy(Pos_AC->PW, PW);
		Pos_AC->Next = H->heads[IndexToInsert].Next;
		H->heads[IndexToInsert].Next = Pos_AC;
		cout << "New: OK\n";
	}
	else {
		cout << "ERROR: Exist\n";
	}
}

void CommandProcess(HashTable H) {
	char Command;
	Account AC;
	PassWord PW;
	cin >> Command;
	cin >> AC;
	cin >> PW;
	switch (Command)
	{
	case'L':
		Login(H,AC,PW); 
		break;
	case'N':
		CreatAC(H,AC,PW); 
		break;
	default:
		break;
	}
}


int main() {
	int N;
	cin >> N;
	HashTable H;
	H = BuildHashTable(N);
	for (int i = 0; i < N; i++) {
		CommandProcess(H);
	}
	return 0;
}