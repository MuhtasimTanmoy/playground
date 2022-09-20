class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title);
        string word;
        string res = "";
        while(ss >> word) {
            bool first = word.size() >= 3 ? true: false;
            for (auto &c: word) {
                if (first) {
                    c = toupper(c);
                    first = false;
                } else c = tolower(c);
            }
            res+= word;
            res+= ' ';
        }
        res.pop_back();
        return res;
    }
};