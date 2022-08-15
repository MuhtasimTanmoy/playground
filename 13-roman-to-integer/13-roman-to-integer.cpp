class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {
                                        {'I',1}, 
                                        {'V',5}, 
                                        {'X',10}, 
                                        {'L',50},
                                        {'C',100}, 
                                        {'D',500}, 
                                        {'M',1000}
                                       };
        int idx = 0, sum = 0;
        while (idx < s.size()) {
            auto item = s[idx];
            sum += map[item];
            if (idx && map[item] > map[s[idx-1]]) sum -= map[s[idx-1]] * 2;
            ++idx;
        }
        return sum;
    }
};