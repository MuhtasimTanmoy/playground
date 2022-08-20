class Solution {
public:
     int countVowelSubstrings(string A) {
        string p = "aeiou";
        set<char> st(p.begin(),p.end());
         
        int N = A.size();
        int res = 0;
         
        for (int i = 0 ; i < N ; i++) {
            set<char> st2;
            for (int j = i; j < N; j++) {
                if (st.count(A[j]) == 0) break;
                st2.insert(A[j]);
                if (st == st2) res++;
            }
        }
        return res; 
    }
};