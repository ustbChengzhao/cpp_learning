#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
	int start;
	int len;
	ListNode* next;
	ListNode(int x, int y){
		start = x;
		len = y;
		next = nullptr;
	}
};

ListNode* construct(vector< vector<int> > &nums) {
	ListNode* head = new ListNode(nums[0][0], nums[0][1]);
	ListNode* cur = head;
	
	for (int i = 1 ; i < nums.size(); i++) {
		cur->next = new ListNode(nums[i][0], nums[i][1]);
		cur = cur->next;
	}
	cur->next = head;
	return head;
}


void remove(ListNode* head, int start, int n) {
	if (head->start == start) {
		for (int i = 0; i < n - 1; i++)	 head = head->next;
		head->next = head->next->next;
	}
	
	else {
		while(true) {
			if (head->next->start == start) {
				head->next = head->next->next;
				break;
			}
			head = head->next;
		}
	}
	return;
}

ListNode* tackle(ListNode* head, int len, int& n) {
	int cur = INT_MAX;
	ListNode* target = nullptr;
	for (int i = 0; i < n; i++) {
		if (head->len >= len && head->len < cur) {
			target = head;
			cur = target->len;
		}
		head = head->next;
	}
	
	if(target) {
		// cout << "start: " << target->start << "\tlen: " << target->len << endl;
		if (target->len == len) {
			// cout << "removed " << target->start << endl;
			ListNode* res = target->next;
			remove(head, target->start, n);
			n--;
			return res;
		}
		else {
			// cout << "revised " << target->start << endl;
			target->len = target->len - len;
			return target;
		}
		
	}
	// cout << "mei zhao dao" << "\t" << head->start << endl;
	return head;
}



void display(int n, ListNode* head) {
	for (int i =0 ; i < n; i++) {
		cout << head->start << " " << head->len <<  endl;
		head = head->next;
	}
}


void func() {
	int n;
	cin >> n;
	vector< vector<int> > nums(n, vector<int>(2, 0));
	for(int i = 0; i < n; i++) {
		cin >> nums[i][0] >> nums[i][1];
	} 
	ListNode* head = construct(nums);
	// cout << "constructed!" << endl;
	
	vector<int> user;
	while(true) {
		int input;
		cin >> input;
		if (input == -1)	break;
		user.push_back(input);
	}
	
	for (int i = 0; i < user.size(); i++) {
		// cout << "\ntackle: " << user[i] << endl;
		head = tackle(head, user[i], n);
	}
	
	display(n, head);
}

int main() {
	func();
	
	return 0;
}