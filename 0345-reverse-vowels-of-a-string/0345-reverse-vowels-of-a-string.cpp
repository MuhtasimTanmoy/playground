class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        auto isVowel = [&](char c) { return vowelSet.count(c); };
        
        while(left < right) {
            auto leftChar = s[left], rightChar = s[right];
            if (isVowel(leftChar) && isVowel(rightChar)) swap(s[left++], s[right--]);
            else if (isVowel(leftChar) || isVowel(rightChar)) {
                if (isVowel(leftChar)) right--;
                if (isVowel(rightChar)) left++;
            } else right--, left++;
        }
        
        return s;
    }
};