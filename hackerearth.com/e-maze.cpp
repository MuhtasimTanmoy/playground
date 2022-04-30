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

	int X = 0, Y = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'L') 
			X--;
		else if (s[i] == 'R')
			X++;
		else if (s[i] == 'U')
			Y++;
		else
			Y--;
	}
	cout << X << " " << Y << endl;
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