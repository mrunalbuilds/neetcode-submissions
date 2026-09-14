class MinStack {
public:
    //2 stack  stack and minstack
    std::stack<int> stack;
    std::stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push(val);
        val = std::min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
