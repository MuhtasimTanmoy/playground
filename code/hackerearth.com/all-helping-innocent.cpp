#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const int N = 2e5 + 11;

void solve() {
	string s;
	cin >> s;

	unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'Y'};
	vector<int> index = {0, 3, 4, 7};

	if ( vowels.count(s[2]) ) {
		cout << "invalid" << endl;
		return;
	}
	
	for (auto x : index) {
		if ((s[x] + s[x + 1]) % 2) {
			cout << "invalid" << endl;
			return;
		}
	}
	cout << "valid" << endl;
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