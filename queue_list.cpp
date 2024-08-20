#include<iostream>
#include<vector>
using namespace std;

class ArrayQueue {
	private:
		int *nums;
		int front;
		int queSize;
		int queCapacity;
		
	public:
		ArrayQueue(int capacity) {
			nums = new int[capacity];
			queCapacity = capacity;
			front = queSize = 0;
		}
		
		~ArrayQueue() {
			delete[] nums;
		}
		
		int capacity() {
			return queCapacity;
		}
		
		int size() {
			return queSize;
		}
		
		bool isEmpty() {
			return size() == 0;
		}
		
		void push(int num) {
			if (queSize == queCapacity) {
				cout << "dui lie yi man" << endl;
			}
			int rear = (front + queSize) % queCapacity;
			nums[rear] = num;
			queSize++;
		}
		
		int pop() {
			int num = peek();
			front = (front + 1) % queCapacity;
			queSize--;
			return num;
		}
		
		int peek() {
			if (isEmpty()) {
				//throw out_of_range("empty");
			}
			return nums[front];
		}
		
		vector<int> toVector() {
			vector<int> arr(queSize);
			for (int i = 0, j = front; i < queSize; i++, j++) {
				arr[i] = nums[j % queCapacity];
			}
			return arr;
		}
};

int main() {
	ArrayQueue queue = ArrayQueue(10);
	queue.push(1);
	queue.push(2);
	queue.push(3);
	cout << queue.peek() << endl;
	queue.pop();
	cout << queue.peek() << endl;
	return 0;
}
