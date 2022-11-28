class Solution {
    string format(string& email) {
        auto firstPart = email.substr(0, email.find('@'));
        auto firstPartWithDot = firstPart.substr(0, email.find('+'));
        string sanitized = "";
        for (auto c: firstPartWithDot) {
            if (c == '.') continue;
            sanitized += c;
        }
        auto lastPart = email.substr(email.find('@'));
        return sanitized + lastPart;
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> bag;
        for (auto email: emails) {
            auto formatted = format(email);
            bag.insert(formatted);
        }
        return bag.size();
    }
};