class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counter;
        unordered_set<int> bag;
        for (auto a: arr) counter[a]++;
        for (auto [key, val]: counter) bag.insert(val);
        return counter.size() == bag.size();
    }
};