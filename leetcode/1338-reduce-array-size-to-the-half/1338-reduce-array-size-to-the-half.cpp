class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> counter;
        for (auto a: arr) counter[a]++;
        vector<int> pairs;
        for (auto [key, val]: counter) pairs.push_back(val);
        sort(pairs.begin(), pairs.end(), greater<int>());
        int n = arr.size() >> 1;
        int count = 0, itr = 0;
        while ( count < n) count += pairs[itr++];
        return itr;
    }
};