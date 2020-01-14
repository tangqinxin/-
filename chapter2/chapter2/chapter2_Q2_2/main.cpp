#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stdio.h>
#pragma warning(disable: 4996)  
using namespace std;
#define debug(x) cout<<"---->"<<x<<endl
#define MAXN 1005

typedef struct PolyNode *Polynomial;
struct PolyNode {
	int coef; // 系数
	int expon; // 指数
	Polynomial link;
};

void Attach(int c, int e, Polynomial *Rear) {
	Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));

	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*Rear)->link = P;
	*Rear = P;
}

Polynomial ReadPoly() {
	Polynomial P, Rear, t;
	int c, e, N;
	scanf("%d", &N);

	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;

	while (N--) {
		scanf("%d%d", &c, &e);
		Attach(c, e, &Rear);
	}
	t = P;
	P = P->link;
	free(t);
	return P;
}

Polynomial Add(Polynomial P1, Polynomial P2) {
	Polynomial P, Rear, t, t1, t2;
	int sum;

	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while (t1 != NULL &&t2 != NULL) {
		if (t1->expon == t2->expon) {
			sum = t1->coef + t2->coef;
			if (sum)
				Attach(sum, t1->expon, &Rear);
			t1 = t1->link;
			t2 = t2->link;
		}
		else if (t1->expon > t2->expon) {
			Attach(t1->coef, t1->expon, &Rear);
			t1 = t1->link;
		}
		else {
			Attach(t2->coef, t2->expon, &Rear);
			t2 = t2->link;
		}

	}
	while (t1) {
		Attach(t1->coef, t1->expon, &Rear);
		t1 = t1->link;
	}
	while (t2) {
		Attach(t2->coef, t2->expon, &Rear);
		t2 = t2->link;
	}
	Rear->link = NULL;
	t = P;
	P = P->link;
	free(t);
	return P;
}
Polynomial Mult(Polynomial P1, Polynomial P2) {
	Polynomial P, Rear, t1, t2, t;
	int c, e;

	if (!P1 || !P2) {
		return NULL;
	}

	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;

	while (t2) {
		Attach(t1->coef*t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->link;
	}

	t1 = t1->link;
	while (t1) {
		t2 = P2;
		Rear = P;
		while (t2) {
			c = t1->coef*t2->coef;
			e = t1->expon + t2->expon;
			while (Rear->link && Rear->link->expon > e) {
				Rear = Rear->link;
			}
			if (Rear->link && Rear->link->expon == e) {
				if (Rear->link->coef + c == 0) {
					t = Rear->link;
					Rear->link = t->link;
					free(t);
				}
				else {
					Rear->link->coef += c;
				}
			}
			else {
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->expon = e;
				t->link = Rear->link;
				Rear->link = t;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t = P;
	P = P->link;
	free(t);
	return P;
}


void PrintPoly(Polynomial P) {
	int flag = 0;
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
		printf("%d %d", P->coef, P->expon);
		P = P->link;
	}
	printf("\n");
}

int main()
{
	Polynomial P1, P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();
	PP = Mult(P1, P2);
	PrintPoly(PP);
	PS = Add(P1, P2);
	PrintPoly(PS);
	return 0;
}

