class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = size(s) - 1;
        while(left < right) {
            s[left] = s[left] ^ s[right];
            s[right] = s[left] ^ s[right];
            s[left] = s[left] ^ s[right];
            left++;
            right--;
        }
    }
};