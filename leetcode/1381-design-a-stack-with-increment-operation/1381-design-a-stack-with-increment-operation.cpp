class CustomStack {
    int limit;
    vector<int> stk, inc;
public:
    CustomStack(int maxSize) {
        limit = maxSize;
    }
    
    void push(int x) {
        if (stk.size() == limit) return;
        stk.push_back(x);
        inc.push_back(0);
    }
    
    int pop() {
        if (stk.empty()) return -1;
        auto val = stk.back(), inc_by = inc.back();
        
        stk.pop_back();
        inc.pop_back();
        
        if (inc.size()) inc.back() += inc_by;
        return val + inc_by;
    }
    
    void increment(int k, int val) {
        auto len = min(k, (int) stk.size()) - 1;
        if (len >= 0) inc[len] += val;
    }
};