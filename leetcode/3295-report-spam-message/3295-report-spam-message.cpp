class Solution {
public:
    bool reportSpam(vector<string>& messages, vector<string>& banned) {
        unordered_set<string> bag(banned.begin(), banned.end());
        bool has = false;
        for (auto message: messages)
            if (bag.count(message)) {
                if (has) return true;
                has = true;
            }
        return false;    
    }
};