// class Solution {
// public:
//     string capitalizeTitle(string title) {
//         stringstream ss(title);
//         string word;
//         string res = "";
//         while(ss >> word) {
//             bool first = word.size() >= 3 ? true: false;
//             for (auto &c: word) {
//                 if (first) {
//                     c = toupper(c);
//                     first = false;
//                 } else c = tolower(c);
//             }
//             res+= word;
//             res+= ' ';
//         }
//         res.pop_back();
//         return res;
//     }
// };

class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title); string res = "";
        auto shouldCap = [](string& s) { return s.size() > 2; };
        for (string word; ss >> word;) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (shouldCap(word)) word[0] = toupper(word[0]);
            res += word; res += " ";
        }
        if (res.size()) res.pop_back();
        return res;
    }
};