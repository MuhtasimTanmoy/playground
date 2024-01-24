class Solution {
public:
    long long maximumSubsequenceCount(string s, string pat) {
        int count_first = count(s.begin(), s.end(), pat.front()),
            count_second = count(s.begin(), s.end(), pat.back());
        if (count_first < count_second) s = pat.front() + s; else s += pat.back();
        
        long long res = 0;
        for (auto i = 0, f_count = 0; i < s.size(); i++) {
            if (s[i] == pat.back()) res += f_count;
            f_count += s[i] == pat.front();
        }
        return res;
    }
};