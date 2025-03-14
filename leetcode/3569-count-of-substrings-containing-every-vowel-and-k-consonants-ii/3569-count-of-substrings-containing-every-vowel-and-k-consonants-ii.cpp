class Solution {
public:
    // long long countOfSubstrings(string W, int k) {
    //     unordered_map<char, int> vowels;
    //     unordered_set<char> bag {'a', 'e', 'i', 'o', 'u'};
    //     int target = k + 5, res = 0;
    //     for(auto i = 0, l = 0, cons = 0; i < W.size(); i++) {
    //         if (bag.count(W[i])) vowels[W[i]]++; else cons++;
    //         while (cons > k) {
    //             if (bag.count(W[l])) {  if (--vowels[W[l]] == 0) vowels.erase(W[l]); }
    //             else cons--;
    //             l++;
    //         }
    //         if (vowels.size() == 5 && cons == k) res++;
    //     }
    //     return res;
    // }

    string vw = "aeiou";
    long long countAtLeastK(string &w, int k) {
        long long res = 0, j = 0, cnt[6] = {}, unique = 0;
        for (int i = 0; i < w.size(); ++i) {
            int p = vw.find(w[i]) + 1;
            unique += ++cnt[p] == 1 && p;
            while (unique == 5 && cnt[0] >= k) {
                res += w.size() - i;
                int p = vw.find(w[j++]) + 1;
                unique -= --cnt[p] == 0 && p;                
            }
        }
        return res;
    }
    long long countOfSubstrings(string w, int k) {
        return countAtLeastK(w, k) - countAtLeastK(w, k + 1);
    }
};