/*siddharth goyal*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define REP(i, n) for (i = 1; i <= n; i++)
#define FOR(i, a, b) for (i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define vl vector<LL>
#define itr ::iterator it
#define lb lower_bound
#define ub upper_bound
#define LL long long
#define ULL unsigned long long
#define ret return
LL n, i, j, ans = 0;
LL a[10000000];
void f(LL x) {
	ans += (x * (x - 1)) / 2;
}

int main() { // Read the constraints,highlights,Time Limit,Test Cases
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	REP(i, n) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);

	for (i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;

	LL x = 0;
	for (i = 1; i <= n; i++) {
		LL k = 0, l = 0;
		for (j = i + 1; j <= n; j++) {
			k = max(k, a[j] - a[j - 1]);
			if (k == 1)
				l++;
			if (k > 1)
				break;
		}
		if (l)
			f(j - i);
		i = j - 1;
	}
	cout << ans << endl;
}