class MinStack {
    vector<int> stack;
public:
    MinStack() {}
    
    void push(int val) {
        if (size(stack)) stack.push_back(min(val, getMin()));
        else stack.push_back(val);
        
        stack.push_back(val);
    }
    
    void pop() {
        stack.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack[size(stack) - 1];
    }
    
    int getMin() {
        int topElem = top();
        stack.pop_back();
        
        int minElem = top();
        stack.push_back(topElem);
        return minElem;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */