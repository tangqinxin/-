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
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
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
	right = L->Last;/*设定初始值*/

	while (right - left>1) {/*设定循环结束的条件，当两个相邻的时候留到后面直接判断*/
		center = (left + right) / 2;
		if (L->Data[center] == X) {
			return center;/*查找到了，直接跳出循环,返回center的值*/
		}
		if (L->Data[center]>X) {
			right = center;
		}
		else if (L->Data[center]<X) {
			left = center;
		}
	}
	return (L->Data[left] == X) ? left : (L->Data[right] == X ? right : NotFound);/*模仿前面的求三个数的最大值来写*/
}