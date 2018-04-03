#pragma once
/*
234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space? */

#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
	// O(n) time and O(1) space
	if (!head || !head->next) return true;
	// get latter part behind middle of list
	ListNode *fast = head, *slow = head;
	while (fast&&fast->next&&fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	slow = slow->next;
	// reverse latter part
	ListNode *prev = nullptr, *next;
	while (slow)
	{
		next = slow->next;
		slow->next = prev;
		prev = slow;
		slow = next;
	}
	// match former part and reversed latter part
	while (prev)
	{
		if (head->val != prev->val) return false;
		head = head->next;
		prev = prev->next;
	}
	return true;
}