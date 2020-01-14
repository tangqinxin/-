#include <stdio.h>
#define MAXN 100000    //本题最大数据是十万
int MaxSubseqSum1(int a[], int N);
int MaxSubseqSum3(int a[], int N);
int MaxSubseqSum4(int a[], int N);
int DivideAndConquer(int List[], int left, int right);
#pragma warning(disable: 4996)  
int main(void) {
	int K;
	int a[MAXN] = { 0 };

	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d", MaxSubseqSum4(a, K));

	getchar(); 
	getchar();
	return 0;
}
int MaxSubseqSum1(int a[], int N) {
	int maxsum = 0;
	int thissum = 0;
	for (int i = 0; i < N; i++) {/*子链左端*/
		for (int j = i; j < N; j++) {/*子链右端*/
			thissum = 0;
			for (int k = i; k <= j; k++) {
				thissum += a[k];
			}
			if (thissum > maxsum) {
				maxsum = thissum;
			}
		}
	}
	return maxsum;
}

int MaxSubseqSum2(int a[], int N) {
	int maxsum = 0;
	int thissum = 0;
	for (int i = 0; i < N; i++) {/*标记左端*/
		thissum = 0;/*每次左端移动的时候，都要进行初始化*/
		for (int j = i; j < N; j++) {/*标记右端*/
			thissum += a[j];
			if (thissum > maxsum) {
				maxsum = thissum;
			}
		}
	}
	return maxsum;
}

int MaxSubseqSum3(int a[], int N) {
	return DivideAndConquer(a, 0, N - 1);
}
int max3(int a, int b, int c) {
	return (a > b) ? (a > c ? a : c) : (b > c ? b : c);
}

int DivideAndConquer(int List[], int left, int right) {
	int maxleftsum, maxrightsum;
	int maxleftbordersum, maxrightbordersum;
	int leftboardsum, rightboardsum;
	int center;
	

	if (left == right) {/*递归的终止条件*/
		if (List[left] > 0)
			return List[left];
		else
			return 0;
	}

	/*分的过程*/
	center = (left + right) / 2;
	maxleftsum=DivideAndConquer(List, left, center);
	maxrightsum=DivideAndConquer(List, center+1, right);

	leftboardsum = maxleftbordersum = 0;
	for (int i = center; i >= left; i--) {/*求和跨分界线的左半部分和*/
		leftboardsum += List[i];
		if (leftboardsum > maxleftbordersum) {
			maxleftbordersum = leftboardsum;
		}
	}

	rightboardsum = maxrightbordersum = 0;
	for (int i = center+1; i <= right; i++) {/*求和跨分界线的右半部分和*/
		rightboardsum += List[i];
		if (rightboardsum > maxrightbordersum) {
			maxrightbordersum = rightboardsum;
		}
	}

	return max3(maxleftsum, maxrightsum, maxrightbordersum + maxleftbordersum);

}

int MaxSubseqSum4(int a[], int N) {
	int maxsum, thissum;
	maxsum = thissum = 0;

	for (int i = 0; i < N; i++) {
		thissum += a[i];
		if (thissum > maxsum)
			maxsum = thissum;
		else if (thissum < 0)
			thissum = 0;
	}
	return maxsum;
}