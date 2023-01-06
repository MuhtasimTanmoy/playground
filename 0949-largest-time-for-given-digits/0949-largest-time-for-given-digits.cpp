class Solution {
public:
	string largestTimeFromDigits(vector<int>& A) {
		string ans = "";
        sort(A.begin(), A.end());
		do {
			if ((A[0] == 2 && A[1] <= 3 || A[0] < 2) && A[2] <= 5) {
				string temp = to_string(A[0]) + to_string(A[1]) + ":"
					+ to_string(A[2]) + to_string(A[3]);
				if (temp > ans) ans = temp;
			}       
		} while (next_permutation(A.begin(), A.end()));
		return ans;
	}
};