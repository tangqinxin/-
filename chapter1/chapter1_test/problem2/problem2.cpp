#include <stdio.h>
#define MAXNUM 10000
void maxSubseSum(int a[], int K, int output[]);
void maxSubseSum2(int a[], int K, int output[]);
#pragma warning(disable: 4996)  
int main() {
	int K;
	int a[MAXNUM];
	int output[3];

	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &a[i]);
	}
	maxSubseSum(a, K,output);
	printf("%d %d %d", output[0],output[1],output[2]);
	getchar();
	getchar();

	return 0;
}


void maxSubseSum2(int a[], int N, int output[]) {
	int thissum, maxsum;
	int start, end;
	int maxstart, maxend;
	thissum = 0;
	start = end = 0;
	maxstart = maxend = 0;
	maxsum = -1;
	for (int i = 0; i < N; i++) {
		thissum = 0;
		for (int j = i; j < N; j++) {
			thissum += a[j];
			if (thissum > maxsum) {
				maxsum = thissum;
				maxstart = i;
				maxend = j;
			}
		}
	}
	if (maxsum == -1) {
		maxsum = 0;
		maxstart = 0;
		maxend = N - 1;
	}
	output[0] = maxsum;
	output[1] = a[maxstart];
	output[2] = a[maxend];
}


void maxSubseSum(int a[],int K,int output[]) {
	int thissum, maxsum;
	thissum = 0;
	maxsum = -1;
	int start,maxstart,maxend;
	maxstart = start = 0;
	maxend = 0;
	int AllisNag = 1;
	for (int i = 0; i < K; i++) {
		if (a[i] >= 0)
			AllisNag = 0;
	}


	for (int i = 0; i < K; i++) {
		thissum += a[i];
		if (thissum > maxsum) {
			maxsum = thissum;
			maxend = i;/*更新尾部*/
			maxstart = start;
		}
		else if (thissum < 0) {
			thissum = 0;
			start = i+1;/*更新开端*/
		}
	}

	if (AllisNag == 1) {
		maxsum = 0;
		maxstart = 0;
		maxend = K - 1;
	}
		output[0] = maxsum;
		output[1] = a[maxstart];
		output[2] = a[maxend];
}