class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        auto solve = [](int& i) {
            auto str = bitset<64>(i).to_string();
            for (int i = str.size() - 1; i > 0; i--) 
                if (str[i - 1] == '0' && str[i] == '1') {
                     str[i] = '0';
                     return stoi(str, nullptr, 2);
                }
           throw "error";
        };
        
        for (auto num: nums) 
            if (num & 1) res.push_back( solve(num) ); else res.push_back(-1);
        return res;
    }
};