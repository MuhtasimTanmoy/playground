class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        deque<int> to;
        for (auto i: popped) to.push_back(i);
        
        vector<int> stk;
        for (auto i: pushed) {
            stk.push_back(i);
            while (stk.size() && stk.back() == to.front()) 
                stk.pop_back(),
                to.pop_front();
        }
        
        return stk.empty();
    }
};