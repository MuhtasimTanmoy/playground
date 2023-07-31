class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
        function<int(char)> go = [&](auto to) {
            int l = 0;
            for (int i = 0, max_occur = 0; i < ans.size(); i++) 
                max_occur += ans[i] == to,
                max_occur -= max_occur > k ? ans[l++] == to: 0;
            return ans.size() - l;
        };
        return max(go('T'), go('F'));
    }
};