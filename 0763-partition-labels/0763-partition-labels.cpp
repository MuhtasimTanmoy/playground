class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> li(26, make_pair(-1, -1));
        for (int i = 0; i < s.size(); i++) {
            auto c = s[i] - 'a';
            if (li[c].first  == -1) li[c].first = i;
            li[c].second = i;  
        }
        
        vector<int> lengths;
        int index = 0;
        while (index < s.size()) {
            int target = li[s[index]-'a'].second;
            int start = index;
            while (index < target && index < s.size()) {
                target = max(target, li[s[index]-'a'].second);
                index++;
            }
            index++;
            lengths.push_back(index - start);
        }
        return lengths;
    }
};