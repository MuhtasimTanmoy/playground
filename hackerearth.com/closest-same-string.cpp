#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const int N = 2e5 + 11;

void solve() {
	int n;
	cin >> n;

	unordered_map<string, int> map;
	string s;
	int _min = INT32_MAX;
	bool found = false;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (map.count(s)) {
			_min = min(_min, (int)(i - map[s]));
			map[s] = i;
			found = true;
		} else map[s] = i;
	}
	cout << ((_min == INT32_MAX) ? -1 : _min) << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 1;
	cin >> no_of_test_cases;
	while (no_of_test_cases--)solve();
	return 0;
}
