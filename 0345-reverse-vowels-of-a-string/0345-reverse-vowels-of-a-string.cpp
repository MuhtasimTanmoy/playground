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