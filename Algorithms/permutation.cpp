#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

// https://stackoverflow.com/questions/11483060/stdnext-permutation-implementation-explanation
// https://www.techiedelight.com/std_next_permutation-overview-implementation/

// 1 2 3 4
// 1 2 4 3
// 1 3 2 4
// 1 3 4 2
// 1 4 2 3
// 1 4 3 2
// 2 1 3 4

//  vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(begin(nums), end(nums));
//         vector<vector<int>> result;
//         do {
//             result.push_back(nums);
//         } while (nextPermutation(nums));
//         return result;
//     }

bool nextPermutation(vector<int>& s) {
	
	int i = size(s) - 1;
	if (!i) return false;
	
	while (s[i-1] >= s[i]) if (--i == 0) return false;

	int j = size(s) - 1;
	while (j > i && s[j] <= s[i-1]) j--;

	std::swap(s[i-1], s[j]);
	std::reverse (s.begin() + i, s.end());
	return true;
}

// BUILT IN
void solve() {
	int n;
	cin >> n;
	int li[n];
	for (int i = 0; i < n; i++) 
		cin >> li[i];

	do {
		for (auto x : li) 
			cout << x << " ";
		cout << endl;
	} while (next_permutation(li, li + n));
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
	while (no_of_test_cases--) 
		solve();

	return 0;
}
