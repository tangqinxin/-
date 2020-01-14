#include<iostream>
#define MaxSize 100000
int a[MaxSize];

using namespace std;

void GetData(int a[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> a[i];//�������ݲ���Ҫ����
	}
}

void DispArr(int a[], int N) {
	cout << a[0];
	N--;
	int i = 1;
	while (N--) {
		cout << " " << a[i++];
	}
}

void Merge(int a[],int tmpa[], int L, int R, int RightEnd) {
	/*������a[]�е����ݣ�����������a[L,R-1]��a[R,RightEnd]���й鲢��Ȼ���ŵ�tmpa[]��,���մ��a[]*/
	int LeftEnd = R - 1;
	int tptr = L;
	int start = L;
	while (L <= LeftEnd&&R <=RightEnd) {
		if (a[L] > a[R]) tmpa[tptr++] = a[R++];
		else
			tmpa[tptr++] = a[L++];
	}
	while (L <= LeftEnd)//���ﲻ��дΪwhile(L!=LeftEnd),��L=1,LeftEnd=0��ʱ��ᵼ��й¶
		tmpa[tptr++] = a[L++];
	while (R <= RightEnd)
		tmpa[tptr++] = a[R++];
	for(int i=start;i<=RightEnd;i++){
		a[i] = tmpa[i];
	}
}

void Merge2(int a[], int tmpa[], int L, int R, int RightEnd) {
	/*������a[]�е����ݣ�����������a[L,R-1]��a[R,RightEnd]���й鲢��Ȼ���ŵ�tmpa[]��*/
	int LeftEnd = R - 1;
	int tptr = L;
	while (L <= LeftEnd&&R <= RightEnd) {
		if (a[L] > a[R]) tmpa[tptr++] = a[R++];
		else
			tmpa[tptr++] = a[L++];
	}
	while (L <= LeftEnd)//���ﲻ��дΪwhile(L!=LeftEnd),��L=1,LeftEnd=0��ʱ��ᵼ��й¶
		tmpa[tptr++] = a[L++];
	while (R <= RightEnd)
		tmpa[tptr++] = a[R++];
}

void MSort(int a[], int tmpa[], int L, int RightEnd) {
	/*�ݹ�:������a[]��[L,RightEnd]������й鲢����,���Ҵ�ŵ�tmpa[]��*/
	int center = (L + RightEnd) / 2;
	if (L < RightEnd) {
		MSort(a, tmpa, L, center);
		MSort(a, tmpa, center + 1, RightEnd);
		Merge(a, tmpa, L, center + 1, RightEnd);
	}
}

void MSort2(int a[], int tmpa[], int N, int length) {
	/*������a[]�е�Ԫ�ؽ��й鲢��Ȼ���ŵ�tmpa[]�У�ÿlength��Ԫ�ضν��й鲢*/
	int i;
	for (i = 0; i + 2 * length < N; i =i+length * 2) {
		Merge2(a, tmpa, i, i + length, i + 2 * length-1);
	}
	/*�ж�ʣ�µ�Ԫ���Ƿ񳬹�һ��length*/
	if (i + length < N) {//������һ��length,��length�Ͳ���ĺϲ�
		Merge2(a, tmpa, i, i + length, N - 1);
	}
	else
	{//���µ�Ԫ��û�г���һ��length�������µĿ�����tmpa,ע�⣬���µ�������ȻΪ��������!
		for (int j = i; j < N; j++)
			tmpa[j] = a[j];
	}
}

void MergeSort(int a[], int N) {
	int* tmpa = new int[N];
	if (tmpa != NULL) {
		MSort(a, tmpa, 0, N - 1);
	}
	delete []tmpa;
}

void MergeSort2(int a[], int N) {
	/*�ǵݹ�*/
	int length = 1;
	int* tmpa = new int[N];
	while (length < N) {
		MSort2(a, tmpa, N, length);
		length = length * 2;
		MSort2(tmpa,a, N, length);//˼�������length�����˳��ȣ����ܹ���������?�ǿ��Եģ���MSort2���������һ������У�ֱ��i=0,ֱ�ӿ�������ʱlength>N
		length = length * 2;
	}
	
	/*for (int i = 0; i < N; i++)
		a[i] = tmpa[i];//��һ���ǲ���Ҫ�ģ���Ϊ�����ѭ�����Զ��İ����鷭��������Ϊÿһ��ѭ�����Ǵ�a[]->tmpa[]->a[]*/
	delete[]tmpa;
}

int main() {
	int N;
	cin >> N;
	GetData(a, N);
	MergeSort2(a, N);
	DispArr(a, N);
	return 0;
}