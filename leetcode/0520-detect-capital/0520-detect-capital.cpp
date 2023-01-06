// class Solution {
// public:
//     bool detectCapitalUse(string word) {
//         bool hasUpper = isupper(word[0]);
//         for (int i = 1; i < word.size(); i++) {
//             if (islower(word[i-1]) && isupper(word[i])) return false;
//             if (isupper(word[i])) hasUpper = true;
//         }
//         if (islower(word.back()) && word.size() > 2 && hasUpper) return false;
//         return true;
//     }
// };


class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i=1;i<word.size();i++)
            if ( (isupper(word[1]) != isupper(word[i]))  
                ||  (islower(word[0]) && isupper(word[i])) )
                return false;
        
        return true;
    }
};