class Solution {
public:
    bool halvesAreAlike(string s) {
        int left = 0, right = s.size() - 1;
        unordered_set<char> bag = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count = 0;
        while (left < right) {
            if (bag.count(s[left++])) count++;
            if (bag.count(s[right--])) count--;
        }
        return count == 0;
    }
};