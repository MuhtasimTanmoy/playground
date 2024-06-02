class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> counter;
        for (auto i = 0; i < word.size(); i += k) 
            counter[word.substr(i, k)]++;
        
        int total = 0, max_of_them = 0;
        for (auto [_, count]: counter) 
            max_of_them = max(max_of_them, count),
            total += count;
        return total - max_of_them;
    }
};