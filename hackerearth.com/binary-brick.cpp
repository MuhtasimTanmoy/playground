#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll asum(int n) {
	int sum = n * (n + 1) >> 1;
	return 3 * sum;
}

void solve() {
	int n;
	cin >> n;

	int lo = 0, hi = N;
	int mid;

	while (lo < hi) {
		mid = (lo + hi) >> 1;
		if (asum(mid) <= n && asum(mid + 1) > n) break;
		else if (n < asum(mid)) hi = mid - 1;
		else lo = mid + 1;
	}

	n -= asum(mid);

	if (n - mid - 1 > 0 || n == 0) cout << "Motu" << endl;
	else cout << "Patlu" << endl;
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