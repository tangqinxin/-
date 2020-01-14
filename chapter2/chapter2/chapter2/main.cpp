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

/* Ҫ�������������У�ָ����ʽ�������������н��бȽϺ��ٲ��룬Ȼ����н�ϣ����뵽�µ������У���������µ����У�
   ����ѧϰ�����������Ա��������ջ�Ͷ��У�ʵ�ֵĹ����У�����ʽ�Ķ��룬����ʽ�ļӷ�������ʽ�ĳ˷�*/

/*������ܣ�
1.����List1��List2������һ���������ʽ��ͷ����res
2.�Ƚ�LIST1 ��LIST2��ÿһ��Ĵ�С��С�Ĳ���RES��������
3.��һ��Ϊ�յ�ʱ����������ʣ�������ȫ������������
*/

List Merge(List L1, List L2) {
	/*1.���L1����L2����Ϊ�գ���ֱ�ӽ������һ��LIST*/
	/*2.�����Ϊ����ѭ���ж�ֱ��һ��Ϊ��*/
	/*3.һ��Ϊ�պ�ѭ��ʣ�µ�����*/
	List res_final, temp;
	List res= (List)malloc(sizeof(struct Node));/*����һ���������ʽ��ͷ�ڵ㲻�ܣ�������ȥ��ͷ�ڵ�*/
	res_final = temp = res;
	while (L1 && L2) {
		if (L1->Data > L2->Data) {
			attach(L2->Data, res);
			L2 = L2->Next;
		}
		else if(L1->Data < L2->Data)
		{
			attach(L1->Data, res);
			L1 = L1->Next;
		}
		else {
			attach(L1->Data, res); 
			attach(L2->Data, res);
			L2 = L2->Next;
			L1 = L1->Next;
		}
	}
	/*������֮�����*/
	while (L1) {
		attach(L1->Data, res);
		L1 = L1->Next;
	}
	while (L2) {
		attach(L2->Data, res);
		L2 = L2->Next;
	}
	res_final = res_final->Next;
	free(temp);
	return res_final;
}
/*������ܣ�������_data���뵽_L��*/
void attach(ElementType _data, List _L) {
	List temp;
	temp = (Node*)malloc(sizeof(struct Node));
	temp->Data = _data;
	temp->Next = NULL;

	_L->Next = temp;
}