// class Solution {
// public:
//     string breakPalindrome(string palindrome) {
//         int left = 0, right = palindrome.size() - 1;
//         while (left < right) {
//             if (palindrome[left] - 'a') {
//                 palindrome[left] = 'a';
//                 return palindrome;
//             } else if (right - left <= 2) {
//                 palindrome[right] = 'b';
//                 return palindrome;
//             }
//             left++; right--;
//         }
//         return "";
//     }
// };


class Solution {
public:
    string breakPalindrome(string palindrome) {
        int length = palindrome.size();
        if (length == 1) return "";
        for (int i = 0; i < length / 2; i++)
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        palindrome[length - 1] = 'b';
        return palindrome;
    }
};