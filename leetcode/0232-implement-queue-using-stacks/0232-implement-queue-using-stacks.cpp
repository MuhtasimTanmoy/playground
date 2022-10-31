class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) {
        holder.push_back(x);
    }
    
    int pop() {
        if (q.empty()) refill();
        auto item = q.back();
        q.pop_back();
        return item;
    }
    
    int peek() {
        if (q.empty()) refill();
        return q.back();
    }
    
    bool empty() {
        return holder.empty() && q.empty();
    }
private:
    vector<int> holder;
    vector<int> q;
    
    void refill() {
        while (holder.size()) {
            q.push_back(holder.back());
            holder.pop_back();
        }
    }
};