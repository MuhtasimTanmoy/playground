class Solution {
public:
    int maxDifference(string s) {
        vector<int> count(26, 0);
        for (auto c: s) count[c - 'a']++;
        sort(count.begin(), count.end());
        int odd_min = INT_MAX, odd_max = INT_MIN, even_min = INT_MAX, even_max = INT_MIN;
        for (auto c: count) {
            if (!c) continue;
            if (c & 1)
                odd_min = min(odd_min, c), odd_max = max(odd_max, c);
            else 
                even_min = min(even_min, c), even_max = max(even_max, c);
        }
        return max(odd_min - even_max, odd_max - even_min); 
    }
};