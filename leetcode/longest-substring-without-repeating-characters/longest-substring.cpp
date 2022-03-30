class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(),l=0,r=0,mx=0;
        int mp[127]={0};
        while(r<n)
        {
            if(mp[s[r]]==0)
            {
               (mp[s[r]]++);
                mx=max(mx,r-l+1);
                r++;
            }
            else
            {
                mp[s[l]]--;
                l++;
            }
        }
        return mx;
    }
};