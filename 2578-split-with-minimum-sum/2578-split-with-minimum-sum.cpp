class Solution {
public:
    int splitNum(int num) {
        auto numstr = to_string(num);
        sort(numstr.begin(), numstr.end());
        
        string a = "", b = "";
        bool alter = true;
        for (auto c: numstr) if (alter = !alter) a.push_back(c); else b.push_back(c);
        return stoi(a) + stoi(b);   
    }
};