#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
#pragma warning(disable: 4996)  
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch(List L, ElementType X);

int main()
{
	List L;
	ElementType X;
	Position P;

	L = ReadInput();
	scanf("%d", &X);
	P = BinarySearch(L, X);
	printf("%d\n", P);

	return 0;
}

Position BinarySearch(List L, ElementType X) {
	Position left, right, center;
	left = 1;
	right = L->Last;/*�趨��ʼֵ*/

	while (right - left>1) {/*�趨ѭ�����������������������ڵ�ʱ����������ֱ���ж�*/
		center = (left + right) / 2;
		if (L->Data[center] == X) {
			return center;/*���ҵ��ˣ�ֱ������ѭ��,����center��ֵ*/
		}
		if (L->Data[center]>X) {
			right = center;
		}
		else if (L->Data[center]<X) {
			left = center;
		}
	}
	return (L->Data[left] == X) ? left : (L->Data[right] == X ? right : NotFound);/*ģ��ǰ����������������ֵ��д*/
}