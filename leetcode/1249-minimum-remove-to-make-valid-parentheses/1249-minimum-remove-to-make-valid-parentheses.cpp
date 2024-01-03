class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> invalid_index;
        for (auto i = 0; i < s.size(); i++) 
            if (s[i] == '(') invalid_index.push_back(i);
            else if  (s[i] == ')') {
                if (invalid_index.size() && s[invalid_index.back()] == '(')                                    invalid_index.pop_back();
                else invalid_index.push_back(i);
            }
        string res;
        for (auto i = 0, j = 0; i < s.size(); i++) {
            if (j < invalid_index.size() && invalid_index[j] == i) { j++; continue; }
            res += s[i];
        }
        return res;
    }
};