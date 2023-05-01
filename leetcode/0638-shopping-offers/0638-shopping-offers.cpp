class Solution {
    unordered_map<string, int> map;
    int dot(vector<int> &needs, vector<int> price){
        int sum = 0;
        for(int i = 0; i < needs.size(); i++)
            sum += needs[i] * price[i];
        return sum;
    }
    
    int shopping(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        string key;
        for (int n: needs) key += to_string(n);
        if (map.count(key)) return map[key];
        int j = 0, res = dot(needs, price);
        for (auto s: special) {
            vector<int> clone = needs;
            for (j = 0; j < needs.size(); j++) {
                int diff = clone[j] - s[j];
                if (diff < 0) break;
                clone[j] = diff;
            }
            if (j == needs.size())
                res = min(res, s[j] + shopping(price, special, clone));
        }
        return map[key] = res;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return shopping(price, special, needs);
    }
};