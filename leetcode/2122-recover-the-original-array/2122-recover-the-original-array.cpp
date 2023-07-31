class Solution {
public:
//     vector<int> recoverArray(vector<int>& n) {
//         int len = n.size();
        
//         unordered_map<int, int> um;
//         for (int i = 0; i < len - 1; i++)
//             for (int j = i + 1; j < len; j++)
//                 um[abs(n[i] - n[j])]++;
        
//         for (auto [key, value]: um) 
//             cout<<key<<" "<<value<<endl;
        
//         int k = 0, count = 0;
//         for (auto [key, value]: um) 
//             if (value > count)
//                 k = key,
//                 count = value;
        
        
//         vector<int> res;
//         multiset<int> m(n.begin(), n.end());
//         while (m.size()) {
//             auto one = *m.begin(), two = one + k;
//             if (m.count(one) && m.count(two)) {
//                 m.erase(m.find(one));
//                 m.erase(m.find(two));
//                 res.push_back(one + k / 2);
//             } else break;
//         }
//         return res;
//     }
    
    vector<int> recoverArray(vector<int>& nums) {
        multiset<int> s(begin(nums), end(nums));
        int start = *begin(s);
        for (auto it = next(begin(s)); it != end(s); ++it) {
            int k = (*it - start) / 2;
            if (k > 0 && start + 2 * k == *it) {
                vector<int> res;
                auto ss = s;
                while(ss.size()) {
                    auto it_h = ss.find(*begin(ss) + 2 * k);
                    if (it_h == end(ss))
                        break;
                    res.push_back(*begin(ss) + k);
                    ss.erase(begin(ss));
                    ss.erase(it_h);
                }
                
                if (ss.empty())
                    return res;
            }
        }
        return {};
    }
};