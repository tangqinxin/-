#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* ReverseList(ListNode* pHead) {
	ListNode* temp = pHead;//临时变量1
	stack<ListNode*> s;
	while (temp != NULL) {
		s.push(temp);
		temp = temp->next;
	}

	ListNode* temp2;//临时变量2
	ListNode* NewHead = NULL;
	if (!s.empty())
		NewHead = s.top();//记录开头

	while (!s.empty()) {
		temp = s.top();
		s.pop();
		if (!s.empty()) {
			temp2 = s.top();
		}
		else {
			temp2 = NULL;
		}
		temp->next = temp2;
	}
	return NewHead;
}

int main() {
	ListNode* list1 = new ListNode(1);
	ListNode* list2 = new ListNode(2);
	ListNode* list3 = new ListNode(3);
	ListNode* list4 = new ListNode(4);
	ListNode* list5 = new ListNode(5);
	list1->next = list2;
	list2->next = list3;
	list3->next = list4;
	list4->next = list5;
	ListNode* temp = ReverseList(list1);
	return 0;
}