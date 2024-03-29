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
	ll n, m;
	cin >> n >> m;

	ll holder;
	ll curr = 1;
	ll result = 0;

	for (ll i = 0; i < m; i++) {
		cin>>holder;
		if( holder >= curr ) result += holder - curr;
		else result += n - abs(holder - curr);
		curr = holder;
	}
	
	cout<<result<<endl;
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