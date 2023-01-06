class Solution {
public:
    int closetTarget(vector<string>& words, string target, int s) {
        int n = words.size(), ans = INT_MAX;
        for (int i = 0; i < n; i++) 
            if (words[i] == target) 
                 ans = min(ans, min(abs(s - i), abs(n - abs(s - i)))); 
        return ans == INT_MAX ? -1 : ans;
    }
};