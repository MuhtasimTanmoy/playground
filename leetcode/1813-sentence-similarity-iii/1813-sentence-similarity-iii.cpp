class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {            
        // if (l.size() == r.size()) return l == r;
        // if (l.size() > r.size()) swap(l, r);
        // auto has_space = l.find(' ') != string::npos || r.find(' ') != string::npos;
        // deque<char> ld(l.begin(), l.end()), rd(r.begin(), r.end());
        // while (ld.size() && rd.size()) {
        //     bool removed = false;
        //     if (ld.front() == rd.front()) 
        //         ld.pop_front(), rd.pop_front(), removed = true;
        //     if (ld.size() && ld.back() == rd.back()) 
        //         ld.pop_back(), rd.pop_back(), removed = true;
        //     if (!removed) break;
        // }
        // return has_space && (ld.empty() || rd.empty());
        
        string temp = "";
        deque<string>a, b;
        for(char c: s1) if (c == ' ') a.push_back(temp),temp = ""; else temp += c;
        a.push_back(temp), temp = "";
        for(char c: s2) if (c == ' ') b.push_back(temp),temp = ""; else temp += c;
        b.push_back(temp), temp = "";
        
        while (a.size() && b.size() && (a.front() == b.front())) 
            a.pop_front(),b.pop_front();

		while (a.size() && b.size() && (a.back() == b.back()))
            a.pop_back(),b.pop_back();
        
		if (a.empty() || b.empty()) return true;
        return false;
    }
};