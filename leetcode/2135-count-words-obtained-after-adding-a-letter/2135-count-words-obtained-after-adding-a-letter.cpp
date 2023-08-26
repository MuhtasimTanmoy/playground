class Solution {
public:
//     int wordCount(vector<string>& s, vector<string>& t) {
        
//         vector<int> target_vectors;
//         for (auto w: t) {
//             int l = 0;
//             for (auto c: w) l |= 1 << (c - 'a');
//             target_vectors.push_back(l);
//         }
        
//         vector<int> start_vectors;
//         for (auto w: s) {
//             int l = 0;
//             for (auto c: w) l |= 1 << (c - 'a');
//             start_vectors.push_back(l);
//         }
        
//         int res = 0;
//         for (auto tv: target_vectors) {
//             for (auto sv: start_vectors) {
//                 bool found = true; int diff = 0;
//                 for (int i = 0; i < 26 && found; i++) {
//                     auto t_in = tv && (1 << i);
//                     auto s_in = sv && (1 << i);
//                     if (!t_in && s_in) found = false;
//                     if (t_in )
//                 }
//                     if (tv[i]) {
//                         if (sv[i] == 0 && tv[i] == 1) diff++;
//                         if (sv[i] && tv[i] != sv[i]) found = false;
//                     } else if (sv[i]) found = false;
    
//                 if (found && diff == 1) {
//                     res++;
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
    
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        auto get_mask = [](string &w){
            return accumulate(begin(w), end(w), 0, 
                              [](int mask, char ch){ 
                                  return mask + (1 << (ch - 'a')); });  
        };
        
        unordered_set<int> s;
        for (auto &w : startWords) s.insert(get_mask(w));
        
        int res = 0;
        for (auto &w : targetWords) {
            int mask = get_mask(w);
            cout<<mask<<endl;
            res += any_of(begin(w), end(w), [&](char ch) { 
                return s.count(mask - (1 << (ch - 'a'))); 
            });
        }
        return res;
    }
};