class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> count(26, 0);
        int replace = 0;
        for (auto &c: s) if (c != '?') count[c - 'a']++; else replace++;
                
        auto extract_lowest = [&](int res = 0) {
            for (auto i = 0, min_in = INT_MAX; i < 26; i++)
                if (count[i] < min_in) 
                    min_in = count[i], res = i;
            return res;
        };
        
        vector<char> to_replace;
        while (replace--) {
            auto low = extract_lowest();
            to_replace.push_back('a' + low);
            count[low]++;
        }
        sort(to_replace.begin(), to_replace.end());
        
        replace = 0;
        for (auto &c: s)
            if (c == '?') 
                c = to_replace[replace++];
        return s;
    }
};