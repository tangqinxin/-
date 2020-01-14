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

/* 要求输入两个序列（指针形式），将两个序列进行比较后，再插入，然后进行结合，放入到新的序列中，返回这个新的序列；
   本章学习的内容是线性表和链表，堆栈和队列；实现的功能有，多项式的读入，多项式的加法，多项式的乘法*/

/*函数框架：
1.输入List1，List2，定义一个结果多项式表头变量res
2.比较LIST1 和LIST2的每一项的大小，小的插入RES，并后移
3.当一个为空的时候跳出，将剩余的项数全部插入结果当中
*/

List Merge(List L1, List L2) {
	/*1.如果L1或者L2任意为空，则直接结合另外一个LIST*/
	/*2.如果不为空则循环判断直到一个为空*/
	/*3.一个为空后，循环剩下的序列*/
	List res_final, temp;
	List res= (List)malloc(sizeof(struct Node));/*建立一个结果多项式，头节点不管，后面再去除头节点*/
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
	/*参与项之间添加*/
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
/*函数框架：将数据_data插入到_L中*/
void attach(ElementType _data, List _L) {
	List temp;
	temp = (Node*)malloc(sizeof(struct Node));
	temp->Data = _data;
	temp->Next = NULL;

	_L->Next = temp;
}