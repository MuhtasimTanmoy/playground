class Solution {
public:
    int splitNum(int num, string a = "", string b = "", bool alter = true) {
        auto numstr = to_string(num);
        sort(numstr.begin(), numstr.end());
        for (auto c: numstr) if (alter = !alter) a.push_back(c); else b.push_back(c);
        return stoi(a) + stoi(b);   
    }
};