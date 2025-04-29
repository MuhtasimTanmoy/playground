class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<int, bool>> counter;
        s.push_back('2');

        int total_active = 0;
        for (auto i = 1, count = 1; i < s.size(); i++) {
            if (s[i] != s[i-1]) 
                counter.push_back({count, s[i-1] == '1'}),
                count = 1;
            else count++;
            total_active += s[i-1] == '1';
        }
        
        auto max_len = 0;
        for (auto i = 1; i < counter.size() - 1; i++) {
            if (counter[i-1].second != false) continue;
            auto total = counter[i-1].first + counter[i].first + counter[i+1].first;
            max_len = max(max_len, total - counter[i].first);
        }
        
        return total_active + max_len;
    }
};