#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;


int MaxDesend(int a[], int n) {
	//�󳤶�Ϊn��a[]������������鳤��,O(n^2)����
	int dp[100000];//dp[i]���壺��a[i]Ϊ��β�������������ĳ���
	for (int i = 0; i < n; i++)
		dp[i] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] <= a[j]) {//�˴���<=�����˲�����������ϸ�Ļ���Ϊ<
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res,dp[i]);
	}
	return res;
}

int MaxDesendFast(int a[], int n) {
	//��������������O��nlogn)����
	int dp[100005];//����dp[i]Ϊ����Ϊi+1���½����е����һ��Ԫ�ص����ֵ
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		//Ѱ�Ҵ�������һ��С��a[i]����,û�о�push_back
		//�൱��Ѱ���ұ߽�
		int left = 0;
		int right = cnt;
		int target = a[i];
		while (left < right) {
			int mid = (left + right) / 2;
			if (dp[mid] == target) {
				left = mid + 1;//��һ����Ѱ���ұ߽绹����߽�Ӱ��
			}
			else if (dp[mid] > target) {
				left = mid + 1;//��һ���������������ǽ���Ӱ��
			}
			else if (dp[mid] < target) {
				right = mid;
			}
		}//����ѭ��ʱrightΪ��һ��С��target��ֵ����right-1Ϊ��һ�����ڵ���target��ֵ

		//��������������С�ڵ��ڵ�����������Ҳ����push_back����Ϊ���ֲ�����right�ϸ�С��target��
		if (right == cnt)cnt++;//���rightָ��β����ôtarget������С��(�ϸ�С�ڣ��ų��˵��ڵĿ��ܣ���ֻ�ܽ��ں��棬��ʱdp[right]=target�����Ψһ
		dp[right] = target;//���right����ָ��β,���Ǳ���ָ�����һ��Ԫ�أ�˵��right��targetС����ô������dp[right]=target�滻�������Ψһ
		

		//����˵�������ϸ�С�ڵ����,����ȵ�ʱ�򲻿���push_back
		//if (right == cnt) {//�Ѿ�ָ��β�ˣ���ʱright-1�����Ǵ���target�ģ�Ҳ�����ǵ���target�ģ��ֿ��ж�;��right���ϸ�С��target�ģ����right�ǳ�β��˵��������������ֵ
		//	if (dp[right - 1] == target)continue;//���ڵ���������ǲ���push_back,cnt����
		//	else if (dp[right - 1] > target) {//��ʱtarget������Сֵ������push_back
		//		cnt++;
		//		dp[right] = target;
		//	}
		//}
		//else {//����������ҵ�һ���ϸ�С�ڵ�����ֱ�Ӹ�ֵ
		//	dp[right] = target;
		//}
		
	}
	return cnt;
}

int MaxDesendSTL(int a[], int n) {
	//ʹ��STL�����½�������ұ߽�
	int dp[100000];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int target = a[i];
		auto pos = upper_bound(dp, dp + cnt, target,greater<int>());//���ص�һ��С��target����,lower_bound��upper_bound��ʹ�ú������Ƿ������޹�
		if (pos == (dp + cnt))cnt++;
		*pos = target;
	}
	return cnt;
}


int MaxRise(int a[], int n) {
	//�󳤶�Ϊn��a[]����������飬O(nlogn)����
	int dp[100000];//dp[i]����Ϊ����Ϊ����Ϊi+1���������е����һ��Ԫ�ص���Сֵ
	int cnt = 0;//ģ������vector,���ڼ������������ĳ���

	for (int i = 0; i < n; i++) {
		//����ÿһ���µ�������Ҫ��������dp�е���߽磨��һ�����������)
		int target = a[i];
		int left = 0;
		int right = cnt;
		while (left < right) {
			int mid = (left + right) / 2;
			if (dp[mid] == target) {
				right = mid;
			}
			else if (dp[mid] > target) {
				right = mid;
			}
			else if (dp[mid] < target) {
				left = mid + 1;
			}
		}//����ѭ��ʱleft������߽�,ָ���һ�����������
		if (left == cnt)cnt++;
		dp[left] = target;
	}
	return cnt;
}

int MaxRiseSTL(int a[], int n) {
	//�ú���Ѱ������a[]��������������У���ʹ��STL��lower_bound���������߽�
	int dp[100005];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int target = a[i];
		auto pos = lower_bound(dp, dp + cnt, target);//ʹ��lower_boundѰ����߽磬����ֵ�ǵ���������
		if (pos == (dp + cnt))cnt++;
		*pos = target;
	}
	return cnt;
}

int main() {
	int height[100000];
	int n = 0;//���鳤��
	while (cin >> height[n++]);
	n--;
	//cout<<MaxDesendFast(height, n) << endl;
	//cout << MaxRise(height, n)<<endl;
	cout<<MaxDesendSTL(height, n) << endl;
	cout << MaxRiseSTL(height, n)<<endl;
	return 0;
}