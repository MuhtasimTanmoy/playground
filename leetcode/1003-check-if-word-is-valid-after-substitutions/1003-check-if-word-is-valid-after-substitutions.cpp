class Solution {
public:
    /*
    bool isValid(string s) {
        if (s.size() == 0) return true;
        if (s.size() % 3 != 0) return false;
        
        if (s.substr(0, 3) == "abc") return isValid(s.substr(3));
        else if (s.substr(s.size() - 3) == "abc") 
            return isValid(s.substr(0, s.size() - 3));
        
        if (s[0] == 'a' && s.back() == 'c') {
            if (s[1] == 'b') return isValid(s.substr(2, s.size() - 3));
            else if (s[s.size() - 2] == 'b') 
                return isValid(s.substr(1, s.size() - 3));
            else return false;
        } else return false;
    }
    */
    
    bool isValid(string s) {
        vector<char> st;
        for (auto ch : s)
            if (ch == 'c' 
                && st.size() > 1 
                && st.back() == 'b' 
                && st[st.size() - 2] == 'a') st.resize(st.size() - 2);
            else
                st.push_back(ch);
        return st.empty();
    }
};