#include<iostream>
#define MaxSize 100
int a[MaxSize];
int res[MaxSize];
using namespace std;

void GetData(int a[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
}

void CopyArr(int a[], int b[], int N) {
	/*��a[]���鿽����b[]���飬�����СΪN*/
	for (int i = 0; i < N; i++) {
		b[i] = a[i];
	}
}

int CompareRes(int a[], int res[],int N) {
	/*�Ƚ�a[]��res[],��ͬ�򷵻�1����ͬ�򷵻�0*/
	int Flag_IsSame = 1;
	for (int i = 0; i < N; i++) {
		if (a[i] != res[i]) {
			Flag_IsSame = 0;
			break;
		}
	}
	return Flag_IsSame;
}

void InsertSort(int tmpArr[], int i) {
	/*��tmpArr[]��������i�β�������*/
	int tmp = tmpArr[i];
	int j;
	for (j = i; j > 0 && tmp < tmpArr[j - 1]; j--) {
		tmpArr[j] = tmpArr[j - 1];
	}
	tmpArr[j] = tmp;
}

void MergeArr(int a[], int tmp[], int L,int R,int R_end) {
	/*������a[],��������[L,R-1],[R,R_end]����������в��Ϲ鲢��Ȼ����뵽tmp[]��*/
	int L_end = R - 1;
	int ptr2tmp=L;
	while(L <= L_end&&R <= R_end) {
		if (a[L] < a[R]) {
			tmp[ptr2tmp++] = a[L++];
		}
		else {
			tmp[ptr2tmp++] = a[R++];
		}
	}
	while (L <= L_end) {
		tmp[ptr2tmp++] = a[L++];
	}
	while (R <= R_end) {
		tmp[ptr2tmp++] = a[R++];
	}
}

void MergeSort(int a[], int res[], int N, int length) {
	/*������ΪN��a[]����lengthΪ���ȹ鲢��Ȼ����뵽tmp��*/
	int i;
	for (i = 0; i + 2 * length < N; i = i + 2 * length) {
		MergeArr(a, res, i, i + length, i + 2 * length - 1);
	}
	/*ʣ���������еĺϲ�*/
	if(i+length<N){
		MergeArr(a, res, i, i + length, N - 1);
	}
	else {
		CopyArr(a + i, res + i, N - i);
	}
}

int InsertOrMerge(int a[], int res[], int N) {
	/*��һ�ε����������������res[]��*/
	int* tmpArr = new int[N];
	int* ComArr = new int[N];
	int InsertOrMerge=-1;//��ʼ����Ϊ-1�������Insert����1����Merge����2;
	CopyArr(a,tmpArr,N);//��ʼ��tmparr����
	CopyArr(res, ComArr, N);
	int IterInsert,IterMerge;
	for (IterInsert = 1; IterInsert < N; IterInsert++) {
		InsertSort(tmpArr, IterInsert);
		if (CompareRes(tmpArr, ComArr,N) == 1) {
			InsertOrMerge = 1;
			InsertSort(tmpArr, IterInsert+1);//����ǲ���������ô��ִ��һ�ε�����Ȼ������ѭ��
			CopyArr(tmpArr, res,N);//InsertSort��һ�ε����������res[]
			break;
		}
	}

	CopyArr(a, tmpArr, N);//�ٴ���a[]��ʼ��tmpArr[]�����к������ж�
	int length = 1;
	IterMerge = 0;
	while (length <N) {
		MergeSort(a, tmpArr, N, length);
		CopyArr(tmpArr, a, N);//�����鿽����ȥ������ѭ��
		length = length * 2;
		IterMerge++;
		if (CompareRes(tmpArr, ComArr, N) == 1) {
			InsertOrMerge = 2;
			MergeSort(a, tmpArr, N, length);//����ǹ鲢������ô��ִ��һ�ε�����Ȼ������ѭ��
			CopyArr(tmpArr, res, N);//MergeSort��һ�ε����������res[]
			break;
		}
	}
	delete[]tmpArr;
	delete[]ComArr;
	if (InsertOrMerge == 1) return 1;
	if (InsertOrMerge == 2) return 2;
}


void DispRes(int Inser_Merge,int res[],int N) {
	if (Inser_Merge == 1) {
		cout << "Insertion Sort" << endl;
	}
	if (Inser_Merge == 2) {
		cout << "Merge Sort" << endl;
	}
	int i;
	for ( i = 0; i < N-1; i++) {
		cout << res[i]<<" ";
	}
	cout << res[i];
}

int main() {
	int N;
	cin >> N;
	GetData(a, N);//��ȡԭʼ���ݵ�����a[]
	GetData(res, N);//��ȡ��������ݵ�����res[]
	int InOrMeg;
	InOrMeg = InsertOrMerge(a, res, N);
	DispRes(InOrMeg, res,N);
	return 0;
}