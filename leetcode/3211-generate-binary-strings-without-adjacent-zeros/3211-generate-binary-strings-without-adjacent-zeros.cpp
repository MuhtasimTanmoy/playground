class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        string builder = "";
        function<void(int)> go = [&](auto left) {
            if (!left) res.push_back(builder);
            else {                
                builder += '1',
                go(left - 1),
                builder.pop_back();
                
                auto is_one_last = builder.empty() || builder.back() == '1';
                
                if (is_one_last) 
                    builder += '0',
                    go(left - 1),
                    builder.pop_back();
            }
        };
        go(n);
        return res;
    }
};