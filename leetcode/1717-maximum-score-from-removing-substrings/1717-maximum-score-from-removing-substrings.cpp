class Solution {
public:
    int maximumGain(string word, int x, int y, int res = 0) {
        string first = x >= y ? "ab": "ba", second = x < y ? "ab": "ba";
        if (x < y) swap(x, y);
        string now = word;
        
        for (auto term: {make_pair(first, x), make_pair(second, y)}) {
            auto [f, point] = term;
            while (true) {
                string s = "";
                for (auto c: now)
                    if (s.size() 
                        && s.back() == f.front() 
                        && c == f.back())
                            s.pop_back(), res += point;
                    else 
                        s.push_back(c);
                if (now.size() == s.size()) break;
                now = s;
            }
        }      
        return res;
    }
};