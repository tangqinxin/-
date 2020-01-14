#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print(List L); /* ϸ���ڴ˲������������NULL */

List Merge(List L1, List L2);
/*��ĿҪ��ʹ��ԭ���Ľڵ㣬���Ҫ��һЩ*/
List Merge(List L1, List L2) {
	List res = (List)malloc(sizeof(struct Node));
	List L1_pt, L2_pt,temp;
	/*L1,L2�Ǵ�ͷ�ڵ���������Ҫ�������⴦��*/
	temp = res;//resָ������ͷ�ڵ�
	L1_pt = L1->Next;
	L2_pt = L2->Next;
	while (L1_pt&&L2_pt) {/*p,q��Ϊ��ָ���ʱ��ѭ��*/
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
		else if(L1_pt->Data == L2_pt->Data) {/*��������ͬ��ʱ��������ͬʱ����*/
			temp->Next = L1_pt;
			L1_pt = L1_pt->Next;
			temp = temp->Next;

			temp->Next = L2_pt;
			L2_pt = L2_pt->Next;
			temp = temp->Next;
		}
	}
	while (L1_pt) {/*LIST 1�����ʱ����д���*/
		temp->Next = L1_pt;
		temp = temp->Next;
		L1_pt = L1_pt->Next;
	}
	while (L2_pt) {/*LIST 2�����ʱ����д���*/
		temp->Next = L2_pt;
		temp = temp->Next;
		L2_pt = L2_pt->Next;
	}
	temp->Next = NULL;
	L1->Next = NULL;/*����Ҫ���LIST 1��2���д���*/
	L2->Next = NULL;
	//Ҫ�󷵻ش�ͷ�ڵ�Ľ������
	return res;
}