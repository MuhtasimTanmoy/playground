class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        auto increment = [](int now) -> int {
            auto now_str = to_string(now);
            if (now_str.back() == '9') {
                string start = "";
                for (auto i = 0; i < now_str.size() + 1; i++) 
                    start.push_back('0' + i + 1);
                return stoi(start);
            } 
            for (auto &c: now_str) c++;
            return stoi(now_str);
        };
        
        auto len = to_string(low).size(); string str = "";
        for (auto i = 0; i < len; i++) str.push_back('0' + i + 1);
        
        int start = stoi(str);
        while (start <= high) {
            if (start >= low) res.push_back(start);
            if (start == 123456789) break;
            start = increment(start);
        }
        return res;
    }
};