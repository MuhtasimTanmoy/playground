class Solution {
    vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                             "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
public:
    string reformatDate(string date, string res = "") {
        stringstream ss(date); string token;
        
        ss >> token;
        token.pop_back(); token.pop_back();
        if (token.size() == 1) token = "0" + token;
        res += token;
        
        ss >> token;
        int idx = find(months.begin(),months.end(), token) - months.begin() + 1;
        res = to_string(idx) + "-" + res;
        if (idx <= 9) res = "0" + res;
        
        ss >> token;
        res = token + "-" + res;
        return res;
    }
};