class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0, right = 0, maxf = 0, ans = 0;
        
        unordered_map<char,int> mp;
        
        while ( right < s.size() ) {
            
            maxf = max(maxf, ++mp[s[right]]);
            
            if( (right - left + 1) - maxf > k) mp[s[left]]--, left++;
            
            // ans = max(ans, (right - left + 1));
            
            right++;
        }
        return right - left;
    }
};