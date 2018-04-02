#pragma once
/*
141. Linked List Cycle
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? */

#define NULL 0
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
	// 1.hash
	//unordered_map<ListNode*, int> hash;
	//while (head)
	//{
	//	if (++hash[head]>1)
	//		return true;
	//	head = head->next;
	//}
	//return false;
	
	// 2.two points/runners
	ListNode *fast = head, *slow = head;
	while (fast&&fast->next&&slow)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) return true;
	}
	return false;

	// 3.brute(TLE)
	//if (!head) return false;
	//ListNode *anchor = head, *node;
	//while (anchor->next)
	//{
	//	node = anchor;
	//	while (node = node->next)
	//	{
	//		if (node == anchor)
	//			return true;
	//	}
	//	anchor = anchor->next;
	//}
	//return false;
}