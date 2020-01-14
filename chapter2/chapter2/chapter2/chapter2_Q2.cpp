#include<stdio.h>
#include<malloc.h>
#pragma warning(disable: 4996)  
typedef struct PolyNode* Polynomial;
struct PolyNode {
	int pow;
	int coef;
	Polynomial link;
};

/*��ȡһ������ʽ*/
Polynomial read();
/*�������ʽ�����*/
Polynomial add(Polynomial P1, Polynomial P2);
/*����˻�����ʽ�����*/
Polynomial Multi(Polynomial P1, Polynomial P2);

/*�������ʽ*/
void PrintPoly(Polynomial P);
void attach(int _pow, int _coef, Polynomial* ptrrear);

int main() {
	Polynomial P1;
	Polynomial P2; /*��������ʽP1,P2���ڶ�ȡ*/
	Polynomial res,res2;
	P1 = read();/*��ȡ����ʽP1*/
	P2 = read();/*��ȡ����ʽP2*/
	res2 = Multi(P1, P2);
	PrintPoly(res2);
	res = add(P1, P2);
	PrintPoly(res);
	getchar();
	getchar();
	return 0;
}

/*�˷�����˵����
1.���ʹ�����ȳ˳�������ADD�ӵ�����ķ����Ļ���������һ���ռ������洢ADD����ʱ����ʽ����������˷��ⲿ�ֿռ䣬��ô��þ�Ҫ����
дһ��ADD2����������������ķ�����˳���ͷŵ���Ӧ�Ŀռ䡣
2.���������õ��ǣ�
1.�����P1�ĵ�һ���P2�õ�һ�������Ľ��
2.P1���������P2��Ȼ����бȽ�ָ���Ͳ�ֵ������͵�һ�����ҵ�Ƚ���*/
Polynomial Multi(Polynomial P1, Polynomial P2) {
	/*�ж�P1��P2ΪNULL�����������NULL*/
	if (!P1 || !P2)
		return NULL;
	/*�ȼ���P1��һ���P2*/
	Polynomial res = (Polynomial)malloc(sizeof(struct PolyNode));/*����ͷ�ڵ�*/
	Polynomial t1, t2,rear;
	t1 = P1->link;
	t2 = P2->link;
	rear = res;
	int pow, coef;
	while (t2) {/*�˳���һ��*/
		pow = t1->pow + t2->pow;
		coef=t1->coef*t2->coef;
		attach(pow,coef,&rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while (t1) {
		t2 = P2->link;/*����Ϊ����Ҫ�޸�*/
		rear = res;
		while (t2) {
			pow = t1->pow+t2->pow;
			coef = t1->coef*t2->coef;

			while (rear->link&&rear->link->pow>pow) {/*������õ��ĵ�����������Ѱ�Ҳ���λ��,������rear->link������rear��Ϊ�˱���ǰ�ڵ����Ϣ��
													 ���Ǳ�����ʱ���ÿһ�������ݵĽڵ㣨�������һ���ڵ㣩Ҳ�����������������ʵ����Ҫ�����һ���ڵ��������Ĵ���*/
				rear = rear->link;/*���ָ�������ϻ��ߵ������һ���ʱ���������ʣ��Ҫô��ָ����ȵ������Ҫô��ȱ��������*/
			}
			if (rear->link&&rear->link->pow == pow) {/*ָ����ȵ�������ֿ�Ϊ��͵���0�Ͳ�����0������*/
				if (rear->link->coef + coef == 0) {
					Polynomial temp = rear->link;
					rear->link = rear->link->link;/*�ν�����*/
					free(temp);
				}
				else {
					rear->link->coef = rear->link->coef + coef;
				}
			}
			else {/*�������Ϊrear->linkΪ�ջ��������м������һ����Ѿ��������һ����,���ڵ�һ���Ѿ��˳����ˣ���˻����ϲ�����С����ߴεĵ�pow,�������ǲ���*/
				/*���ﲻ��ʹ��attach����Ϊattach��������ɶ�����attach��û�������������Ĺ��ܣ�������������Լ��ֶ�д�������*/
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

	return res;/*��ӡ�ĺ������Ǵ�ͷ�ڵ�ģ�����Ϊ���صĽ��ҲӦ�ô�ͷ�ڵ㣬�����޸Ĵ�ӡ�ĺ���*/
}



Polynomial add(Polynomial P1, Polynomial P2) {
	Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
	Polynomial res = P;
	Polynomial term1 = P1->link;
	Polynomial term2 = P2->link;
	/*����������attach����*/
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
	Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));/*����һ��ͷ�ڵ�*/
	int N;
	scanf("%d", &N);
	int pow,coef;
	Polynomial temp = P;
	P->link = NULL;
	while (N--) {
		scanf("%d%d", &coef, &pow);
		attach(pow, coef, &temp);/*ʹ��ָ����Ϊ��ʹ��ѭ������ı��������Ÿ��£�Ҳ���ǰ���ַ���ݵĹؼ�*/
	}
	return P;/*����ͷ�ڵ�*/
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

