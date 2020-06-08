#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

ll T, a, b;
void solve() {
	cin >> a >> b;
	ll res = 0;
	if (a > b) swap(a,b);
	while (a*8 <= b) {
		a = a*8;
		res++;
	}
	while (a*4 <= b) {
		a = a*4;
		res++;
	}
	while (a*2 <= b) {
		a = a*2;
		res++;
	}
	if (a == b) cout << res << endl;
	else cout << -1 << endl;
}
 
int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}