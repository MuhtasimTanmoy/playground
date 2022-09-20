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
	int li[n];
	deque<int> _deque;

	for (int i = 0; i < n; i++) cin >> li[i];
	sort(li, li + n);

	for (int i = 0; i < n; i++) {
		if (!_deque.empty() && _deque.front() < li[i])
			_deque.pop_front();

		_deque.push_back(li[i]);
	}

	int total_remaining = 0;
	while (!_deque.empty()) {
		total_remaining += _deque.front();
		_deque.pop_front();
	}

	cout << total_remaining << endl;
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
