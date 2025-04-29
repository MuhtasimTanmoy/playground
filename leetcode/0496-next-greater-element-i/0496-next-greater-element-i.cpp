class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& l, vector<int>& r) {
        vector<int> next_greater(r.size(), -1);
        vector<int> stk;
        for (auto i = 0; i < r.size(); i++) {
            while (stk.size() && r[stk.back()] < r[i]) {
                auto pre = stk.back(); stk.pop_back();
                next_greater[pre] = i;
            }
            stk.push_back(i);
        }
    
        unordered_map<int, int> idx;
        for (auto i = 0; i < r.size(); i++) idx[r[i]] = i;

        vector<int> res;
        for (auto i: l) {
            auto now = next_greater[idx[i]];
            if (now != -1) now = r[now];
            res.push_back(now);
        }
        return res;
    }
};