#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr) {}
};

void insert(ListNode *n0, ListNode *p) {
	p->next = n0->next;
	n0->next = p;
}

void remove(ListNode* n0) {
	if (n0->next == nullptr) {
		return;
	}
	ListNode* p = n0->next;
	ListNode* n1 = p->next;
	n0->next = n1;
	
	delete p;
}

ListNode* access(ListNode* head, int index) {
	for (int i = 0; i < index; i++) {
		if (head == nullptr) {
			return head;
		}
		head = head->next;
	}
	return head;
}

int find(ListNode* head, int target) {
	int index = 0;
	while(head != nullptr) {
		if (head->val == target) {
			return index;
		}
		head = head->next;
		index++;
	}
	return -1;
}

void traverse(ListNode* head) {
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	ListNode* n0 = new ListNode(1);
	ListNode* n1 = new ListNode(3);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(5);
	ListNode* n4 = new ListNode(4);
	
	
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	
	ListNode* n5 = new ListNode(10);
	insert(n0, n5);
	remove(n1);
	traverse(n0);
	return 0;
}
