#include<iostream>
#include<stdio.h>
#include <algorithm>
#pragma warning(disable: 4996)  
#define MAX 100005
using namespace std;
struct node {
	int data;
	int next;
}Point[MAX];
int main() {
	
	int headaddress, N, K;
	cin >> headaddress >> N >> K;

	int address,num;
	num = N;

	while (num--) {
		cin >> address;
		cin >> Point[address].data >> Point[address].next;/*��ȡ����*/
	}
	/*��˳����*/
	int list[MAX];
	address = headaddress;
	int sum = 0;
	while(address!=-1) {/*���п����ж��NULL�Ľڵ㣬����ѡȡ��head����һ��NULL�Ľڵ�*/
		list[sum++] = address;
		address = Point[address].next;
	}
	/*ʵ���������list�������Ǵ�����һ�����ڼ�¼�ڵ�λ�õ����飬�ѽڵ��λ�ø���¼������
	  ����һ���Ļ��������ĸ��ֶ���Ҳʮ�ֵĺò����������Ļ���ʵ�Ѿ����������ˣ���ǰ����Ҫ�ҵ�i���ڵ㣬
	  ֻ��ͨ��ѭ����һ���ڵ�������Ѱ�ң���ô������˳֮�����˸�����ôֻҪ�ҵ�i��Ԫ�ؾͿ����ˡ����ṹ����
	  �����þ��൱�������洢���ݵģ���������ʵ�ʵĲ�����*/
	  /*���������˺ܾõ�ԭ������Ϊû�������������Ա�����飬�������������ˣ���Ȼ�����ǿ��������������ģ�����
	  ���÷ǳ����鷳��*/



	/*��ת����*/
	for (int i = 0; i < sum - sum%K; i = i + K) {
		for (int j = 0; j < K / 2; j++) {
			int tempad;
			tempad = list[i + j];
			list[i + j] = list[i + K - 1 - j];
			list[i + K - 1 - j] = tempad;
		}
	}
	

	int i = 0;
	for (; i < sum-1; i++) {
		printf("%05d %d %05d\n", list[i], Point[list[i]].data, list[i+1]);/*ע�⣬��������ӡ��Ӧ����list[i+1],������Point[list[i]].next*/
	}
	printf("%05d %d %d\n", list[i], Point[list[i]].data, -1);/*����һֱѭ����sum������ĵ㲻�ٴ�ӡ��*/

	return 0;
}
