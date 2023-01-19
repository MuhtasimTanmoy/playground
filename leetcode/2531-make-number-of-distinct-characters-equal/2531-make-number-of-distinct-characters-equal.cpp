// class Solution {
// public:
//     bool isItPossible(string word1, string word2) {
//         vector<int> w1map(26, 0), w2map(26, 0);
//         for (auto c: word1) w1map[c - 'a']++;
//         for (auto c: word2) w2map[c - 'a']++;
//         auto w1Count = count_if(w1map.begin(), w1map.end(), [](bool n) { return n; });
//         auto w2Count = count_if(w2map.begin(), w2map.end(), [](bool n) { return n; });
//         if (w1Count == w2Count && word1.size() == word2.size()) return true;
//         if (w1Count < w2Count) swap(w1map, w2map);
//         if (abs(w1Count - w2Count) > 1) return false;
//         auto doesShortOneHasSpace = count_if(w2map.begin(), 
//                                              w2map.end(), 
//                                              [](auto n) { return n > 1; });
//         if (!doesShortOneHasSpace) return false;
//         for (int i = 0; i < w2map.size(); i++) 
//             if (!w2map[i] && w1map[i] > 1) 
//                 return true;
//         return false;
//     }
// };


class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int ct1[26] = {};
        int ct2[26] = {};
        for (char c: word1) ct1[c-'a']++;
        for (char c: word2) ct2[c-'a']++;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (ct1[i] && ct2[j]) {
                    ct1[i]--, ct1[j]++;
                    ct2[i]++, ct2[j]--;
                    
                    if (count(begin(ct1), end(ct1), 0) 
                        == count(begin(ct2), end(ct2), 0))
                        return true;
                   
                    ct1[i]++, ct1[j]--;
                    ct2[i]--, ct2[j]++;
                }
            }
        }
        return false;
    }
};