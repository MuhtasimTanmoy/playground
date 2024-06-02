class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> to_delete, other;
        for (auto i = 0; i < s.size(); i++) {
            if (s[i] == '(') to_delete.push_back(i);
            else if (s[i] == ')')
                if (to_delete.size()) to_delete.pop_back();
                else other.push_back(i);
        }
        unordered_set<int> bag(to_delete.begin(), to_delete.end());
        bag.insert(other.begin(), other.end());
        for (auto i = 0, r = 0; i < s.size(); i++) {
            if (bag.count(i)) continue;
            s[r++] = s[i];
        }
        s.resize(s.size() - bag.size());
        return s;
    }
};