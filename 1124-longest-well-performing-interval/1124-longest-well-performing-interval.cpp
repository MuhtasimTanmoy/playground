// class Solution {
//     const int LIMIT = 8;
// public:
//     int longestWPI(vector<int>& hours) {
//         int tiringDays = 0;
//         for (auto hour: hours) if (hour > LIMIT) tiringDays++;
        
//         unordered_map<string, int> dp;
//         auto key = [](int left, int right, int tiring, int nonTiring) {
//             stringstream ss;
//             ss << left <<"-" << right <<"-"<< tiring<<"-"<< nonTiring;
//             return ss.str();
//         };
        
//         function<int(int, int, int, int)> calc 
//             = [&](int left, int right, int tiring, int nonTiring) -> int {
//             if (left > right) return 0;
            
//             auto k = key(left, right, tiring, nonTiring);
//             if (dp.count(k)) return dp[k];
            
//             if (nonTiring >= tiring)
//                 if (hours[left] <= LIMIT)
//                     return dp[k] = calc(left + 1, right, tiring, nonTiring - 1);
//                 else if (hours[right] <= LIMIT)
//                     return dp[k] = calc(left, right - 1, tiring, nonTiring - 1);
//                 else {
//                     int leftTaken = calc(left, right - 1, tiring - 1, nonTiring);
//                     int rightTaken = calc(left + 1, right, tiring - 1, nonTiring);
//                     return dp[k] = max(leftTaken, rightTaken);
//                 }
//             else return right - left + 1;
//         };
//         return calc(0, hours.size() - 1, tiringDays, hours.size() - tiringDays);
//     }
// };

class Solution {
public:
	int longestWPI(vector<int>& hours) {
        int n = hours.size(), ans = 0, ct = 0;
		unordered_map<int, int> m;
		for (int i = 0; i < n; ++i) {
			if (hours[i] > 8) ct++; else ct--;
			if (ct > 0) ans = max(ans, i + 1);
			else {
                cout<<ct<<endl;
				if (!m.count(ct)) m[ct] = i;
				if (m.count(ct - 1)) ans = max(ans, i - m[ct - 1]);
			}
		}
		return ans;
	}
};