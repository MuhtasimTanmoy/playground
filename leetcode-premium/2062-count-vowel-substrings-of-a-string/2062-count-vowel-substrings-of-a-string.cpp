// class Solution {
// public:
//      int countVowelSubstrings(string A) {
//         string p = "aeiou";
//         set<char> st(p.begin(),p.end());
//         int N = A.size();
//         int res = 0;
//         for (int i = 0 ; i < N ; i++) {
//             set<char> st2;
//             for (int j = i; j < N; j++) {
//                 if (st.count(A[j]) == 0) break;
//                 st2.insert(A[j]);
//                 if (st == st2) res++;
//             }
//         }
//         return res; 
//     }
// };

class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> m;
        int ans = 0;
        for (int i = -1, j = 0; j < size(word); j++) {
            auto curr = word[j];
            if (!vowel.count(curr)) {
                m.clear();
                i = j;
                continue;
            }
            m[curr] = j;
            if (size(m) == 5) {
                int k = j;
                for (auto& [c, idx]: m) k = min(k, idx);
                ans += k - i;
            }
        }
        return ans;
    }
};