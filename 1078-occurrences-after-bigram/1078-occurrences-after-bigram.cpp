class Solution {
public:
    vector<string> findOcurrences(string text, 
                                  string first, 
                                  string second) {
        stringstream ss(text);
        string token, prevToken = "";
        bool available = false;
        vector<string> res;
        while (ss >> token) {
            if (available) {
                res.push_back(token);
                available = false;
            }
            
            if (token == second && prevToken == first) 
                available = true;
            
            prevToken = token;
        }
        return res;
    }
};