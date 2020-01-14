#include<stdio.h>
#include<malloc.h>
#pragma warning(disable: 4996)  
typedef struct PolyNode* Polynomial;
struct PolyNode {
	int pow;
	int coef;
	Polynomial link;
};

/*读取一个多项式*/
Polynomial read();
/*计算多项式的求和*/
Polynomial add(Polynomial P1, Polynomial P2);
/*计算乘积多项式的输出*/
Polynomial Multi(Polynomial P1, Polynomial P2);

/*输出多项式*/
void PrintPoly(Polynomial P);
void attach(int _pow, int _coef, Polynomial* ptrrear);

int main() {
	Polynomial P1;
	Polynomial P2; /*建立多项式P1,P2用于读取*/
	Polynomial res,res2;
	P1 = read();/*读取多项式P1*/
	P2 = read();/*读取多项式P2*/
	res2 = Multi(P1, P2);
	PrintPoly(res2);
	res = add(P1, P2);
	PrintPoly(res);
	getchar();
	getchar();
	return 0;
}

/*乘法过程说明：
1.如果使用了先乘出来再用ADD加到结果的方法的话，会申请一个空间用来存储ADD的临时多项式，如果不想浪费这部分空间，那么最好就要另外
写一个ADD2函数来加这种特殊的方法，顺便释放掉对应的空间。
2.因此这里采用的是：
1.先算出P1的第一项乘P2得到一个初步的结果
2.P1的其他项乘P2，然后进行比较指数和插值，这个和第一题的作业比较像*/
Polynomial Multi(Polynomial P1, Polynomial P2) {
	/*判断P1或P2为NULL的情况，返回NULL*/
	if (!P1 || !P2)
		return NULL;
	/*先计算P1第一项乘P2*/
	Polynomial res = (Polynomial)malloc(sizeof(struct PolyNode));/*建立头节点*/
	Polynomial t1, t2,rear;
	t1 = P1->link;
	t2 = P2->link;
	rear = res;
	int pow, coef;
	while (t2) {/*乘出第一项*/
		pow = t1->pow + t2->pow;
		coef=t1->coef*t2->coef;
		attach(pow,coef,&rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while (t1) {
		t2 = P2->link;/*我认为不需要修改*/
		rear = res;
		while (t2) {
			pow = t1->pow+t2->pow;
			coef = t1->coef*t2->coef;

			while (rear->link&&rear->link->pow>pow) {/*将计算得到的单项遍历结果表，寻找插入位置,这里用rear->link而不是rear是为了保留前节点的信息，
													 但是遍历的时候对每一个有数据的节点（包括最后一个节点）也进行了搜索，因此其实不需要对最后一个节点进行特殊的处理。*/
				rear = rear->link;/*如果指数不符合或者到了最后一项的时候就跳出，剩余要么是指数相等的情况，要么是缺少项的情况*/
			}
			if (rear->link&&rear->link->pow == pow) {/*指数相等的情况，分开为求和等于0和不等于0来处理*/
				if (rear->link->coef + coef == 0) {
					Polynomial temp = rear->link;
					rear->link = rear->link->link;/*衔接链表*/
					free(temp);
				}
				else {
					rear->link->coef = rear->link->coef + coef;
				}
			}
			else {/*这种情况为rear->link为空或者是在中间插入了一项，即已经到了最后一项了,由于第一项已经乘出来了，因此基本上不会有小于最高次的的pow,基本上是补充*/
				/*这里不能使用attach，因为attach函数会造成断链，attach并没有链接两个链的功能，因此我们这里自己手动写这个函数*/
				Polynomial temp = (Polynomial)malloc(sizeof(struct PolyNode));
				temp->coef = coef;
				temp->pow = pow;
				temp->link = rear->link;
				rear->link = temp;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}

	return res;/*打印的函数就是带头节点的，我认为返回的结果也应该带头节点，除非修改打印的函数*/
}



Polynomial add(Polynomial P1, Polynomial P2) {
	Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
	Polynomial res = P;
	Polynomial term1 = P1->link;
	Polynomial term2 = P2->link;
	/*链表方法调用attach函数*/
	while (term1&&term2) {
		if (term1->pow > term2->pow) {
			attach(term1->pow, term1->coef, &P);
			term1 = term1->link;
		}
		else if (term1->pow < term2->pow) {
			attach(term2->pow, term2->coef, &P);
			term2 = term2->link;
		}
		else if (term1->pow == term2->pow) {
			if ((term1->coef) + (term2->coef) != 0) {
				attach(term1->pow, (term1->coef) + (term2->coef), &P);
			}
			term1 = term1->link;
			term2 = term2->link;
		}
	}
	while (term1) {
		attach(term1->pow, term1->coef, &P);
		term1 = term1->link;
	}
	while (term2) {
		attach(term2->pow, term2->coef, &P);
		term2 = term2->link;
	}

	return res;
}



Polynomial read() {
	Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));/*申请一个头节点*/
	int N;
	scanf("%d", &N);
	int pow,coef;
	Polynomial temp = P;
	P->link = NULL;
	while (N--) {
		scanf("%d%d", &coef, &pow);
		attach(pow, coef, &temp);/*使用指针是为了使得循环外面的变量会随着更新，也就是按地址传递的关键*/
	}
	return P;/*返回头节点*/
}

void attach(int _pow, int _coef, Polynomial* ptrrear) {
	(*ptrrear)->link = (Polynomial)malloc(sizeof(struct PolyNode));
	(*ptrrear) = (*ptrrear)->link;
	(*ptrrear)->pow = _pow;
	(*ptrrear)->coef = _coef;
	(*ptrrear)->link = NULL;
}

int compare(int num1, int num2) {
	if (num1 > num2)
		return 1;
	else if (num1 < num2)
		return -1;
	else if (num1 == num2)
		return 0;
}

void PrintPoly(Polynomial P) {
	P = P->link;
	int flag=0;
	if (!P) {
		printf("0 0\n");
		return;
	}

		while (P) {
			if (!flag) {
				flag = 1;
			}
			else {
				printf(" ");
			}
			printf("%d %d", P->coef, P->pow);
			P = P->link;
		}
		printf("\n");

}

