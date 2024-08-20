#include<iostream>
#include<vector>
using namespace std;

class ArrayStack {
	private:
		vector<int> stack;
		
	public:
		int size() {
			return stack.size();
		}
		
		bool isEmpty() {
			return stack.empty();
		}
		
		void push(int val) {
			stack.push_back(val);
		} 
		
		int pop() {
			int num = top();
			stack.pop_back();
			return num;
		}
		
		int top() {
			if (isEmpty()) {
				throw out_of_range("stack is empty");
			}
			return stack.back();
		}
		
		vector<int> toVector() {
			return stack;
		}
		
		
};
