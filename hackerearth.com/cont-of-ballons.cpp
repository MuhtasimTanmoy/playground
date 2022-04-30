#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const int N = 2e5 + 11;

void solve() {
	int blue, purple;
	cin >> blue >> purple;

	int students;
	cin >> students;

	int count_a = 0, count_b = 0;
	int holder_a, holder_b;

	for (int i = 0; i < students; i++) {
		cin >> holder_a >> holder_b;
		count_a += holder_a;
		count_b += holder_b;
	}

	cout << min(count_a, count_b) * max(blue, purple) + max(count_a, count_b) * min(blue, purple) << endl;
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