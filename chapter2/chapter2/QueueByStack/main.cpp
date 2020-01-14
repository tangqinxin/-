#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
	stack<int> STACK1;
	stack<int> STACK2;
	int flag;
public:
	/** Initialize your data structure here. */
	MyQueue() :flag(1) {     }

	/** Push element x to the back of queue. */
	void push(int x) {
		if (flag == 1) {
			STACK1.push(x);
		}
		else if (flag == 2) {
			STACK2.push(x);
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int res;
		if (flag == 1) {
			while (STACK1.size()) {
				STACK2.push(STACK1.top());
				STACK1.pop();
			}
			res = STACK2.top();
			STACK2.pop();
			flag = 2;
		}
		else if (flag == 2) {
			while (STACK2.size()) {
				STACK1.push(STACK2.top());
				STACK2.pop();
			}
			res = STACK1.top();
			STACK1.pop();
			flag = 1;
		}
		return res;
	}

	/** Get the front element. */
	int peek() {
		int res;
		if (flag == 1) {
			while (STACK1.size()) {
				STACK2.push(STACK1.top());
				STACK1.pop();
			}
			res = STACK2.top();
			flag = 2;
		}
		else if (flag == 2) {
			while (STACK2.size()) {
				STACK1.push(STACK2.top());
				STACK2.pop();
			}
			res = STACK1.top();
			flag = 1;
		}
		return res;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (flag == 1) {
			return STACK1.empty();
		}
		else
			return STACK2.empty();
	}
};

int main() {
	MyQueue M;
	M.push(1);
	M.push(2);
	M.peek();
	M.pop();
	M.empty();
	return 0;
}