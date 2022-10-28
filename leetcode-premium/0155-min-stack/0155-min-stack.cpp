class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        li.push_back(val);
        if (min.empty() 
            || (min.size() 
                && val <= min.back())) min.push_back(val);
    }
    
    void pop() {
        if (li.back() == min.back()) min.pop_back();
        li.pop_back();
    }
    
    int top() {
        return li.back();
    }
    
    int getMin() {
        return min.back();
    }
private:
    vector<int> li;
    vector<int> min;
};