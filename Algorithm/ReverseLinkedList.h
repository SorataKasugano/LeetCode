#pragma once
/*
206. Reverse Linked List
Reverse a singly linked list.
Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both? */

#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
	// 1.iterative
	if (!head || !head->next) return head;
	ListNode *prev = nullptr, *next = nullptr;
	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return prev;

	// 2.recursive
	//if (!head || !head->next) return head;
	//ListNode* ret = reverseList(head->next);
	//head->next->next = head;
	//head->next = nullptr;
	//return ret;
}