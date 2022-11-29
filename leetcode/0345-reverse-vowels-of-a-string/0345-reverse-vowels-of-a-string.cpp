class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        auto isVowel = [&](char c) { return vowelSet.count(c); };
        while (left < right) {
            auto isleftCharVowel = isVowel(s[left]), isRightCharVowel = isVowel(s[right]);
            if (isleftCharVowel && isRightCharVowel) swap(s[left++], s[right--]);
            else {
                if (!isleftCharVowel) left++;
                if (!isRightCharVowel) right--;
            }
        }
        return s;
    }
};

class Solution  {
public:
    string reverseVowels(string s) {
        set<char> vwls = {'a','e','i','o','u','A','E','I','O','U'};
        int l = 0, r = s.size()-1;
        while (l < r) {
            l += !vwls.count(s[l]);
            r -= !vwls.count(s[r]);
            if (vwls.count(s[l]) && vwls.count(s[r]))
                swap(s[l++], s[r--]);
        }
        return s;
    }
};