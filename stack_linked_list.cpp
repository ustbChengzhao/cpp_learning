#include<iostrema>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val): val(val), next(nullptr) {
	}
};

class LinkedListStack{
	private:
		ListNode* stackTop;
		int stkSize;

	public:
		LinkedListStack() {
			stackTop = nullptr;
			stkSize = 0;
		}
		
		~LinkedListStack() {
			free
		}
		
		int size() {
			return stkSize;
		}
		
		bool isEmpty() {
			return stkSize == 0;
		}
		
		void push(int num) {
			ListNode* node = new ListNode(num);
			node->next = stackTop;
			stackTop = node;
			stkSize++;
		}
		
		int pop() {
			int num = top();
			ListNode *temp = stackTop;
			stackTop = stackTop->next;
			
			delete temp;
			stkSize--;
			return num;
		}
		
		int top() {
			if (isEmpty()) {
				throw out_of_range("stack is empty");
			}
			return stackTop->val;
		}
		
		vector<int> toVector() {
			ListNode* node = stackTop;
			vector<int> res(size());
			for (int i = 0; i < size(); i++) {
				res[i] = stackTop->val;
				stackTop = stackTop->next;
			}
			return res;
		}
};
int main() {
	 
}
