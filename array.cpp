#include<iostream> 
using namespace std;

	
int randomAccess(int* nums, int size) {
	int randomIndex = rand() % size;
	int randomNumber = nums[randomIndex];
	
	return randomNumber;
}

void insert(int *nums, int size, int num, int index) {
	for (int i = size - 1; i > index; i--) {
		nums[i] = nums[i - 1];
	}
	nums[index] = target;
}

void remove(int *nums, int size, int index) {
	for (int i = index; i < size - 1; i++) {
		nums[i] = nums[i + 1];
	}
}

void traverse(int *nums, int size) {
	for (int i = 0; i < size; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

int find(int *nums, int size, int target) {
	for (int i = 0; i < size; i++) {
		if (nums[i] == target) {
			return i;
		}
	}
	return -1;
}

int *extend(int *nums, int size, int enlarge) {
	int *res = new int[size + enlarge];
	for (int i = 0; i < size; i++) {
		res[i] = nums[i];
	}
	delete[] nums;
	return res;
}



int main() {
	int* arr = new int[5];
	int* nums = new int[5] {1, 2, 3, 4, 5};
	
	cout << randomAccess(nums, 5) << endl;
	
	return 0;
}
