class MyStack {
private:
    queue<int> data;
public:
    MyStack() {}
    
    void push(int x) {
        data.push(x);
        for (int i = 0; i < data.size() - 1; ++i) 
            data.push(pop());
    }
    
    int pop() {
        int result = top();
        data.pop();
        return result;
    }
    
    int top() {
        return data.front();
    }
    
    bool empty() {
        return data.empty();
    }
};