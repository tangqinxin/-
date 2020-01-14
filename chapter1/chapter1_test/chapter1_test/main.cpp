#include <stdio.h>
#define MAXN 100000    //�������������ʮ��
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
	for (int i = 0; i < N; i++) {/*�������*/
		for (int j = i; j < N; j++) {/*�����Ҷ�*/
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
	for (int i = 0; i < N; i++) {/*������*/
		thissum = 0;/*ÿ������ƶ���ʱ�򣬶�Ҫ���г�ʼ��*/
		for (int j = i; j < N; j++) {/*����Ҷ�*/
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
	

	if (left == right) {/*�ݹ����ֹ����*/
		if (List[left] > 0)
			return List[left];
		else
			return 0;
	}

	/*�ֵĹ���*/
	center = (left + right) / 2;
	maxleftsum=DivideAndConquer(List, left, center);
	maxrightsum=DivideAndConquer(List, center+1, right);

	leftboardsum = maxleftbordersum = 0;
	for (int i = center; i >= left; i--) {/*��Ϳ�ֽ��ߵ���벿�ֺ�*/
		leftboardsum += List[i];
		if (leftboardsum > maxleftbordersum) {
			maxleftbordersum = leftboardsum;
		}
	}

	rightboardsum = maxrightbordersum = 0;
	for (int i = center+1; i <= right; i++) {/*��Ϳ�ֽ��ߵ��Ұ벿�ֺ�*/
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