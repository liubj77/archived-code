// Filename: min_stack.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */

class MinStack {
public:
    void push(int x) {
        stack1.push(x);
        int min = x;
        if (stack2.size()) {
            min = x < stack2.top() ? x : stack2.top();
        }
            
        stack2.push(min);
    }

    void pop() {
        stack1.pop();
        stack2.pop();
    }

    int top() {
        return stack1.top();
    }

    int getMin() {
        return stack2.top();
    }
private:
    stack<int> stack1;
    stack<int> stack2;  // min stack
};
