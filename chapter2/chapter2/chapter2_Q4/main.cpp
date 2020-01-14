#include <iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



bool isPalindrome(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* temp = head;
		ListNode* last = NULL;

		if (head == NULL) {
			return true;
		}
		if (head != NULL&&head->next == NULL) {
			return true;
		}
		if (head->next != NULL&&head->next->next == NULL) {
			if (head->val == head->next->val)
				return true;
			else return false;
		}

		while (fast->next != NULL&&fast->next->next != NULL) {
			temp = slow;
			fast = fast->next->next;
			slow = slow->next;
			if (last == NULL) {
				last = head;
				last->next = NULL;
			}
			else {
				temp->next = last;
				last = temp;
			}
		}
		//找到中点
		if (fast->next == NULL) {
			//奇数
			fast = slow->next;
			slow = temp;
		}
		else {
			//偶数
			fast = slow->next;
			slow->next = temp;
		}
		while (fast != NULL&&slow != NULL) {
			if (fast->val != slow->val) {
				return false;
			}
			fast = fast->next;
			slow = slow->next;
		}
		return true;
}

int main(){
	ListNode* l1;
	ListNode* l2;
	ListNode* res;
	bool boolres;
	l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(3);
	l1->next->next->next->next = new ListNode(2);
	l1->next->next->next->next->next = new ListNode(2);

	l2 = new ListNode(5);
	l2->next = new ListNode(7);
	boolres = isPalindrome(l1);

	return 0;
}