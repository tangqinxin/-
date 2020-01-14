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
		cin >> Point[address].data >> Point[address].next;/*读取数据*/
	}
	/*理顺链表*/
	int list[MAX];
	address = headaddress;
	int sum = 0;
	while(address!=-1) {/*表中可能有多个NULL的节点，我们选取从head到第一个NULL的节点*/
		list[sum++] = address;
		address = Point[address].next;
	}
	/*实际上这里的list的作用是创建了一个用于记录节点位置的数组，把节点的位置给记录了下来
	  这样一来的话，后续的各种东西也十分的好操作；这样的话其实已经超出链表了，以前链表要找第i个节点，
	  只能通过循环下一个节点依次来寻找，那么现在捋顺之后，有了个表，那么只要找第i个元素就可以了。而结构数组
	  的作用就相当于用来存储数据的，而不进行实际的操作。*/
	  /*这题我做了很久的原因是因为没有深入的理解线性表和数组，过于依赖链表了，当然这题是可以用链表来做的，但是
	  会变得非常的麻烦。*/



	/*翻转链表*/
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
		printf("%05d %d %05d\n", list[i], Point[list[i]].data, list[i+1]);/*注意，这里最后打印的应该是list[i+1],而不是Point[list[i]].next*/
	}
	printf("%05d %d %d\n", list[i], Point[list[i]].data, -1);/*这里一直循环到sum，后面的点不再打印了*/

	return 0;
}
