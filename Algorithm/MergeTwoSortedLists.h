#pragma once
/*
21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should 
be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4 */

#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	// 1.iterative
	if (!l1 || !l2) return !l1 ? l2 : l1;
	ListNode* curr = (l1->val <= l2->val) ? l1 : l2;
	ListNode* comp = (l1->val <= l2->val) ? l2 : l1;
	ListNode* ret = curr, *tmp = nullptr;
	while (curr->next)
	{
		if (curr->val <= comp->val && curr->next->val>comp->val)
		{
			tmp = comp;
			comp = curr->next;
			curr->next = tmp;
		}
		else
			curr = curr->next;
	}
	curr->next = comp;
	return ret;

	// 2.iterative
	//ListNode ret(0);
	//ListNode* iter = &ret;
	//while (l1&&l2)
	//{
	//	if (l1->val<l2->val)
	//	{
	//		iter->next = l1;
	//		l1 = l1->next;
	//	}
	//	else
	//	{
	//		iter->next = l2;
	//		l2 = l2->next;
	//	}
	//	iter = iter->next;
	//}
	//iter->next = !l1 ? l2 : l1;
	//return ret.next;

	// 3.recursive
	//if (!l1 || !l2) return !l1 ? l2 : l1;
	//if (l1->val<l2->val)
	//{
	//	l1->next = mergeTwoLists(l1->next, l2);
	//	return l1;
	//}
	//else
	//{
	//	l2->next = mergeTwoLists(l1, l2->next);
	//	return l2;
	//}
}