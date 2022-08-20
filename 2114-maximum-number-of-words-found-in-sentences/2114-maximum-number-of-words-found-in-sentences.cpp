class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for (auto sentence: sentences) {
            int counter = 1;
            for (auto c: sentence) if (c == ' ') counter++;
            ans = max(ans, counter);
        }
        return ans;
    }
};