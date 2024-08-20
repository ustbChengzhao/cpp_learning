#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
	private:
		vector<int> maxHeap;
		
		int left(int i) {
			return 2 * i + 1;
		}
		
		int right(int i) {
			return 2 * i + 2;
		}
		
		int parent(int i) {
			return (i - 1) / 2;
		}
		
		void shiftUp(int index) {
			while(true) {
				int p = parent(index);
				
				// 遍历至堆顶 或 当前元素小于父节点 
				if (p < 0 || maxHeap[index] <= maxHeap[p]) {
					break;
				}
				swap(maxHeap[index], maxHeap[p]);
				index = p;
			}
		}
		
		void shiftDown(int index) {
			while(true) {
				int l = left(index);
				int r = right(index);
				int ma = index;
				
				if (l < size() && maxHeap[l] > maxHeap[ma]) {
					ma = l;
				}
				if (r < size() && maxHeap[r] > maxHeap[ma]) {
					ma = r;
				}
				if (ma == index) {
					break;
				}
				
				swap(maxHeap[index], maxHeap[ma]);
				
				index = ma;
			}
		}
	
	public:
		MaxHeap() {
			
		}
		
		MaxHeap(vector<int> nums) {
			maxHeap = nums;
			for (int i = parent(size() - 1); i >= 0; i--) {
				shiftDown(i);
			}
		}
		
		int size() {
			return maxHeap.size();
		}
		
		int isEmpty() {
			return size() == 0;
		}
		
		int peek() {
			return maxHeap[0];
		}
		
		void push(int val) {
			maxHeap.push_back(val);
			shiftUp(size() - 1);
		}
		
		void pop() {
			if (isEmpty()) {
				throw out_of_range("堆为空");
			}
			swap(maxHeap[0], maxHeap[size() - 1]);
			maxHeap.pop_back();
			shiftDown(0);
		}
};

int main() {
	vector<int> nums = {1, 2, 4, 10, 11, 7, 5};
	
	MaxHeap maxHeap =  MaxHeap(nums);
	
	int peek = maxHeap.peek();
	
	cout << peek << endl;
	
	return 0;
	
}
