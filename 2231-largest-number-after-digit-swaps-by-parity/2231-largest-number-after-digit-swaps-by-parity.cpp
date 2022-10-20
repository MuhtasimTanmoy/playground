class Solution {
public:
    int largestInteger(int num) {
        vector<int> li(10, 0);
        vector<int> even, odd;
        auto numStr = to_string(num);
        for (auto c: numStr) li[c - '0']++;
        
        int curr = 0;
        for (auto i: li) {
            while(i--) 
                if (curr & 1) odd.push_back(curr);
                else even.push_back(curr);
            curr++;
        }
        
        int res = 0;
        for (auto c: numStr) {
            auto isOdd = (c - '0') & 1;
            int add = 0;
            if (isOdd) {
                add = odd.back();
                odd.pop_back();
            } else {
                add = even.back();
                even.pop_back();
            }
            res = res * 10 + add;
        }
        return res;
    }
};