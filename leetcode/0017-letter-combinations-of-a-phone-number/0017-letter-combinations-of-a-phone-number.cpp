class Solution {
public:
    vector<string> letterCombinations(string d) {
        unordered_map<char, vector<char>> mapper;
        mapper['2'] = {'a', 'b', 'c'};
        mapper['3'] = {'d', 'e', 'f'};
        mapper['4'] = {'g', 'h', 'i'};
        mapper['5'] = {'j', 'k', 'l'};
        mapper['6'] = {'m', 'n', 'o'};
        mapper['7'] = {'p', 'q', 'r', 's'};
        mapper['8'] = {'t', 'u', 'v'};
        mapper['9'] = {'w', 'x', 'y', 'z'};
        
        vector<string> res;
        string builder;
        function<void(int, int)> go = [&](auto i, auto s) {
            if (builder.size() == d.size() && d.size()) {
                res.push_back(builder);
                return;
            }
            for (int j = i; j < d.size(); j++) {
                auto list = mapper[d[j]];
                for (int k = s; k < list.size(); k++)
                    builder.push_back(list[k]),
                    go(j + 1, 0),
                    builder.pop_back();  
            }
        };
        go(0, 0);
        return res;
    }
};