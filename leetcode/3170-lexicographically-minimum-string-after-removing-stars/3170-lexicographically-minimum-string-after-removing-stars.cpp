class Solution {
public:
    string clearStars(string s) {
        vector<int> l[26] = {};
        auto extract = [&](){
            for (auto &now: l)
                    if (now.size()) {
                        auto remove = now.back();
                        s[remove] = '*';
                        now.pop_back();
                        return;
                    }
        };
        
        for (auto i = 0; i < s.size(); i++) 
            if (s[i] =='*') extract();
            else {
                auto index = s[i] - 'a';
                l[index].push_back(i);
            }
        
        s.erase(remove(begin(s), end(s), '*'), end(s));
        return s;
    }
};