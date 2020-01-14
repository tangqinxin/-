#include<iostream>
struct node {
	int val;
	node* next;
	node* prev;
	node(int val):val(val),next(NULL),prev(NULL){}
};

class list {
private:
	int size;
	node* tail;
	node* head;
public:
	list():size(0),tail(NULL),head(NULL){}
	void addathead(int val) {
		node* newhead = new node(val);
		size++;
		if (head == NULL&&tail==NULL) {
			head = newhead;
			tail = newhead;
		}
		else {
			head->prev = newhead;
			newhead->next = head;
			head = newhead;
		}
	}
	void addattail(int val) {
		if (head == NULL&&tail == NULL) {
			addathead(val);
		}
		else {
			node* newnode = new node(val);
			size++;
			tail->next = newnode;
			newnode->prev = tail;
			tail = tail->next;
		}
	}

	node* getnode(int index) {
		if (index<0 || index>size)
			return NULL;
		node* temp;
		if (index <= size / 2) {
			temp = head;
			int i = index;
			while (i--) {
				temp = temp->next;
			}
		}
		else {
			temp = tail;
			int i = size - index;
			while (i--) {
				temp = temp->prev;
			}
		}
		return temp;
	}
};

int main() {
	using namespace std;
	list L;
	for (int i = 0; i < 10; i++) {
		L.addattail(i);
	}
	cout << L.getnode(7)->val << endl;
	getchar();
	getchar();
	return 0;
}