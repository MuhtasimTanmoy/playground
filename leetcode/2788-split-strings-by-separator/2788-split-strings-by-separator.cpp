class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        string build = "";
        for (auto word: words) {
            for (auto c: word) 
                if (c != separator) build += c;
                else {
                    if (build.size())
                        res.push_back(build),
                        build.clear();
                }
            if (build.size()) 
                res.push_back(build), 
                build.clear();
        }
        return res;
    }
};