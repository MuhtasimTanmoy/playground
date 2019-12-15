//https://codeforces.com/contest/1272//problem/A
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve()
{
	int a, b, c;
	cin >> a >> b >> c;

	int _max = 0;
	_max = max(_max, abs(a - b));
	_max = max(_max, abs(a - c));
	_max = max(_max, abs(c - b));

	_max = max(0, _max - 2);

	cout << 2 * _max << endl;
}


//  while (q--) {
//         cin >> a >> b >> c;
//         long long ans = 1e18;
//         for (int d1 = -1; d1 <= 1; ++d1) {
//             for (int d2 = -1; d2 <= 1; ++d2) {
//                 for (int d3 = -1; d3 <= 1; ++d3) {
//                     int x = a + d1;
//                     int y = b + d2;
//                     int z = c + d3;
//                     ans = min(ans, 1LL * abs(x - y) + abs(y - z) + abs(x - z));
//                 }
//             }
//         }
//         cout << ans << "
"
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
