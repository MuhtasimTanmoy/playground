#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve() {
	int n;
	cin >> n;
	vector<int> li(n);
	int min_elem = INT32_MAX;

	for (int i = 0; i < n; i++) {
		cin >> li[i];
		min_elem = min(min_elem, li[i]);
	}

	int count = 0;
	for (int i = 0; i < n; i++) 
		if (li[i] == min_elem) count++;

	cout << (count % 2 ? "Lucky" : "Unlucky") << endl;
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
