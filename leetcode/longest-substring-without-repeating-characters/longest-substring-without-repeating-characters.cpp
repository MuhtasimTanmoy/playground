// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int len = 0;
//         int left = -1;
//         int right = 0;
//         unordered_set<char> bag;
    
//         while(left < size(s) && right < size(s)) { 
//             cout<<right<<endl;
//             if (bag.count(s[right]) == 0) {
//                 bag.insert(s[right]);
//                 len = max(len, right - left + 1);
//                 right++;
//             } else {
//                 while(bag.count(s[++left]))
//                     bag.erase(s[left]);
//             }
//         }
//         return len;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> cnt(128, 0);
        
        int left = 0, right = 0, res = 0;
        
        while (right < s.size()) {
            
            ++cnt[s[right]];
            
            while (cnt[s[right]] > 1) --cnt[s[left++]];
            
            res = max(res, right - left + 1 );
            
            ++right;
        }
        
        return res;
    }
};