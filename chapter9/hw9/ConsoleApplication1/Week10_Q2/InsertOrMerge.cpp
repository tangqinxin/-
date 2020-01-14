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
	/*将a[]数组拷贝到b[]数组，数组大小为N*/
	for (int i = 0; i < N; i++) {
		b[i] = a[i];
	}
}

int CompareRes(int a[], int res[],int N) {
	/*比较a[]和res[],相同则返回1，不同则返回0*/
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
	/*对tmpArr[]数组做第i次插入排序*/
	int tmp = tmpArr[i];
	int j;
	for (j = i; j > 0 && tmp < tmpArr[j - 1]; j--) {
		tmpArr[j] = tmpArr[j - 1];
	}
	tmpArr[j] = tmp;
}

void MergeArr(int a[], int tmp[], int L,int R,int R_end) {
	/*将数组a[],有序区间[L,R-1],[R,R_end]两个区间进行不断归并，然后存入到tmp[]中*/
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
	/*将长度为N的a[]，以length为长度归并，然后存入到tmp中*/
	int i;
	for (i = 0; i + 2 * length < N; i = i + 2 * length) {
		MergeArr(a, res, i, i + length, i + 2 * length - 1);
	}
	/*剩余有序子列的合并*/
	if(i+length<N){
		MergeArr(a, res, i, i + length, N - 1);
	}
	else {
		CopyArr(a + i, res + i, N - i);
	}
}

int InsertOrMerge(int a[], int res[], int N) {
	/*多一次迭代的数组结果存放在res[]中*/
	int* tmpArr = new int[N];
	int* ComArr = new int[N];
	int InsertOrMerge=-1;//初始设置为-1，如果是Insert返回1，是Merge返回2;
	CopyArr(a,tmpArr,N);//初始化tmparr数组
	CopyArr(res, ComArr, N);
	int IterInsert,IterMerge;
	for (IterInsert = 1; IterInsert < N; IterInsert++) {
		InsertSort(tmpArr, IterInsert);
		if (CompareRes(tmpArr, ComArr,N) == 1) {
			InsertOrMerge = 1;
			InsertSort(tmpArr, IterInsert+1);//如果是插入排序，那么再执行一次迭代，然后跳出循环
			CopyArr(tmpArr, res,N);//InsertSort多一次迭代结果覆盖res[]
			break;
		}
	}

	CopyArr(a, tmpArr, N);//再次用a[]初始化tmpArr[]，进行后续的判断
	int length = 1;
	IterMerge = 0;
	while (length <N) {
		MergeSort(a, tmpArr, N, length);
		CopyArr(tmpArr, a, N);//将数组拷贝回去，方便循环
		length = length * 2;
		IterMerge++;
		if (CompareRes(tmpArr, ComArr, N) == 1) {
			InsertOrMerge = 2;
			MergeSort(a, tmpArr, N, length);//如果是归并排序，那么再执行一次迭代，然后跳出循环
			CopyArr(tmpArr, res, N);//MergeSort多一次迭代结果覆盖res[]
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
	GetData(a, N);//读取原始数据到数组a[]
	GetData(res, N);//读取排序后数据到数组res[]
	int InOrMeg;
	InOrMeg = InsertOrMerge(a, res, N);
	DispRes(InOrMeg, res,N);
	return 0;
}