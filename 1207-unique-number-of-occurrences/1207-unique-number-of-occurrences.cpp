class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> occur(2001, 0);
        for (auto a: arr) 
            occur[a+1000]++;
        unordered_set<int> tracker;
        for (auto c: occur) 
            if (c)
                if (tracker.count(c)) return false;
                else tracker.insert(c);
        return true;
    }
};