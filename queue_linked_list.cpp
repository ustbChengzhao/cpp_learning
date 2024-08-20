#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val): val(val), next(nullptr) {
	}
};

class LinkedListQueue{
	private:
		ListNode* front;
		ListNode* rear;
		int queSize;
		
	public:
		LinkedListQueue() {
			front = nullptr;
			rear = nullptr;
			queSize = 0;
		}
		
		~LinkedListQueue() {
			
		}
		
		int size() {
			return queSize;
		}
		
		bool isEmpty() {
			return size() == 0;
		}
		
		void push(int num) {
			ListNode* node = new ListNode(num);
			if (front == nullptr) {
				front = node;
				rear = node;
			}
			
			else {
				rear->next = node;
				rear = node;
			}
			queSize++;
		}
		
		int pop() {
			int num = peek();
			ListNode* temp = front;
			front = temp->next;
			
			delete temp;
			queSize--;
			return num;
		}
		
		int peek() {
			if (isEmpty()) {
				cout << "empty" << endl;
			}
			
			return front->val;
		}
		
		vector<int> toVector() {
			ListNode* node = front;
			vector<int> res(size());
			for (int i = 0; i < size(); i++) {
				res[i] = node->val;
				node = node->next;
			}
			return res;
		}
};

int main() {
	LinkedListQueue queue = LinkedListQueue();
	queue.push(1);
	queue.push(2);
	queue.push(3);
	cout << queue.peek() << endl;
	queue.pop();
	cout << queue.peek() << endl;
	return 0;
}
