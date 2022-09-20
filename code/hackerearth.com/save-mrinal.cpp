#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int t;
	cin >> t;
	for (int id = 0; id < t; ++id) {
		int i, j;
		cin >> i >> j;
		set<int> s;
		for (int x = i; x <= j; x++) s.insert(a[x]);
		cout << s.size() << '\n';
		s.clear();
	}
	return 0;
}