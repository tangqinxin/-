#include<iostream>
#include<algorithm>
#define maxsize 100
using namespace std;
int n;
int rod[maxsize];
int used[maxsize];
int Next[maxsize];
int NextLeftboard[maxsize];
int StartArr[maxsize];
int maxlen;
int minres;
int cnt;
bool flag = false;

bool cmp(int a, int b) {
	return a > b;
}

int findrightboard(int arr[],int arrlen, int target) {
	//返回降序数组中第一个小于target的数的序号
	//这对于降序数组来说，找到第一个小于的，相当于找右边界，而且是找区间外的，因此不-1
	//如果找第一个大于的，相当于找左边界
	int left = 1;
	int right = arrlen + 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] == target) {
			left = mid + 1;
		}
		else if (arr[mid] > target) { 
			left = mid+1;
		}
		else if (arr[mid] < target) {
			right = mid;
		}
	}
	if (right == (arrlen+1))return arrlen;
	else return right;
}

int findleftboard(int arr[], int arrlen, int target) {
	//找到降序数组第一个大于target的数
	//这是是找target区间的左边界，而且是在区间外的，这种情况下画数轴判断，需要-1
	int left = 1;
	int right = arrlen + 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] == target) {
			right = mid;
		}
		else if (arr[mid] > target) {
			left = mid + 1;
		}
		else if (arr[mid] < target) {
			right = mid;
		}
	}
	//跳出时left==right，由于返回-1，要特判0
	if (left == 1)return 1;
	return (left - 1);
}

void GetNextLeftboard() {
	//NextLeftboard[i]为rod[]数组中第一个大于rod[i]长度的木棒长度的下标
	for (int i = 1; i <= cnt; i++) {
		NextLeftboard[i] = findleftboard(rod, cnt, rod[i]);
	}
}

void GetNextArr() {
	//利用排序后的rod[]数组，得到next[]数组
	//next[i]为rod[]数组中第一个小于rod[i]长度的木棒长度的下标
	for (int i = 1; i <= cnt; i++) {
		Next[i] = findrightboard(rod, cnt, rod[i]);
	}
}

//----------------------正文代码-----------------------------//
int FindNextInd(int arr[], int arrlen, int target,int curindex) {
	//找到在降序数组arr[]中，第一个长度小于target的下标
	//寻找右边界，是边界外,返回right
	//要求左边界从curindex进行跳跃，而不是每次都从[1,cnt]进行二分,而是从[i,cnt]进行二分
	//如果考虑到i已经搜索过，代码中可以从i+1开始进行，但是这样要对left特判越界,此处舍弃
	//由于在for循环中，跳出循环要超过cnt，因此此处的代码还需要修改
	int left = curindex;
	int right = arrlen + 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] == target) {
			left = mid + 1;
		}
		else if (arr[mid] > target) {
			left = mid + 1;
		}
		else if (arr[mid] < target) {
			right = mid;
		}
	}
	return right;
}

int FindStartInd(int arr[], int arrlen, int leftlen,int startind) {
	//这是是用来初始化枚举的开始，令查找从<=leftlen的下标开始查找合适的长度
	//在降序数组arr[]中，找到第一个小于等于leftlen的数
	//这里可以寻找左边界，边界内，返回left,重复的数字区间在dfs中更新i的跳跃的时候处理即可
	int left = startind;//定义左边界，剪枝
	int right = arrlen + 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] == leftlen) {
			right = mid;
		}
		else if (arr[mid] < leftlen) {
			right = mid;
		}
		else if (arr[mid] > leftlen) {
			left = mid + 1;
		}
	}
	if (left == arrlen + 1)return arrlen;
	return left;
}

void dfs(int curcnt, int left, int target) {
	//正在收入第cnt根木棒，当前距离target长度还有left长
	if (curcnt > cnt&&left==target) {
		flag = true;
		minres = target;
		return;//如果已经收完所有木棒，并且收完最后一根后长度恰好，则完成搜索
	}

	if (flag == true) {
		return;//剪枝
	}

	for (int i = 1; i <= cnt; i++) {
		if (used[i] != 1&&left>=rod[i]) {
			used[i] = 1;
			if (left - rod[i] == 0) {
				dfs(curcnt + 1, target, target);//如果恰好接上一根，那么要开始另外一根
			}
			else if (left - rod[i] > 0) {
				dfs(curcnt + 1, left - rod[i], target);//如果无法接上一根，那么继续接
			}
			used[i] = 0;
		}
	}
}


void dfs2(int curcnt, int leftlen, int target) {
	if (curcnt > cnt&&leftlen == target) {
		flag = true;
		minres = target;
		return;//已经收完所有木棒，并且最后一根后长度恰好，则完成搜索
	}
	if (flag == true) { 
		return;//找到结果直接跳过后续搜索，最普通的剪枝
	}

	for (int i =1; i <= cnt;i++) {
		//i初始化为<=leftlen的下标，不再从1开始枚举；
		//单次枚举失败时，i从当前下标开始进行跳跃，而不是单纯i++；
		//以上2个剪枝是基于有序的数组才能实现

		if (used[i] != 1) {
			if (leftlen-rod[i]==0) {
				//此为当前最优情况，如果该情况失败了，直接返回，不再进行同层的跳跃枚举
				used[i] = 1;
				dfs2(curcnt + 1, target, target);
				used[i] = 0;//如果走到这一步就说明已经失败了直接跳出循环
				break;//此处使用break或者return跳出都可以，我建议用break;
			}
			if (leftlen - rod[i] > 0) {
				used[i] = 1;
				dfs2(curcnt + 1, leftlen - rod[i], target);
				used[i] = 0;//此处失败了，还可以继续进行枚举，不用跳出
				if (leftlen == target)break;//这个剪枝的原因是因为没有拼过，肯定要拼，那么最长的肯定能用上，这里不行就肯定不行了
				while (rod[i] == rod[i + 1]&&i<cnt) {//一种常用的跳跃循环
					i++;//虽然继续枚举，但是我们要找不同的值
					//当前的i是不可行的，我们遍历知道i+1和i不同即可
				}
			}
		}
	}
}

void dfs3(int curcnt, int leftlen, int target) {
	if (curcnt > cnt&&leftlen == 0) {
		flag = true;
		minres = target;
		return;//已经收完所有木棒，并且最后一根后长度恰好，则完成搜索
	}
	if (flag == true) {
		return;//找到结果直接跳过后续搜索，最普通的剪枝
	}

	if (leftlen == 0) {
		for (int i = 1; i <= cnt; i++) {
			if (used[i] != 1) {
				used[i] = 1;
				dfs3(curcnt + 1, target - rod[i], target);
				used[i] = 0;
				if (flag == true)return;
			}
		}
	}
	
	for (int i = 1; i <= cnt; i++) {
		if (used[i] != 1) {
			used[i] = 1;
			dfs3(curcnt + 1, leftlen - rod[i], target);
			used[i] = 0;
			if (leftlen == rod[i] || leftlen == target)return;
			if (flag == true)return;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int len;
		cin >> len;
		if (len <= 50) {
			cnt++;
			maxlen = max(maxlen, len);//求最大值，方便后续计算
			rod[cnt] = len;
		}
	}

	int lensum=0;
	for (int i = 1; i <= cnt; i++) {
		lensum += rod[i];
	}

	sort(rod + 1, rod + 1 + cnt, cmp);

	for (int tmplen = maxlen; tmplen <= lensum; tmplen++) {
		if (lensum%tmplen != 0)continue;
		dfs3(1,0, tmplen);
	}

	cout << minres;
	return 0;
}