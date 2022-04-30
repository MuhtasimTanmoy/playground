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
	int no_of_sides;
	cin >> no_of_sides;

	ll max_elem = INT64_MIN;
	ll sum = 0;

	ll holder;

	for (int i = 0; i < no_of_sides; i++) {
		cin >> holder;
		sum += holder;
		max_elem = max(max_elem, holder);
	}

	sum -= max_elem;
	cout << (sum > max_elem ? "YES" : "NO") << endl;
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