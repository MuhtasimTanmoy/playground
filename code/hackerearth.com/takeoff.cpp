#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;
bool slots[N] = {true};

void solve() {
	int n, p, q, r;
	cin >> n >> p >> q >> r;
	int traverse = p;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (i % p == 0 && i % q && i % r) count++;
		else if (i % q == 0 && i % p && i % r) count++;
		else if (i % r == 0 && i % q && i % p) count++;
	}
	cout << count << endl;
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