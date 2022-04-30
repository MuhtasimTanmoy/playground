#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 7;
int _map[N];

void solve() {
	int n;
	cin >> n;

	int li[n] = {0};
	for (int i = 0; i < n; i++) cin >> li[i];

	int _xor = li[0];
	for (int i = 1; i < n; i++) _xor = li[i] ^ _xor;

	int last_set_bit = _xor & ~(_xor - 1);
	
	int x = 0;
	int y = 0;

	for (int i = 0; i < n; i++) {
		if (li[i] & last_set_bit) x ^= li[i];
		else y ^= li[i];
	}

	if (x < y) swap(x, y);
	cout << y << " " << x << endl;
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