class Solution {
public:
    int numRabbits(vector<int>& A) {
        unordered_map<int, int> counter;
        int res = 0;
        for (auto a: A) counter[a]++;
        for (auto [key, val]: counter) 
            res += (val + key) / (key + 1) * (key + 1);
        
        return res;
    }
};