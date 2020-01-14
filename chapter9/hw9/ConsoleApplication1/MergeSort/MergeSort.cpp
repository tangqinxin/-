#include<iostream>
#define MaxSize 100000
int a[MaxSize];

using namespace std;

void GetData(int a[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> a[i];//这里数据不需要后移
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
	/*将数组a[]中的数据，在有序区间a[L,R-1]和a[R,RightEnd]进行归并，然后存放到tmpa[]中,最终存回a[]*/
	int LeftEnd = R - 1;
	int tptr = L;
	int start = L;
	while (L <= LeftEnd&&R <=RightEnd) {
		if (a[L] > a[R]) tmpa[tptr++] = a[R++];
		else
			tmpa[tptr++] = a[L++];
	}
	while (L <= LeftEnd)//这里不能写为while(L!=LeftEnd),当L=1,LeftEnd=0的时候会导致泄露
		tmpa[tptr++] = a[L++];
	while (R <= RightEnd)
		tmpa[tptr++] = a[R++];
	for(int i=start;i<=RightEnd;i++){
		a[i] = tmpa[i];
	}
}

void Merge2(int a[], int tmpa[], int L, int R, int RightEnd) {
	/*将数组a[]中的数据，在有序区间a[L,R-1]和a[R,RightEnd]进行归并，然后存放到tmpa[]中*/
	int LeftEnd = R - 1;
	int tptr = L;
	while (L <= LeftEnd&&R <= RightEnd) {
		if (a[L] > a[R]) tmpa[tptr++] = a[R++];
		else
			tmpa[tptr++] = a[L++];
	}
	while (L <= LeftEnd)//这里不能写为while(L!=LeftEnd),当L=1,LeftEnd=0的时候会导致泄露
		tmpa[tptr++] = a[L++];
	while (R <= RightEnd)
		tmpa[tptr++] = a[R++];
}

void MSort(int a[], int tmpa[], int L, int RightEnd) {
	/*递归:将数组a[]的[L,RightEnd]区间进行归并排序,并且存放到tmpa[]中*/
	int center = (L + RightEnd) / 2;
	if (L < RightEnd) {
		MSort(a, tmpa, L, center);
		MSort(a, tmpa, center + 1, RightEnd);
		Merge(a, tmpa, L, center + 1, RightEnd);
	}
}

void MSort2(int a[], int tmpa[], int N, int length) {
	/*将数组a[]中的元素进行归并，然后存放到tmpa[]中，每length个元素段进行归并*/
	int i;
	for (i = 0; i + 2 * length < N; i =i+length * 2) {
		Merge2(a, tmpa, i, i + length, i + 2 * length-1);
	}
	/*判断剩下的元素是否超过一个length*/
	if (i + length < N) {//超过了一个length,将length和残余的合并
		Merge2(a, tmpa, i, i + length, N - 1);
	}
	else
	{//余下的元素没有超过一个length，将余下的拷贝到tmpa,注意，余下的子列仍然为有序子列!
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
	/*非递归*/
	int length = 1;
	int* tmpa = new int[N];
	while (length < N) {
		MSort2(a, tmpa, N, length);
		length = length * 2;
		MSort2(tmpa,a, N, length);//思考：如果length超过了长度，还能够翻过来吗?是可以的，在MSort2函数的最后一种情况中，直接i=0,直接拷贝，此时length>N
		length = length * 2;
	}
	
	/*for (int i = 0; i < N; i++)
		a[i] = tmpa[i];//这一段是不需要的，因为上面的循环会自动的把数组翻过来，因为每一次循环都是从a[]->tmpa[]->a[]*/
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