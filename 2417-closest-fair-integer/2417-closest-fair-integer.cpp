class Solution {
public:
    int closestFair(int n) {
        for (;;n++) {
            auto strn = to_string(n);
            auto sz = strn.size();
            if (sz & 1) n = pow(10, sz++); strn = to_string(n);
            auto oddCount = count_if(strn.begin(), 
                                     strn.end(), 
                                     [&](char c) { return (c - '0') & 1; });
            if (oddCount == (strn.size() >> 1)) return stoi(strn);
        }
        throw "exception";
    }
};