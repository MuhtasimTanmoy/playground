#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;

void solve() {
	int n;
	cin >> n;
	int li[n];

	ll sum = 0;
	int _max = INT32_MIN;
	int _min = INT32_MAX;

	for (int i = 0; i < n; i++) {
		cin >> li[i];
		sum += li[i];

		_max = max(_max, li[i]);
		_min = min(_min, li[i]);
	}

	sort(li, li + n);

	int total_min = INT32_MAX;

	for (int i = _min; i <= _max; i++)
	{
		auto it = lower_bound(li, li + n, i);
		int segment = it - li;
		cout << endl<< "segment "<<i<< "...." << segment << "...." << endl;
		int res = sum + segment * i - (n - segment) * i;
		cout << endl<< "res "<< "...." << res << "...." << endl;
		total_min = min(total_min, res);
	}

	cout << total_min << endl;
}

// solution is taking median

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
