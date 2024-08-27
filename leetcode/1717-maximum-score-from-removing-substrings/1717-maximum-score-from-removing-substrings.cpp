class Solution {
public:
    int maximumGain(string w, int x, int y, int res = 0) {
//         string firstlookfor = "ab", then = "ba", builder = "";
//         if (y > x) swap(firstlookfor, then), swap(x, y);
        
//         int res = 0;
//         for (auto c: s) 
//             if (builder.size()) {
//                 if (builder.back() == firstlookfor.front() && c == firstlookfor.back())
//                     builder.pop_back(), res += x;
//                 else builder.push_back(c);
//             } else builder.push_back(c);
        
//          for (auto c: builder) 
//             if (builder.size()) {
//                 if (builder.back() == then.front() && c == then.back())
//                     builder.pop_back(), res += y;
//                 else builder.push_back(c);
//             } else builder.push_back(c);
//         return res;
        
        string first = "ab", second = "ba";
        if (x < y) swap(x, y), swap(first, second);
        string now = w, s = "";
        for (auto term: {make_pair(first, x), make_pair(second, y)}) {
            auto [f, point] = term;
            for (auto c: now)
                if (s.size() && s.back() == f.front()  && c == f.back())
                        s.pop_back(), res += point;
                else
                    s.push_back(c);
            now = s; s = "";
        }   
        return res;
    }
};