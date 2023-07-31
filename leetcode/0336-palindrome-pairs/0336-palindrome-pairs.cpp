// class Solution {
// public:
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         auto is_palindrome = [&](string a) {
//             int l = 0, r = a.size() - 1;
//             while (l < r) {
//                 if (a[l] != a[r]) return false;
//                 l++, r--;
//             }
//             return true;
//         };
        
//         vector<vector<int>> res;
//         for (int i = 0; i < words.size() - 1; i++) {
//             auto l = words[i];
//             for (int j = i + 1; j < words.size(); j++) {
//                 auto r = words[j];
//                 if (is_palindrome(l + r)) res.push_back({i, j});
//                 if (is_palindrome(r + l)) res.push_back({j, i});
//             }
//         }
//         return res;  
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         auto is_palin = [&](string a, int l, int r) {
//             while (l < r) if (a[l++] != a[r--]) return false;
//             return true;
//         };
//         vector<vector<int>> result;
//         unordered_map<string, int> d;
//         for (int i = 0; i < words.size(); i++) d[words[i]] = i;
//         for (int i = 0; i < words.size(); i++) 
//             for (int j = 0; j <= words[i].length(); j++) {
//                 if (is_palin(words[i], j, words[i].size() - 1)) {
//                     auto suff = words[i].substr(0, j);
//                     reverse(suff.begin(), suff.end());
//                     if (d.count(suff) && i != d[suff]) 
//                         result.push_back({i, d[suff]});
//                 }
//                 if (j > 0 && is_palin(words[i], 0, j - 1)) {
//                     auto pre = words[i].substr(j);
//                     reverse(pre.begin(), pre.end());
//                     if (d.count(pre) && d[pre] != i) 
//                         result.push_back({d[pre], i});
//                 }
//             }
//         return result;
//     }
// };


struct TrieNode {
    TrieNode *next[26] = {};
    int index = -1;
    vector<int> palindromeIndexes;
};

class Solution {
    TrieNode root;
    void add(string &s, int i) {
        auto node = &root;
        for (int j = s.size() - 1; j >= 0; --j) {
            if (isPalindrome(s, 0, j)) node->palindromeIndexes.push_back(i);
            int c = s[j] - 'a';
            if (!node->next[c]) node->next[c] = new TrieNode();
            node = node->next[c];
        }
        node->index = i;
        node->palindromeIndexes.push_back(i);
    }
    
    bool isPalindrome(string &s, int i, int j) {
        while (i < j && s[i] == s[j]) ++i, --j;
        return i >= j;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& A) {
        int N = A.size();
        for (int i = 0; i < N; ++i) add(A[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < N; ++i) {
            auto s = A[i];
            auto node = &root;
            for (int j = 0; j < s.size() && node; ++j) {
                if (node->index != -1 && node->index != i && isPalindrome(s, j, s.size() - 1))
                    ans.push_back({ i, node->index }); 
                node = node->next[s[j] - 'a'];
            }
            if (!node) continue;
            for (int j : node->palindromeIndexes) 
                if (i != j) ans.push_back({ i, j });
        }
        return ans;
    }
};