#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;

void solve() {

	double n, m, a, b;
	cin >> n >> m >> a >> b;

	int count = n / m;
	int res = 0;

	if ( b / m <= a ) {
		res += b * count;
		n -= m * count;
		res += min(a * n, b * n);
	} else res+= a * n;

	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
    int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
    while (no_of_test_cases--) execute(); 
	return 0;
}