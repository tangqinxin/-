#include<iostream>
#include<cstring>
using namespace std;
int n;
int words[3][30];//记录下算式的值
int used[30];//由于每个字母有唯一值，因此利用hash进行查询是否已经被使用
int res[30];//用来枚举答案，0-25对应于A-Z即26个英文字母
int finalres[30];//用来记录最终答案


void dfs(int row,int col,int carry) {
	//多个枚举应该以枚举数字为基础，然后去推进层数

	if (col<0&&carry==0) {
		for (int i = 0; i < n; i++) {
			finalres[i] = res[i];
		}
		return;
	}

	for (int i = col; i >= 0; i--) {
		//这个循环的存在是为了剪掉那些已经枚举过的，但是在后面计算中不符合的情况
		int num1 = res[words[0][i]];
		int num2 = res[words[1][i]];
		int num3 = res[words[2][i]];
		if (num1 == -1 || num2 == -1 || num3 == -1) continue;//这里当时的逻辑是怎么想到用continue的	
		int sum = num1 + num2;
		if (sum%n != num3 && (sum + 1) % n != num3) return;//如果有一个不符合，那么一定是不合理的
	}

	if (res[words[row][col]] == -1) {
		//如果当前值是不存在的，也就是说这个值是没有被填充的,那么我们要枚举这个值
		for (int i = 0; i <n; i++) {
			if (!used[i]) {//某个数字没有被使用,那么可以在当前层枚举这个数字,在if中可以对当前层的业务逻辑进行if分类
				if (row != 2) {//如果没有枚举完毕，那么我们需要继续递增row的层数，直到3行全部出来才能计算
					used[i] = 1;
					res[words[row][col]] = i;
					dfs(row + 1, col, carry);
					used[i] = 0;
					res[words[row][col]] = -1;
				}
				else if (row == 2) {
					//这个分支仍然是要填充，只是填充的过程又加了剪枝(筛选),但是我觉得其实不用，因为前面已经剪掉了
					int sum = res[words[0][col]] + res[words[1][col]] + carry;
					if (sum%n != i)continue;
					used[i] = 1;
					res[words[row][col]] = i;
					dfs(0, col - 1, sum / n);
					used[i] = 0;
					res[words[row][col]] = -1;
				}
			}
		}
	}
	else if(res[words[row][col]]!=-1){
		//如果当前的值已经有了，那就不需要遍历了，直接根据层数进行更深的遍历
		if (row != 2) {
			dfs(row + 1, col, carry);
		}
		else if (row == 2) {
			int sum = res[words[0][col]] + res[words[1][col]] + carry;
			if (sum%n != res[words[row][col]])return;
				dfs(0, col - 1, sum / n);
		}
	}
}

void display() {
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cout << finalres[i];
		}
		else {
			cout << " " << finalres[i];
		}
	}
}

int main() {
	memset(res, -1, sizeof(res));//置为-1，说明没有值，不可置为0，因为0也算有效的
	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			char ch;
			cin >> ch;
			words[i][j] = ch - 'A';//将字母转换为数字编号
		}
	}
	dfs(0, n - 1, 0);
	display();
	return 0;
}