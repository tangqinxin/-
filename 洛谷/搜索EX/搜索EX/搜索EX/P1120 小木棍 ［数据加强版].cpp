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
	//���ؽ��������е�һ��С��target���������
	//����ڽ���������˵���ҵ���һ��С�ڵģ��൱�����ұ߽磬��������������ģ���˲�-1
	//����ҵ�һ�����ڵģ��൱������߽�
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
	//�ҵ����������һ������target����
	//��������target�������߽磬��������������ģ���������»������жϣ���Ҫ-1
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
	//����ʱleft==right�����ڷ���-1��Ҫ����0
	if (left == 1)return 1;
	return (left - 1);
}

void GetNextLeftboard() {
	//NextLeftboard[i]Ϊrod[]�����е�һ������rod[i]���ȵ�ľ�����ȵ��±�
	for (int i = 1; i <= cnt; i++) {
		NextLeftboard[i] = findleftboard(rod, cnt, rod[i]);
	}
}

void GetNextArr() {
	//����������rod[]���飬�õ�next[]����
	//next[i]Ϊrod[]�����е�һ��С��rod[i]���ȵ�ľ�����ȵ��±�
	for (int i = 1; i <= cnt; i++) {
		Next[i] = findrightboard(rod, cnt, rod[i]);
	}
}

//----------------------���Ĵ���-----------------------------//
int FindNextInd(int arr[], int arrlen, int target,int curindex) {
	//�ҵ��ڽ�������arr[]�У���һ������С��target���±�
	//Ѱ���ұ߽磬�Ǳ߽���,����right
	//Ҫ����߽��curindex������Ծ��������ÿ�ζ���[1,cnt]���ж���,���Ǵ�[i,cnt]���ж���
	//������ǵ�i�Ѿ��������������п��Դ�i+1��ʼ���У���������Ҫ��left����Խ��,�˴�����
	//������forѭ���У�����ѭ��Ҫ����cnt����˴˴��Ĵ��뻹��Ҫ�޸�
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
	//������������ʼ��ö�ٵĿ�ʼ������Ҵ�<=leftlen���±꿪ʼ���Һ��ʵĳ���
	//�ڽ�������arr[]�У��ҵ���һ��С�ڵ���leftlen����
	//�������Ѱ����߽磬�߽��ڣ�����left,�ظ�������������dfs�и���i����Ծ��ʱ������
	int left = startind;//������߽磬��֦
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
	//���������cnt��ľ������ǰ����target���Ȼ���left��
	if (curcnt > cnt&&left==target) {
		flag = true;
		minres = target;
		return;//����Ѿ���������ľ���������������һ���󳤶�ǡ�ã����������
	}

	if (flag == true) {
		return;//��֦
	}

	for (int i = 1; i <= cnt; i++) {
		if (used[i] != 1&&left>=rod[i]) {
			used[i] = 1;
			if (left - rod[i] == 0) {
				dfs(curcnt + 1, target, target);//���ǡ�ý���һ������ôҪ��ʼ����һ��
			}
			else if (left - rod[i] > 0) {
				dfs(curcnt + 1, left - rod[i], target);//����޷�����һ������ô������
			}
			used[i] = 0;
		}
	}
}


void dfs2(int curcnt, int leftlen, int target) {
	if (curcnt > cnt&&leftlen == target) {
		flag = true;
		minres = target;
		return;//�Ѿ���������ľ�����������һ���󳤶�ǡ�ã����������
	}
	if (flag == true) { 
		return;//�ҵ����ֱ��������������������ͨ�ļ�֦
	}

	for (int i =1; i <= cnt;i++) {
		//i��ʼ��Ϊ<=leftlen���±꣬���ٴ�1��ʼö�٣�
		//����ö��ʧ��ʱ��i�ӵ�ǰ�±꿪ʼ������Ծ�������ǵ���i++��
		//����2����֦�ǻ���������������ʵ��

		if (used[i] != 1) {
			if (leftlen-rod[i]==0) {
				//��Ϊ��ǰ�����������������ʧ���ˣ�ֱ�ӷ��أ����ٽ���ͬ�����Ծö��
				used[i] = 1;
				dfs2(curcnt + 1, target, target);
				used[i] = 0;//����ߵ���һ����˵���Ѿ�ʧ����ֱ������ѭ��
				break;//�˴�ʹ��break����return���������ԣ��ҽ�����break;
			}
			if (leftlen - rod[i] > 0) {
				used[i] = 1;
				dfs2(curcnt + 1, leftlen - rod[i], target);
				used[i] = 0;//�˴�ʧ���ˣ������Լ�������ö�٣���������
				if (leftlen == target)break;//�����֦��ԭ������Ϊû��ƴ�����϶�Ҫƴ����ô��Ŀ϶������ϣ����ﲻ�оͿ϶�������
				while (rod[i] == rod[i + 1]&&i<cnt) {//һ�ֳ��õ���Ծѭ��
					i++;//��Ȼ����ö�٣���������Ҫ�Ҳ�ͬ��ֵ
					//��ǰ��i�ǲ����еģ����Ǳ���֪��i+1��i��ͬ����
				}
			}
		}
	}
}

void dfs3(int curcnt, int leftlen, int target) {
	if (curcnt > cnt&&leftlen == 0) {
		flag = true;
		minres = target;
		return;//�Ѿ���������ľ�����������һ���󳤶�ǡ�ã����������
	}
	if (flag == true) {
		return;//�ҵ����ֱ��������������������ͨ�ļ�֦
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
			maxlen = max(maxlen, len);//�����ֵ�������������
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