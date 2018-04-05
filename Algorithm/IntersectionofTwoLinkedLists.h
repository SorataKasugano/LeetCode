#pragma once
/*
160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:           a1 ¡ú a2
					 ¨K
					   c1 ¡ú c2 ¡ú c3
					 ¨J
B:     b1 ¡ú b2 ¡ú b3

begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory. */

#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	// 1.two pointers
	ListNode *nodeA = headA, *nodeB = headB;
	while (nodeA != nodeB)
	{
		nodeA = nodeA ? nodeA->next : headB;
		nodeB = nodeB ? nodeB->next : headA;
	}
	return nodeA;
	// 2.a strange solution in fact not O(n)
	//if (!headA || !headB) return nullptr;
	//ListNode *lastA = nullptr, *lastB = nullptr, *nodeA = headA, *nodeB = headB;
	//while (nodeA != nodeB)
	//{
	//	nodeA = nodeA->next;
	//	nodeB = nodeB->next;
	//	if (!nodeA) nodeA = headA;
	//	if (!nodeB) nodeB = headB;
	//	if (!nodeA->next) lastA = nodeA;
	//	if (!nodeB->next) lastB = nodeB;
	//	if (lastA&&lastB&&lastA != lastB) return nullptr;
	//}
	//return nodeA;
}