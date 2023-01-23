class Solution {
public:
    string reformatDate(string date, string res = "") {
        auto months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        stringstream ss(date); string token;
        int index = 0;
        while (ss >> token) {
            switch (index) {
                case 0:
                    token.pop_back(); token.pop_back();
                    if (token.size() == 1) token = "0" + token;
                    res += token; break;
                case 1: {
                    int idx = find(months.begin(),months.end(), token) - months.begin() + 1;
                    res = to_string(idx) + "-" + res;
                    if (idx <= 9) res = "0" + res;
                    break;
                }
                case 2:
                    res = token + "-" + res;
            }
            index++;
        }
        return res;
    }
};