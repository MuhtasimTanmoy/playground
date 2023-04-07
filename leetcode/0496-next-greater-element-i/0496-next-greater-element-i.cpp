class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& l, vector<int>& r) {
        vector<int> res(l.size(), -1);
        unordered_map<int, int> l_val_to_idx;
        for (int i = 0; i < l.size(); i++) l_val_to_idx[l[i]] = i;
        
        vector<int> stk;
        for (auto elem: r) {
            while (stk.size() && elem > stk.back()) {
                auto m = stk.back(), 
                target_idx = l_val_to_idx.count(m) ? l_val_to_idx[m]: -1;
                if (target_idx != -1) res[target_idx] = elem;
                stk.pop_back();
            }
            stk.push_back(elem);
        }
        return res;
    }
};