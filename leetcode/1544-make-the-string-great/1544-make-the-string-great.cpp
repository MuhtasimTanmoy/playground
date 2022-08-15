class Solution {
public:
    string makeGood(string s) {
        int dif='a'-'A';
        stack<char> st;
        st.push(s[0]);
        for(int i=1; i < s.length(); i++) {
            if(!st.empty() and abs(st.top() - s[i]) == dif)  st.pop();
            else  st.push(s[i]);
        }
        string ans="";
        while (!st.empty()) {
          ans += st.top();
          st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};