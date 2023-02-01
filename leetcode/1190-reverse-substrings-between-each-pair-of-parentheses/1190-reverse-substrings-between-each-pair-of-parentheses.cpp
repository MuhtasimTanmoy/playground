// class Solution {
// public:
//     string reverseParentheses(string s, string res = "", bool isQ = true) {
//         stack<char> st; queue<char> q;
//         auto push = [&](char c) {  
//             if (isQ) {
//                 cout<<"In q: "<<c<<endl;
//                 q.push(c);
//             } else {
//                 cout<<"In st: "<<c<<endl;
//                 st.push(c); 
//             }
//         };
        
//         for (auto c: s) 
//             if (c == '(' || c == ')') push('|'), isQ = !isQ; 
//             else push(c);
                
//         while (q.size() || st.size()) {
//             while (st.size() && st.top() != '|') res += st.top(), st.pop();
//             if (st.size()) st.pop();
            
//             while (q.size() && q.front() != '|') res += q.front(), q.pop();
//             if (q.size()) q.pop();
//         }
//         return res;
//     }
// };


class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (char c : s) 
            if (c == ')') {
                queue<char> p;
                while (!st.empty() && st.top() != '(') {
                    p.push(st.top());
                    st.pop();
                }
                if (st.size()) st.pop();
                while (p.size()) {
                    st.push(p.front());
                    p.pop();
                }
            } else st.push(c);
        
        string result;
        while (st.size()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};