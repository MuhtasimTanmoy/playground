class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> mapper;
        for (int i = 0; i < keyboard.size(); i++) mapper[keyboard[i]] = i;
        
        int prev_index = 0, sum = 0;
        for (auto c: word) {
            auto now_index = mapper[c];
            sum += abs(now_index - prev_index);
            prev_index = now_index;
        }
        return sum;
    }
};