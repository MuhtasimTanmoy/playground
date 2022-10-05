class Solution {
    int pCount(const string &s, int left, int right) {
        int ans = 0;
        while(left >=0 && right < size(s) && s[left] == s[right]) {
            ans++;
            left--;
            right++;
        }
        return ans;
    }
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < size(s); i++) {
            count += pCount(s, i, i);
            count += pCount(s, i, i + 1);
        }
        return count;
    }
};