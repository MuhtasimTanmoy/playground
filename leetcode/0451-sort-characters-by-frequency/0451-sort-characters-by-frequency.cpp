class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> freq(150, {0, 0});
        for (auto c: s)
            freq[c].first = c,
            freq[c].second++;
        
        sort(freq.begin(), freq.end(), [](auto a, auto b) {
            return a.second > b.second;
        });
        
        string res = "";
        for (auto [key, count]: freq) while (count--) res += key;
        return res;
    }
};