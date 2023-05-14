/*
class Solution {
public:
    int uniqueLetterString(string s) {
        int res = 0;
        for (auto i = 0; i < s.size(); i++) {
            vector<int> counter(26);
            int count = 0;
            for (auto j = i; j < s.size(); j++) {
                auto idx = s[j] - 'A';
                counter[idx]++;
                if (counter[idx] == 1) count++;
                if (counter[idx] == 2) count--;
                res += count;
            }
        }
        return res;
    }
};
*/

class Solution {
    const int M = 1000000007;
public:
    int uniqueLetterString(string s) {
		int n = s.length();
		vector<long long> L(n, -1), R(n, -1);
		vector<long long> lastL(26, -1), lastR(26, n);
        
		for (int i = 0; i < n; i++)
			L[i] = i - lastL[s[i] - 'A'],
			lastL[s[i] - 'A'] = i;
		
		for (int i = n-1; i >= 0; i--)
			R[i] = lastR[s[i] - 'A'] - i,
			lastR[s[i] - 'A'] = i;
		
		int ans = 0; 
		for (int i = 0; i < n; i++)
			ans = (ans + (L[i] * R[i]) % M) % M;
		return ans;
    }
};