#include <iostream>
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


void ShellSort(int a[],int N) {
	int Sedgewick[] = { 929,505,209,109,41,19,5,1,0 };
	int Si;
	for (Si = 0; Sedgewick[Si] >= N; Si++) {}//˼��������Ϊʲô��>=������>? ��Ϊ����ĳ���ֱ����i=D,a[i]==a[D],���������Ȼ����,��Ϊ�����Ǵ�a[0]~a[N-1]
	int D, i, j;
	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si]) {
		for (i = D; i < N; i++) {
			int tmp = a[i];
			for (j = i; j >= D&&a[j - D] > tmp;j=j-D) {//˼��������j>=D,��ѭ����ʼ���ʺ�������a[0]>tmp
				a[j] = a[j - D];
			}
			a[j] = tmp;
		}
	}
}

int main() {
	int N;
	cin >> N;
	GetData(a, N);
	ShellSort(a, N);
	DispArr(a, N);
	return 0;
}