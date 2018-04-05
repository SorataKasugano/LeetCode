#pragma once
/*
155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2. */

#include <vector>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		values_.push_back(x);
		if (mins_.empty() || x <= mins_.back()) mins_.push_back(x);
	}

	void pop() {
		if (values_.back() == mins_.back()) mins_.pop_back();
		values_.pop_back();
	}

	int top() {
		return values_.back();
	}

	int getMin() {
		return mins_.back();
	}

private:
	vector<int> values_;
	vector<int> mins_;
};