#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);
/*题目要求使用原来的节点，因此要简单一些*/
List Merge(List L1, List L2) {
	List res = (List)malloc(sizeof(struct Node));
	List L1_pt, L2_pt,temp;
	/*L1,L2是带头节点的链表，因此要进行特殊处理*/
	temp = res;//res指向结果的头节点
	L1_pt = L1->Next;
	L2_pt = L2->Next;
	while (L1_pt&&L2_pt) {/*p,q不为空指针的时候循环*/
		if (L1_pt->Data > L2_pt->Data) {
			temp->Next = L2_pt;
			temp = temp->Next;
			L2_pt = L2_pt->Next;
		}
		else if (L1_pt->Data < L2_pt->Data) {
			temp->Next = L1_pt;
			temp = temp->Next;
			L1_pt = L1_pt->Next;
		}
		else if(L1_pt->Data == L2_pt->Data) {/*两个数相同的时候，两个都同时插入*/
			temp->Next = L1_pt;
			L1_pt = L1_pt->Next;
			temp = temp->Next;

			temp->Next = L2_pt;
			L2_pt = L2_pt->Next;
			temp = temp->Next;
		}
	}
	while (L1_pt) {/*LIST 1残余的时候进行处理*/
		temp->Next = L1_pt;
		temp = temp->Next;
		L1_pt = L1_pt->Next;
	}
	while (L2_pt) {/*LIST 2残余的时候进行处理*/
		temp->Next = L2_pt;
		temp = temp->Next;
		L2_pt = L2_pt->Next;
	}
	temp->Next = NULL;
	L1->Next = NULL;/*根据要求对LIST 1，2进行处理*/
	L2->Next = NULL;
	//要求返回带头节点的结果链表
	return res;
}