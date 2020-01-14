#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;


int MaxDesend(int a[], int n) {
	//求长度为n的a[]的最长不上升数组长度,O(n^2)方法
	int dp[100000];//dp[i]定义：以a[i]为结尾的最长不上升数组的长度
	for (int i = 0; i < n; i++)
		dp[i] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] <= a[j]) {//此处的<=体现了不上升，如果严格的话改为<
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
	//求最长不上升数组的O（nlogn)方法
	int dp[100005];//定义dp[i]为长度为i+1的下降序列的最后一个元素的最大值
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		//寻找从左边起第一个小于a[i]的数,没有就push_back
		//相当于寻找右边界
		int left = 0;
		int right = cnt;
		int target = a[i];
		while (left < right) {
			int mid = (left + right) / 2;
			if (dp[mid] == target) {
				left = mid + 1;//这一步受寻找右边界还是左边界影响
			}
			else if (dp[mid] > target) {
				left = mid + 1;//这一步受数列是升序还是降序影响
			}
			else if (dp[mid] < target) {
				right = mid;
			}
		}//跳出循环时right为第一个小于target的值，而right-1为第一个大于等于target的值

		//下面的语句适用于小于等于的情况，即相等也可以push_back（因为二分产生的right严格小于target）
		if (right == cnt)cnt++;//如果right指向超尾，那么target就是最小的(严格小于，排除了等于的可能），只能接在后面，此时dp[right]=target，情况唯一
		dp[right] = target;//如果right不是指向超尾,而是比如指向最后一个元素，说明right比target小，那么可以用dp[right]=target替换它，情况唯一
		

		//下面说明以下严格小于的情况,即相等的时候不可以push_back
		//if (right == cnt) {//已经指向超尾了，此时right-1可能是大于target的，也可能是等于target的，分开判断;但right是严格小于target的，如果right是超尾，说明不存在这样的值
		//	if (dp[right - 1] == target)continue;//等于的情况，我们不做push_back,cnt不变
		//	else if (dp[right - 1] > target) {//此时target就是最小值，可以push_back
		//		cnt++;
		//		dp[right] = target;
		//	}
		//}
		//else {//正常情况下找到一个严格小于的数，直接赋值
		//	dp[right] = target;
		//}
		
	}
	return cnt;
}

int MaxDesendSTL(int a[], int n) {
	//使用STL来求下降数组的右边界
	int dp[100000];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int target = a[i];
		auto pos = upper_bound(dp, dp + cnt, target,greater<int>());//返回第一个小于target的数,lower_bound和upper_bound的使用和序列是否有序无关
		if (pos == (dp + cnt))cnt++;
		*pos = target;
	}
	return cnt;
}


int MaxRise(int a[], int n) {
	//求长度为n的a[]的最长上升数组，O(nlogn)方法
	int dp[100000];//dp[i]定义为长度为长度为i+1的上升序列的最后一个元素的最小值
	int cnt = 0;//模拟向量vector,用于计数最长上升数组的长度

	for (int i = 0; i < n; i++) {
		//对于每一个新的数，需要搜索它在dp中的左边界（第一个比它大的数)
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
		}//跳出循环时left就是左边界,指向第一个比它大的数
		if (left == cnt)cnt++;
		dp[left] = target;
	}
	return cnt;
}

int MaxRiseSTL(int a[], int n) {
	//该函数寻找数组a[]的最大升序子序列，但使用STL的lower_bound求数组的左边界
	int dp[100005];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int target = a[i];
		auto pos = lower_bound(dp, dp + cnt, target);//使用lower_bound寻找左边界，返回值是迭代器类型
		if (pos == (dp + cnt))cnt++;
		*pos = target;
	}
	return cnt;
}

int main() {
	int height[100000];
	int n = 0;//数组长度
	while (cin >> height[n++]);
	n--;
	//cout<<MaxDesendFast(height, n) << endl;
	//cout << MaxRise(height, n)<<endl;
	cout<<MaxDesendSTL(height, n) << endl;
	cout << MaxRiseSTL(height, n)<<endl;
	return 0;
}