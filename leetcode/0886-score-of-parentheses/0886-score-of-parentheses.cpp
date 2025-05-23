// class Solution {
// public:
//     int scoreOfParentheses(string s) {
//         int count = 0, depth = 0;
//         for (auto c: s) {
//             if (c == '(') depth++;
//             else 
//                 depth--,
//                 count += pow(2, depth);
//         }
//         return count;
//     }
// };



class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st; st.push(0);
        int score = 0;
        for (auto c: s) {
            if (c == '(') st.push(0);
            else {
                auto v = st.top(); st.pop();
                auto w = st.top(); st.pop();
                st.push(w + max(2 * v, 1));
            }
        }
        return st.top();
    }
};