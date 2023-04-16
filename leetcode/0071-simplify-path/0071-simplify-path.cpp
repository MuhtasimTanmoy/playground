class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss,tmp,'/')) 
            if (tmp == "" or tmp == ".") continue;
            else if (tmp != "..") stk.push_back(tmp);
            else if (stk.size()) stk.pop_back();
        for(auto str: stk) res += "/" + str;
        return res.empty() ? "/" : res;
    }
};