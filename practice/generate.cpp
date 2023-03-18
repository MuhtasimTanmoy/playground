#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve() {
	
	int candles, can_regen;
	cin >> candles >> can_regen;
	int hours = 0;

	while( (candles-can_regen) >= 0 ) {
		candles-=can_regen;
		candles+=1;
		hours+=can_regen;
	}

	hours += candles;
	cout<<hours<<endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
	while (no_of_test_cases--)solve();
	return 0;
}
