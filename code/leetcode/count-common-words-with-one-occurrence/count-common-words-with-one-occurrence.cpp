class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> bucket;
        for(auto word: words1) bucket[word]++;
        for(auto word: words2) bucket[word] += 1000;
        int result = 0;
        for(auto& word: bucket) if(word.second == 1001) result++;
        return result;
    }
};